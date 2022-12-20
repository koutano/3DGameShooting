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
		// �e�̍X�V����
		for (auto bullet : bullets)
		{
			bullet->Update();
		}

		// �e�̏����鏈��
		for (auto itr = bullets.begin(), itr_end = bullets.end(); itr != bullets.end();)
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

	void BulletManager::Draw()
	{
		for (auto bullet : bullets)
		{
			bullet->Draw();
		}
	}
}
