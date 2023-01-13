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
		// 弾の生成
		void CreateBullet(ObjBase* obj_);
		// 更新用
		void Update();
		// 描画用
		void Draw();

		std::vector< Bullet* > GetBullets() { return bullets; }

	private:
		std::vector<Bullet*> bullets{};
	};
}

#endif // !BULLET_MANAGER_H_

