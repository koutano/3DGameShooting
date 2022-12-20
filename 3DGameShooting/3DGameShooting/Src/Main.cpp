#include "Library/Library.h"
#include "Scene/SceneControl.h"

//const int window_width = 800;
//const int window_height = 600;
//const int color_bit = 32;

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (TEngine::Library::Initialized() == false)
	{
		return 0;
	}

	/*ChangeWindowMode(true);
	SetGraphMode(window_width, window_height, color_bit);*/

	//if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	//{
	//	return -1;			// エラーが起きたら直ちに終了
	//}
	Game::SceneControl scene;
	while (true)
	{
		if (TEngine::Library::Update() == false)
		{
			break;
		}
		/*if (TEngine::Library::IsKeyPushed(KEY_INPUT_RETURN))
		{
			break;
		}*/

		TEngine::Library::StartRendering();

		scene.Update();

		TEngine::Library::FinishRendering();
	}


	TEngine::Library::Finish();
	//DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
