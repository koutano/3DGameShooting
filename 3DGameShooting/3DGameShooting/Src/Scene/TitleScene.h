#ifndef TITLE_SCENE_H_
#define TITLE_SCENE_H_

#include "BaseScene.h"

namespace Game
{
	class TitleScene :public BaseScene
	{
	public:
		TitleScene();
		~TitleScene()override;

	public:
		void Update()override;

		void Draw()override;

	private:
	};
}

#endif // !TITLE_SCENE_H_
