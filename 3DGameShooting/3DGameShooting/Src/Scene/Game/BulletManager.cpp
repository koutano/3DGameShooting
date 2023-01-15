#include "BulletManager.h"
#include "../../Library/Library.h"
namespace Game
{
	BulletManager::BulletManager()
	{
		TEngine::Library::LoadModel("bullet", "Res/NormalSphere.mv1");
	}

	BulletManager::~BulletManager()
	{
		for (auto& bullet : bullets)
		{
			delete bullet;
		}
		TEngine::Library::DeleteModel("bullet");
	}

	void BulletManager::CreateBullet(ObjBase* obj_)
	{
		bullets.push_back(new Bullet(obj_));
	}

	void BulletManager::Update()
	{
		// 弾の更新処理
		for (auto bullet : bullets)
		{
			bullet->Update();
		}

		// 弾の消える処理
		for (auto itr = bullets.begin(), itr_end = bullets.end(); itr != bullets.end();)
		{
			if ((*itr)->GetDeadFlag())
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

	void BulletManager::Draw()
	{
		for (auto bullet : bullets)
		{
			bullet->Draw();
		}
	}
}
