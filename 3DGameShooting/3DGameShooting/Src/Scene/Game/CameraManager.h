#ifndef CAMERA_MANAGER_H_
#define CAMERA_MANAGER_H_

#include <DxLib.h>
#include "Player.h"

namespace Game
{
	class CameraManager
	{
	public:
		CameraManager();
		CameraManager(Player* player_);
		~CameraManager() = default;

	public:
		void Update();

		// NearとFarの更新
		static void SetNearAndFar(float n, float f)
		{
			SetCameraNearFar(n, f);
		}

		VECTOR GetPos() { return pos; }
	private:
		Player* player{ nullptr };
		VECTOR pos{ 0.0f, 0.0f, -10.0f };
		float fov{60};
	};
}

#endif // !CAMERA_MANAGER_H_
