#include "EnemyManager.h"
#include "../../Library/Library.h"

namespace Game
{
	EnemyManager::EnemyManager()
	{
		TEngine::Library::LoadModel("enemy", "Res/Enemy.mv1");
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

	void EnemyManager::Update()
	{
		// “G‚ÌXVˆ—
		for (auto enemy : enemies)
		{
			enemy->Update();
		}

		// “G‚ÌÁ‚¦‚éˆ—
		for (auto itr = enemies.begin(), itr_end = enemies.end(); itr != enemies.end();)
		{
			if ((*itr)->IsDead())
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
