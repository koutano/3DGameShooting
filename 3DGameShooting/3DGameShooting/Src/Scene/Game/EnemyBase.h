#ifndef ENEMY_BASE_H_
#define ENEMY_BASE_H_

#include "ObjBase.h"

namespace Game
{
	// 敵基底クラス
	class EnemyBase:public ObjBase
	{
	public:
		EnemyBase(VECTOR pos_, VECTOR scale_, VECTOR degreeAngle_) :
			ObjBase(pos_,scale_,degreeAngle_)
		{}
		~EnemyBase() = default;
	public:
		bool GetDeadFlag() { return deadFlag; }
		void SetDeadFlag(bool deadFlag_) { deadFlag = deadFlag_; }
		virtual void OnCollisionBullet();
		virtual void OnCollisionShockWave();
		virtual void AfterDeath(int* isCreateShockWave_){}
	protected:
		float speed{ 0.5f };
		int deleteTime{ 300 };
		bool deadFlag{ false };
		int hp{ 1 };
	};
}

#endif // !ENEMY_BASE_H_
