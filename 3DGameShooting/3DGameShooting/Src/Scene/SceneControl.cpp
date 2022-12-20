#include "SceneControl.h"
#include "GameScene.h"
#include "TitleScene.h"

namespace Game
{
	SceneControl::SceneControl()
	{
		scene = new TitleScene();
	}

	void SceneControl::Update()
	{
		if (scene == nullptr)
		{
			return;
		}

		scene->Update();

		scene->Draw();

		if (scene->IsEnd())
		{
			ChangeScene();
		}
	}

	void SceneControl::ChangeScene()
	{
		if (scene == nullptr)
		{
			return;
		}

		BaseScene* nextScene{ nullptr };

		switch (scene->GetNextScene())
		{
		case Scene::Title:
			nextScene = new TitleScene();
			break;
		case Scene::Game:
			nextScene = new GameScene();
			break;
		default:
			break;
		}

		delete scene;
		scene = nextScene;
	}
}