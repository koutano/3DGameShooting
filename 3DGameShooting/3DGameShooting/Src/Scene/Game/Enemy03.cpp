#include "Enemy03.h"
#include "../../Library/Library.h"
#define _USE_MATH_DEFINES
#include <math.h>

namespace Game
{
	Enemy03::Enemy03(VECTOR pos_) :
		EnemyBase(pos_,VGet(1,1,1),VGet(0,180,0))
	{
	}

	void Enemy03::Update()
	{
		pos.x += sinf(degreeAngle.y / 180 * M_PI) * speed;
		pos.z += cosf(degreeAngle.y / 180 * M_PI) * speed;

		--deleteTime;
		if (deleteTime < 0)
		{
			SetDeadFlag(true);
		}
	}

	void Enemy03::Draw()
	{
		TEngine::Library::DrawModel("enemy03", pos, degreeAngle, scale);
	}

}
