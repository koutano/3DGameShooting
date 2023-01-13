#ifndef ENEMY_04_H_
#define ENEMY_04_H_

#include "EnemyBase.h"
#include "DxLib.h"

namespace Game
{
	class Enemy04:public EnemyBase
	{
	public:
		Enemy04(VECTOR pos_);
		~Enemy04()override = default;
	public:
		void Update()override;
		void Draw()override;
		void OnCollisionBullet()override;
	};
}

#endif // !ENEMY_04_H_
