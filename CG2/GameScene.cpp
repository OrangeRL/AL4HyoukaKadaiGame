#include "GameScene.h"
#include <cassert>

GameScene::GameScene() {

}

GameScene::~GameScene() {
	delete player;
	delete map;
	delete goal;
	delete particle;
	
	delete tutorialFloor;
	delete stageFloor;

	soundManager_.SoundUnload(soundData1);
	soundManager_.SoundUnload(selectSound);
}

void GameScene::Initialize(WinApp* winApp) {

	//透視投影変換行列の計算
	matProjection_ = XMMatrixPerspectiveFovLH(
		XMConvertToRadians(45.0) ,
		(float)winApp->window_width / winApp->window_height ,
		0.1f , 1000.0f
	);

	viewProjection_.Initialize();
	viewProjection_.eye = {0 , 100 , -100};


	//XAudioエンジンのインスタンスを生成
	soundManager_.Initialize();

	map = new Map();
	map->Initialize(&viewProjection_ , &matProjection_);

	goal = new Goal;
	goal->Initialize(&viewProjection_ , &matProjection_);

	enemy = new Enemy;
	enemy->Initialize(&viewProjection_, &matProjection_);

	player = new Player();
	player->Initialize(&viewProjection_ , &matProjection_);
	player->SetMap(map);
	player->SetGoal(goal);
	player->SetEnemy(enemy);

	particle = new Particle;
	particle->Initialize(&viewProjection_ , &matProjection_ , player);


	stage = 1;

}

void GameScene::Update() {
	
	viewProjection_.UpdateView();
	player->Update();
	particle->Update();
	//goal->Update();

}

void GameScene::Draw() {
	//3D描画
	
	player->Draw();

	//スプライト描画
	Sprite::PreDraw(dx12base_.GetCmdList().Get());


	Sprite::PostDraw();

}

void GameScene::Reset() {

	player->Reset();
	particle->Reset();
	map->LoadMap(stage , &viewProjection_ , &matProjection_);

}