#include "GameScene.h"
#include "../Library/Library.h"
#define _USE_MATH_DEFINES
#include <math.h>

namespace Game
{

	GameScene::GameScene()
	{
		nextScene = Scene::Title;
		TEngine::Library::LoadTexture("game", "Res/Game.png");
		
		bulletManager = new BulletManager;
		player = new Player(bulletManager);
		camera = new CameraManager;
		enemyManager = new EnemyManager;
		score = new Score;
	}

	GameScene::~GameScene()
	{
		TEngine::Library::DeleteTexture("game");
		delete bulletManager;
		delete player;
		delete camera;
		delete enemyManager;
		delete score;
	}

	void GameScene::Update()
	{
		player->Update();
		camera->Update();
		bulletManager->Update();
		enemyManager->Update();



		auto bullets = bulletManager->GetBullets();
		auto enemies = enemyManager->GetEnemies();

		/*for (int i = 0; i < bullets.size(); ++i)
		{
			if (Collision(bullets[i], enemy))
			{
				isNextScene = true;
			}
		}*/
		

		for (auto itr1 = enemies.begin(); itr1 != enemies.end(); ++itr1)
		{
			for (auto itr2 = bullets.begin(); itr2 != bullets.end(); ++itr2)
			{
				if (Collision(*itr1, *itr2))
				{
					(*itr1)->OnCollisionBullet();
					(*itr2)->OnCollisionEnemy();
					if ((*itr1)->GetDeadFlag())
					{
						score->AddScore(70);
					}
				}
			}
		}

		if (enemyCount >= 0)
		{
			enemyManager->CreateEnemy(VGet(GetRand(player->GetMoveWidthArea() * 2) - (player->GetMoveWidthArea()),
				GetRand(player->GetMoveHeightArea() * 2) - (player->GetMoveHeightArea()), enemyFirstPosZ));
			enemyCount = 0;
		}
		enemyCount++;
		/*if(Collision(player, enemy))
		{
			isNextScene = true;
		}*/

		if (TEngine::Library::IsKeyPushed(KEY_INPUT_RETURN))
		{
			isNextScene = true;
		}
	
	}

	void GameScene::Draw()
	{
		//TEngine::Library::DrawTexture("game", 400, 300);
		player->Draw();
		bulletManager->Draw();
		enemyManager->Draw();

		score->Draw();
	}

	bool GameScene::Collision(ObjBase* obj1_, ObjBase* obj2_)
	{
		VECTOR pos1 = obj1_->GetPos();
		VECTOR scale1 = obj1_->GetScale();

		VECTOR pos2 = obj2_->GetPos();
		VECTOR scale2 = obj2_->GetScale();

		VECTOR obj1ColPos1{ pos1.x + (scale1.x / 2),pos1.y + (scale1.y / 2),pos1.z + (scale1.z / 2) };
		VECTOR obj1ColPos2{ pos1.x - (scale1.x / 2),pos1.y - (scale1.y / 2),pos1.z - (scale1.z / 2) };
		
		VECTOR obj2ColPos1{ pos2.x + (scale2.x / 2),pos2.y + (scale2.y / 2),pos2.z + (scale2.z / 2) };
		VECTOR obj2ColPos2{ pos2.x - (scale2.x / 2),pos2.y - (scale2.y / 2),pos2.z - (scale2.z / 2) };

		/*
		// ‚±‚Á‚¿‚Å‚àok
		if (obj1ColPos1.x >= obj2ColPos2.x && obj2ColPos1.x >= obj1ColPos2.x&&
			obj1ColPos1.y >= obj2ColPos2.y && obj2ColPos1.y >= obj1ColPos2.y&&
			obj1ColPos1.z >= obj2ColPos2.z && obj2ColPos1.z >= obj1ColPos2.z)
		{
			return true;
		}*/

		if (obj1ColPos1.x <= obj2ColPos2.x || obj2ColPos1.x <= obj1ColPos2.x)
		{
			return false;
		}

		if (obj1ColPos1.y <= obj2ColPos2.y || obj2ColPos1.y <= obj1ColPos2.y)
		{
			return false;
		}

		if (obj1ColPos1.z <= obj2ColPos2.z || obj2ColPos1.z <= obj1ColPos2.z)
		{
			return false;
		}

		return true;
	}

	void GameScene::MoveRange(CameraManager* camera_, ObjBase* obj2_)
	{
		VECTOR moveRange{};

		auto camera = camera_->GetPos();
		//auto *obj = &obj2_->GetPos();

		//auto cameraRange = VSub(camera, obj);
		float cameraRange = 10;
		float fav = 60;
		float sita = 90 - (fav / 2);
		

		auto moverangeX = cameraRange * tanf(sita / 180 * M_PI);
		//auto moverangeY = cameraRange.y - tanf(sita2);
		
		/*if ((*obj).x >= moverangeX)
		{
			(*obj).x = moverangeX;
		}*/
		

	}

}