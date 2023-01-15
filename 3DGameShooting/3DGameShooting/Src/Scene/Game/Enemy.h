#ifndef ENEMY_H_
#define ENEMY_H_

#include "EnemyBase.h"
#include "DxLib.h"

namespace Game
{
	// 通常の敵
	class Enemy:public EnemyBase
	{
	public:
		Enemy(VECTOR pos_);
		~Enemy()override = default;
	public:
		void Update()override;
		void Draw()override;
	};
}

#endif // !ENEMY_H_
