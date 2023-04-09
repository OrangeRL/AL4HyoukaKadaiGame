#pragma once
#include "GameObject3D.h"
#include "Input.h"
#include "MathFunc.h"
#include "DustParticleManager.h"

class Map;
class Goal;
class Enemy;

class Player {
public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	~Player();

	void Initialize(ViewProjection* viewProjection, XMMATRIX* matProjection);

	void Update(ViewProjection* viewProjection, XMMATRIX* matProjection);

	void Draw();

	void Reset();

	//�A�N�Z�b�T
	void SetMap(Map* map);
	void SetGoal(Goal* goal);
	void SetEnemy(Enemy* enemy);

	int GetIsGoal();
	void SetIsGoal(int flag);

	int GetIsEnemy();
	void SetIsEnemy(int flag);

	int GetIsDead();

	Vector3 GetAngle();
	ViewProjection* GetViewProjection() { return viewProjection; }
	WorldTransform GetWorldTransform();
Vector3 centerVec = { 0,0,0 };
Vector3 angle = {};
	//�����o�֐�
private:
	void Rotate();
	void Move();
	void Collision();

	//�����o�ϐ�
private:
	//�L�[����
	Input& input = Input::GetInstance();

	//�Q�[���I�u�W�F�N�g
	GameObject3D* gameObject = nullptr;

	ViewProjection* viewProjection;

	Vector3 velocity = {};
	//���ʃx�N�g��
	
	const float accelaration = 0.0025f;

	float moveSpeed = 0;

	const float maxSpeed = 0.5;
	float ct = 0;
	const float g = 3;
	float timer = 0;
	int jumpFlag = 0;
	Vector3 target;

	int isDead = false;

	int isHitMap = false;

	int isGoal = false;
	int isEnemy = false;

	Map* map = nullptr;
	Goal* goal = nullptr;
	Enemy* enemy = nullptr;
	DustParticleManager pManager;
	
	Vector3 move = {};
};

