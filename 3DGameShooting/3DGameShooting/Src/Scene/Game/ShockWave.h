#ifndef SHOCK_WAVE_H_
#define SHOCK_WAVE_H_

#include "DxLib.h"
#include "ObjBase.h"

namespace Game
{
	// 衝撃波クラス
	class ShockWave:public ObjBase
	{
	public:
		ShockWave(VECTOR pos_);
		~ShockWave()override = default;
	public:
		void Update()override;
		void Draw()override;
	};
}

#endif // !ENEMY_03_H_
