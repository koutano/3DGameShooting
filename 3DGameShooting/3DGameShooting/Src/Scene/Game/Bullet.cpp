#include "Bullet.h"
#include "../../Library/Library.h"
#define _USE_MATH_DEFINES
#include <math.h>

namespace Game
{
	Bullet::Bullet(ObjBase* obj_) :
		ObjBase(VGet(0, 0, 0), VGet(1, 1, 1), VGet(0, 0, 0))
	{
		pos = obj_->GetPos();
		degreeAngle = obj_->GetDegreeAngle();
	}

	Bullet::~Bullet()
	{
	}

	void Bullet::Update()
	{
		pos.x += sinf(degreeAngle.y / 180 * M_PI) * speed;
		pos.y += sinf(degreeAngle.x / 180 * M_PI) * speed;
		pos.z += cosf(degreeAngle.y / 180 * M_PI) * speed;

		deleteTime--;
		if (deleteTime <= 0)
		{
			SetDeadFlag(true);
		}
	}

	void Bullet::Draw()
	{
		TEngine::Library::DrawModel("bullet", pos, degreeAngle, scale);
	}
}
