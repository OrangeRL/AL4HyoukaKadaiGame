#include "Player.h"

class Map {
public:
	int GetObjectCount();
	int GetObjectID(int x , int y);
	WorldTransform GetWorldTransform(int ObjectNum);
};

class Goal {
public:
	WorldTransform GetWorldTransform();
};

class Enemy {
public:
	WorldTransform GetWorldTransform();
};

Player::Player() {

}

Player::~Player() {
	delete gameObject;
}

void Player::Initialize(ViewProjection* viewProjection , XMMATRIX* matProjection) {

	gameObject = new GameObject3D();
	gameObject->PreLoadModel("Resources/star/star.obj");
	gameObject->PreLoadTexture(L"Resources/star/star.jpg");
	gameObject->SetViewProjection(viewProjection);
	gameObject->SetMatProjection(matProjection);
	gameObject->Initialize();
	//gameObject->worldTransform.rotation.x = 1.8;
	Reset();

}

void Player::Update() {

	Rotate();
	Move();
	

	if (isDead == false) {
		gameObject->Update();
	}
}

void Player::Draw() {
	if (isDead == false) {
		gameObject->Draw();
	}
}

void Player::Reset() {
	gameObject->worldTransform.translation = {-40 , 0 , -40};
	moveSpeed = 0;
	isDead = false;
}

void Player::Rotate() {

	const float rotationSpeed = MathFunc::Utility::Deg2Rad(6.0f);

	Vector3 rotation = {0 , 0 , 0};

	rotation.y = rotationSpeed;
	
	gameObject->worldTransform.rotation += rotation;

}

void Player::Move() {



	moveSpeed = 0.5f;
	move = { 0,0,0 };

	
	//if (input.PushKey(DIK_W))
	//{
	//	move = { 0,0,moveSpeed };
	//}

	//else if (input.PushKey(DIK_S))
	//{
	//	move = { 0,0,-moveSpeed };
	//}
	//else if (input.PushKey(DIK_A))
	//{
	//	move = { -moveSpeed,0,0 };
	//}
	//else if (input.PushKey(DIK_D))
	//{
	//	move = { moveSpeed,0,0 };
	//}
	if (input.PushKey(DIK_W) || input.PushKey(DIK_S) || input.PushKey(DIK_D) || input.PushKey(DIK_A))
	{

		// 移動後の座標を計算
		if (input.PushKey(DIK_W)) { move = { 0,0,moveSpeed }; }
		else if (input.PushKey(DIK_S)) { move = { 0,0,-moveSpeed }; }
		if (input.PushKey(DIK_D)) { move = { moveSpeed,0,0 }; }
		else if (input.PushKey(DIK_A)) { move = { -moveSpeed,0,0 }; }

		if (input.PushKey(DIK_D) && input.PushKey(DIK_W)) { move = { moveSpeed,0,moveSpeed }; }
		else if (input.PushKey(DIK_D) && input.PushKey(DIK_S)) { move = { moveSpeed,0,-moveSpeed }; }

		if (input.PushKey(DIK_A) && input.PushKey(DIK_W)) { move = { -moveSpeed,0,moveSpeed }; }
		if (input.PushKey(DIK_A) && input.PushKey(DIK_S)) { move = { -moveSpeed,0,-moveSpeed }; }
	}
	if(jumpFlag==0){
	if (input.PushKey(DIK_SPACE))
	{
		jumpFlag = 1;
	}
	}
	//gravity
	if (jumpFlag == 1) {
		gameObject->worldTransform.translation.y += 1;
	}
	if (jumpFlag == 1) {
		moveSpeed = g * (timer / 50);

		gameObject->worldTransform.translation.y -= moveSpeed;

		timer++;
		if (gameObject->worldTransform.translation.y < 0) {
			timer = 0;
			gameObject->worldTransform.translation.y = 0;
			
			jumpFlag = 0;
		}
	}


	gameObject->worldTransform.translation += move;

	
	if (isHitMap == false) {
		velocity = {
			moveSpeed * cosf(angle.y) ,
			0 ,
			moveSpeed * -sinf(angle.y)
		};
	}
	else {
		velocity = {
			moveSpeed * -cosf(-angle.y) ,
			0 ,
			moveSpeed * -sinf(-angle.y)
		};
	}

	//gameObject->worldTransform.translation += velocity;

}


//アクセッサ
void Player::SetMap(Map* map) {
	this->map = map;
}

void Player::SetGoal(Goal* goal) {
	this->goal = goal;
}

int Player::GetIsGoal() {
	return isGoal;
}

void Player::SetIsGoal(int flag) {
	isGoal = flag;
}

void Player::SetEnemy(Enemy* enemy) {
	this->enemy = enemy;
}

int Player::GetIsEnemy() {
	return isGoal;
}

void Player::SetIsEnemy(int flag) {
	isEnemy = flag;
}

int Player::GetIsDead() {
	return isDead;
}

Vector3 Player::GetAngle() {
	return angle;
}

WorldTransform Player::GetWorldTransform() {
	return gameObject->worldTransform;
}