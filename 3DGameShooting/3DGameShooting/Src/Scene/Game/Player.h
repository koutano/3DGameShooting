#ifndef PLAYER_H_
#define PLAYER_H_

#include <DxLib.h>
#include "ObjBase.h"
#include "Player.h"
#include "BulletManager.h"

namespace Game
{
	// プレイヤークラス
	class Player :public ObjBase
	{
	public:
		Player(BulletManager* bullet_manager_);
		~Player()override;

	public:
		// 更新用
		void Update()override;
		// 描画用
		void Draw()override;

		int GetMoveWidthArea()const { return moveWidthArea; }
		int GetMoveHeightArea()const { return moveHeightArea; }

	private:
		void MoveArea();
	private:
		BulletManager* bulletManager{ nullptr };	// 弾出す用

		float speed{ 0.1 };		// 移動速度
		int moveWidthArea{ 7 };
		int moveHeightArea{ 5 };
	};
}

#endif // !PLAYER_H_
