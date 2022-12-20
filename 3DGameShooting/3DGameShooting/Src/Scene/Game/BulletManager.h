#ifndef BULLET_MANAGER_H_
#define BULLET_MANAGER_H_

#include "Bullet.h"
#include <vector>

namespace Game
{
	class BulletManager
	{
	public:
		BulletManager();
		~BulletManager();

	public:
		// �e�̐���
		void CreateBullet(ObjBase* obj_);
		// �X�V�p
		void Update();
		// �`��p
		void Draw();

		std::vector< Bullet* > GetBullets() { return bullets; }

	private:
		std::vector<Bullet*> bullets{};
	};
}

#endif // !BULLET_MANAGER_H_

