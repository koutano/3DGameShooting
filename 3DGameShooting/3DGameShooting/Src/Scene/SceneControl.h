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
		// �X�V�p�֐�
		void Update();

	private:
		// �V�[���ڍs�p�֐�
		void ChangeScene();

	private:

		BaseScene* scene{ nullptr };
	};
}
#endif	// !SCENE_CONTROL_H_