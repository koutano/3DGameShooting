#ifndef SCENE_CONTROL_H_
#define SCENE_CONTROL_H_

#include "BaseScene.h"

namespace Game
{
	class SceneControl
	{
	public:
		SceneControl();
		~SceneControl() = default;

	public:
		// 更新用関数
		void Update();

	private:
		// シーン移行用関数
		void ChangeScene();

	private:

		BaseScene* scene{ nullptr };
	};
}
#endif	// !SCENE_CONTROL_H_