#ifndef ENEMY_04_H_
#define ENEMY_04_H_

#include "EnemyBase.h"
#include "DxLib.h"

namespace Game
{
	// 倒れると衝撃波を出す敵
	class Enemy04:public EnemyBase
	{
	public:
		Enemy04(VECTOR pos_);
		~Enemy04()override = default;
	public:
		void Update()override;
		void Draw()override;
		void AfterDeath(int* isCreateShockWave_)override;
	};
}

#endif // !ENEMY_04_H_
