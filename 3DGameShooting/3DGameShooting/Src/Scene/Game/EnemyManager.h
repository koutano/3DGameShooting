#ifndef ENEMY_MANAGER_H_
#define ENEMY_MANAGER_H_

#include "Enemy.h"
#include "vector"

namespace Game
{
	class EnemyManager
	{
	public:
		EnemyManager();
		~EnemyManager();
		
	public:
		void CreateEnemy(VECTOR pos_);
		void Update();
		void Draw();

		std::vector<Enemy*> GetEnemies() { return enemies; }
	private:
		std::vector<Enemy*> enemies;
	};
}

#endif // !ENEMY_MANAGER_H_

