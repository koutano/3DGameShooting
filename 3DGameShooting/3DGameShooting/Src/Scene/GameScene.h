#ifndef GAME_SCENE_H_
#define GAME_SCENE_H_

#include "BaseScene.h"
#include "Game/Player.h"
#include "Game/CameraManager.h"
#include "Game/BulletManager.h"
#include "Game/EnemyManager.h"
#include "Game/Score.h"

namespace Game
{
	class GameScene :public BaseScene
	{
	public:
		GameScene();
		~GameScene()override;

	public:
		// 更新用
		void Update()override;
		// 描画用
		void Draw()override;

		bool Collision(ObjBase* obj1_, ObjBase* obj2_);

		void MoveRange(CameraManager* camera, ObjBase* obj2);
	private:
		Player* player{ nullptr };				// プレイヤー
		CameraManager* camera{ nullptr };		// カメラ
		BulletManager* bulletManager{ nullptr };// 弾
		EnemyManager* enemyManager{ nullptr };	// 敵
		Score* score{ nullptr };

		int enemyCount{ 0 };
		const int MaxEnemyCount{ 10 };
		int enemy02Count{ 0 };
		const int MaxEnemy02Count{ 20 };
		float enemyApperAreaX{ 100 };
		float enemyApperAreaY{ 50 };
		float enemyFirstPosZ{ 100 };
		//int score{ 0 };
	};
}
#endif	// !GAME_SCENE_H_