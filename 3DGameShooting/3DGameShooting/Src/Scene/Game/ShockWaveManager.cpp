#include "ShockWaveManager.h"
#include "../../Library/Library.h"
namespace Game
{
	ShockWaveManager::ShockWaveManager()
	{
		TEngine::Library::LoadModel("bullet", "Res/NormalSphere.mv1");
	}

	ShockWaveManager::~ShockWaveManager()
	{
		for (auto& shockWave : shockWaves)
		{
			delete shockWave;
		}
		TEngine::Library::DeleteModel("bullet");
	}

	void ShockWaveManager::CreateShockWave(ObjBase* obj_)
	{
		shockWaves.push_back(new ShockWave(obj_));
	}

	void ShockWaveManager::Update()
	{
		// 弾の更新処理
		for (auto bullet : shockWaves)
		{
			bullet->Update();
		}

		// 弾の消える処理
		for (auto itr = shockWaves.begin(), itr_end = shockWaves.end(); itr != shockWaves.end();)
		{
			if ((*itr)->IsDead())
			{
				delete* itr;
				itr = bullets.erase(itr);
			}
			else
			{
				++itr;
			}
		}
	}

	void ShockWaveManager::Draw()
	{
		for (auto bullet : shockWaves)
		{
			bullet->Draw();
		}
	}
}
