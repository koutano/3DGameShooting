#ifndef SHOCK_WAVE_MANAGER_H_
#define SHOCK_WAVE_MANAGER_H_

#include "ShockWave.h"
#include <vector>

namespace Game
{
	// 弾管理クラス
	class ShockWaveManager
	{
	public:
		ShockWaveManager();
		~ShockWaveManager();

	public:
		// 衝撃波の生成
		void CreateShockWave(ObjBase* obj_);
		// 更新用
		void Update();
		// 描画用
		void Draw();

		std::vector< ShockWave* > GetBullets() { return shockWaves; }

	private:
		std::vector<ShockWave*> shockWaves{};
	};
}

#endif // !SHOCK_WAVE_MANAGER_H_

