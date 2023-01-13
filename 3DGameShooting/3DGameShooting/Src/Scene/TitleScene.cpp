#include "TitleScene.h"
#include "../Library/Library.h"

namespace Game
{
	TitleScene::TitleScene()
	{
		nextScene = Scene::Game;
		TEngine::Library::LoadTexture("title", "Res/Title.png");
	}

	TitleScene::~TitleScene()
	{
		TEngine::Library::DeleteTexture("title");
	}

	void TitleScene::Update()
	{
		if (TEngine::Library::IsKeyPushed(KEY_INPUT_RETURN))
		{
			isNextScene = true;
		}
	}

	void TitleScene::Draw()
	{
		TEngine::Library::DrawTexture("title", 400, 300);
	}
}
