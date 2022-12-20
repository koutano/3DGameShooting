#ifndef ENEMY_H_
#define ENEMY_H_

#include "ObjBase.h"
#include "DxLib.h"

namespace Game
{
	class Enemy:public ObjBase
	{
	public:
		Enemy(VECTOR pos_);
		~Enemy()override;
	public:
		void Update()override;
		void Draw()override;
		bool IsDead();

		void SetDeadFlag(bool deadFlag_) { deadFlag = deadFlag_; }
	private:
		void Move(int key_, float degreeAngle_);
		float speed{ 0.1f };
		int deleteTime{ 300 };
		bool deadFlag{ false };
	};
}

#endif // !ENEMY_H_
