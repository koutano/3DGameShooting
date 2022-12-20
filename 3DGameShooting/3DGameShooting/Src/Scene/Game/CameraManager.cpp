#include "CameraManager.h"
#define _USE_MATH_DEFINES
#include <math.h>

namespace Game
{
	CameraManager::CameraManager()
	{
		SetNearAndFar(0.1f, 1000.0f);
		SetupCamera_Perspective(fov/ 180 * M_PI);
	}

	CameraManager::CameraManager(Player* player_):
		player(player_)
	{
	}

	void CameraManager::Update()
	{

		SetCameraPositionAndTargetAndUpVec(
			pos,
			VGet(0.0f, 0.0f, 0.0f),
			VGet(0.0f, 1.0f, 0.0f)
		);

		// 座標の更新
		//pos = VAdd(parameter.pos, parameter.offsetPos);
		// 注視点の更新
		//targetPos = VAdd(parameter.frontVector, pos);

		//VECTOR playerPos = player->GetPos();
		//VECTOR playerRote = player->GetDegreeAngle();
		//VECTOR targetPos{};

		//targetPos.x = playerPos.x - sinf(playerRote.y / 180.0f * DX_PI) * -1;
		//targetPos.z = playerPos.z - cosf(playerRote.y / 180.0f * DX_PI) * -1;
		//targetPos.y = playerPos.y - sinf(playerRote.x / 180.0f * DX_PI);

		//SetCameraPositionAndTarget_UpVecY(
		//	playerPos,			// カメラ座標
		//	targetPos		// 注視点
		//);
	}
}
