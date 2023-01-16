#ifndef ENEMY_05_H_
#define ENEMY_05_H_

#include "EnemyBase.h"
#include "DxLib.h"

namespace Game
{
	// ホーミングする敵
	class Enemy05:public EnemyBase
	{
	public:
		Enemy05(VECTOR pos_);
		~Enemy05()override = default;
	public:
		void Update()override;
		void Draw()override;

	};
}

#endif // !ENEMY_05_H_
