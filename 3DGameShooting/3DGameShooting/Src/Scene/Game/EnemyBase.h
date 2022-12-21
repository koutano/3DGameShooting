#ifndef ENEMY_BASE_H_
#define ENEMY_BASE_H_

#include "ObjBase.h"

namespace Game
{
	class EnemyBase:public ObjBase
	{
	public:
		EnemyBase(VECTOR pos_, VECTOR scale_, VECTOR degreeAngle_) :
			ObjBase(pos_,scale_,degreeAngle_)
		{}
		~EnemyBase() = default;
		virtual bool IsDead() = 0;

		void SetDeadFlag(bool deadFlag_) { deadFlag = deadFlag_; }
	protected:
		float speed{ 0.1f };
		int deleteTime{ 300 };
		bool deadFlag{ false };
		int hp{ 1 };
	};
}

#endif // !ENEMY_BASE_H_
