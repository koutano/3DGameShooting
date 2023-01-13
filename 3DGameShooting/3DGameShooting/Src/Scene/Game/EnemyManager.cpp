#include "EnemyManager.h"
#include "../../Library/Library.h"
#include "Enemy.h"
#include "Enemy02.h"
#include "Enemy03.h"

namespace Game
{
	EnemyManager::EnemyManager()
	{
		// Enemyモデルのロード
		TEngine::Library::LoadModel("enemy", "Res/Enemy.mv1");
		TEngine::Library::LoadModel("enemy02", "Res/Enemy02.mv1");
		TEngine::Library::LoadModel("enemy03", "Res/Enemy03.mv1");

		// Enemyの色付け
		MV1SetMaterialDifColor(TEngine::Library::GetModel("enemy"), 0, GetColorF(1.0f, 0.0f, 0.0f, 1.0f));
		MV1SetMaterialDifColor(TEngine::Library::GetModel("enemy02"), 0, GetColorF(0.0f, 1.0f, 0.0f, 1.0f));
		MV1SetMaterialDifColor(TEngine::Library::GetModel("enemy03"), 0, GetColorF(0.0f, 0.0f, 1.0f, 1.0f));
	}

	EnemyManager::~EnemyManager()
	{
		for (auto& enemy : enemies)
		{
			delete enemy;
		}
	}

	void EnemyManager::CreateEnemy(VECTOR pos_)
	{
		enemies.push_back(new Enemy(pos_));
	}

	void EnemyManager::CreateEnemy02(VECTOR pos_)
	{
		enemies.push_back(new Enemy02(pos_));
	}

	void EnemyManager::CreateEnemy03(VECTOR pos_)
	{
		enemies.push_back(new Enemy03(pos_));
	}

	void EnemyManager::Update()
	{
		// 敵の更新処理
		for (auto enemy : enemies)
		{
			enemy->Update();
		}

		// 敵の消える処理
		for (auto itr = enemies.begin(), itr_end = enemies.end(); itr != enemies.end();)
		{
			if ((*itr)->GetDeadFlag())
			{
				delete* itr;
				itr = enemies.erase(itr);
			}
			else
			{
				++itr;
			}
		}
	}

	void EnemyManager::Draw()
	{
		for (auto enemy : enemies)
		{
			enemy->Draw();
		}
	}

}
