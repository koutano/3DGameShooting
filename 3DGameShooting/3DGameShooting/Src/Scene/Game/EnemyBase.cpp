#include "EnemyBase.h"

namespace Game
{
	void EnemyBase::OnCollisionBullet()
	{
		hp--;
		if (hp <= 0)
		{
			SetDeadFlag(true);
		}
	}
}