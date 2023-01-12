#ifndef BULLET_H_
#define BULLET_H_

#include "ObjBase.h"

namespace Game
{
	class Bullet :public ObjBase
	{
	public:
		Bullet(ObjBase* obj_);
		~Bullet()override;
	public:
		// �X�V�p
		void Update()override;
		// �`��p
		void Draw()override;
		// �e�̐����m�F�p
		bool IsDead() { return deadFlag; }
		void SetDeadFlag(bool deadFlag_) { deadFlag = deadFlag_; }
		void OnCollisionEnemy() { deadFlag = true; }
	private:
		float speed{ 1.0f };	// �e�̑��x
		int deleteTime{ 300 };	// �����\�t���[����
		bool deadFlag{ false };
	};
}

#endif // !BULLET_H_
