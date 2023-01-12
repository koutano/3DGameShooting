#include "Enemy02.h"
#include "../../Library/Library.h"
#define _USE_MATH_DEFINES
#include <math.h>

namespace Game
{
	Enemy02::Enemy02(VECTOR pos_) :
		EnemyBase(pos_, VGet(1, 1, 1), VGet(0, 180, 0))
	{
		hp = 1000;
	}

	void Enemy02::Update()
	{
		pos.x += sinf(degreeAngle.y / 180 * M_PI) * speed;
		pos.z += cosf(degreeAngle.y / 180 * M_PI) * speed;

		--deleteTime;
		if (deleteTime < 0)
		{
			SetDeadFlag(true);
		}
	}

	void Enemy02::Draw()
	{
		TEngine::Library::DrawModel("enemy02", pos, degreeAngle, scale);
	}
}