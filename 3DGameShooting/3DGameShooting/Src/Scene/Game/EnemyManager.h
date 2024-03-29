﻿#ifndef ENEMY_MANAGER_H_
#define ENEMY_MANAGER_H_

#include "Enemy.h"
#include "vector"
#include "EnemyBase.h"

namespace Game
{
	// 敵管理クラス
	class EnemyManager
	{
	public:
		EnemyManager();
		~EnemyManager();
		
	public:
		void CreateEnemy(VECTOR pos_);
		void CreateEnemy02(VECTOR pos_);
		void CreateEnemy03(VECTOR pos_);
		void CreateEnemy04(VECTOR pos_);
		void CreateEnemy05(VECTOR pos_);
		void Update();
		void Draw();

		std::vector<EnemyBase*> GetEnemies() { return enemies; }
	private:
		std::vector<EnemyBase*> enemies;
	};
}

#endif // !ENEMY_MANAGER_H_

