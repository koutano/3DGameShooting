#ifndef BULLET_H_
#define BULLET_H_

#include "ObjBase.h"

namespace Game
{
	// 弾
	class Bullet :public ObjBase
	{
	public:
		Bullet(ObjBase* obj_);
		~Bullet()override;
	public:
		// 更新用
		void Update()override;
		// 描画用
		void Draw()override;
		// 弾の生死確認用
		bool IsDead() { return deadFlag; }
		void SetDeadFlag(bool deadFlag_) { deadFlag = deadFlag_; }
		void OnCollisionEnemy() { deadFlag = true; }
	private:
		float speed{ 1.0f };	// 弾の速度
		int deleteTime{ 300 };	// 生存可能フレーム数
		bool deadFlag{ false };
	};
}

#endif // !BULLET_H_
