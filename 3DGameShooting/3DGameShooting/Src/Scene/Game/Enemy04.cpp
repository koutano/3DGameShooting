#include "Enemy04.h"
#include "../../Library/Library.h"
#define _USE_MATH_DEFINES
#include <math.h>

namespace Game
{
	Enemy04::Enemy04(VECTOR pos_) :
		EnemyBase(pos_,VGet(1,1,1),VGet(0,180,0))
	{
		hp = 10;
	}

	void Enemy04::Update()
	{
		pos.x += sinf(degreeAngle.y / 180 * M_PI) * speed;
		pos.z += cosf(degreeAngle.y / 180 * M_PI) * speed;

		--deleteTime;
		if (deleteTime < 0)
		{
			SetDeadFlag(true);
		}
	}

	void Enemy04::Draw()
	{
		TEngine::Library::DrawModel("enemy04", pos, degreeAngle, scale);
	}

	void Enemy04::OnCollisionBullet()
	{
		hp--;
		if (hp <= 0)
		{
			SetDeadFlag(true);
		}
		

	}

}
