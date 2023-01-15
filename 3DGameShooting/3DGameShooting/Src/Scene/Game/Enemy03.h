#ifndef ENEMY_03_H_
#define ENEMY_03_H_

#include "EnemyBase.h"
#include "DxLib.h"

namespace Game
{
	// 弾が当たると大きくなる敵
	class Enemy03:public EnemyBase
	{
	public:
		Enemy03(VECTOR pos_);
		~Enemy03()override = default;
	public:
		void Update()override;
		void Draw()override;
		void OnCollisionBullet()override;
	};
}

#endif // !ENEMY_03_H_
