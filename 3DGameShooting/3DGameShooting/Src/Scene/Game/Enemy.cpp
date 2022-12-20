#include "Enemy.h"
#include "../../Library/Library.h"
#define _USE_MATH_DEFINES
#include <math.h>

namespace Game
{
	Enemy::Enemy(VECTOR pos_) :
		ObjBase(pos_,VGet(1,1,1),VGet(0,180,0))
	{
		MV1SetMaterialDifColor(TEngine::Library::GetModel("enemy"), 0, GetColorF(1.0f, 0.0f, 0.0f, 1.0f));
	}

	Enemy::~Enemy()
	{

	}

	void Enemy::Update()
	{
		pos.x += sinf(degreeAngle.y / 180 * M_PI) * speed;
		pos.z += cosf(degreeAngle.y / 180 * M_PI) * speed;

		--deleteTime;
		if (deleteTime < 0)
		{
			SetDeadFlag(true);
		}
	}

	void Enemy::Draw()
	{
		TEngine::Library::DrawModel("enemy", pos, degreeAngle, scale);
	}

	void Enemy::Move(int key_, float degreeAngle_)
	{
		if (TEngine::Library::IsKeyHeld(key_))
		{
			pos.x += sinf(degreeAngle_ / 180 * M_PI) * speed;
			pos.z += cosf(degreeAngle_ / 180 * M_PI) * speed;
		}
	}

	bool Enemy::IsDead()
	{
		return deadFlag;
	}
}