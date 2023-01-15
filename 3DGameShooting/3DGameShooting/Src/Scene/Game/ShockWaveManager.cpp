#include "ShockWaveManager.h"
#include "../../Library/Library.h"
namespace Game
{
	ShockWaveManager::ShockWaveManager()
	{
		TEngine::Library::LoadModel("shockwave", "Res/ShockWave.mv1");
		MV1SetMaterialDifColor(TEngine::Library::GetModel("shockwave"), 0, GetColorF(0.6627f, 0.8078f, 0.9255f, 0.5f));

	}

	ShockWaveManager::~ShockWaveManager()
	{
		for (auto& shockWave : shockWaves)
		{
			delete shockWave;
		}
		TEngine::Library::DeleteModel("shockwave");
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
			if ((*itr)->GetDeadFlag())
			{
				delete* itr;
				itr = shockWaves.erase(itr);
			}
			else
			{
				++itr;
			}
		}
	}

	void ShockWaveManager::Draw()
	{
		for (auto shockWave : shockWaves)
		{
			shockWave->Draw();
		}
	}
}
