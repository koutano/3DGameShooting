#ifndef ENEMY_02_H_
#define ENEMY_02_H_

#include "EnemyBase.h"
#include <DxLib.h>

namespace Game
{
	class Enemy02:public EnemyBase
	{
	public:
		Enemy02(VECTOR pos_);
		~Enemy02()override = default;
	public:
		void Update()override;
		void Draw()override;
	};
}

#endif // !ENEMY_02_H_
