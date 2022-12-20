#include "Library.h"
#include <DxLib.h>

namespace TEngine
{
	bool Library::Init()
	{
		// ライブラリに必要な初期化処理を行う
		ChangeWindowMode(true);
		int window_width = 800;
		int window_height = 600;
		int color_bit = 32;
		SetGraphMode(window_width, window_height, color_bit);

		// 初期化成功
		return DxLib_Init() != -1 ? true : false;
	}

	void Library::End()
	{
		// ライブラリを終了させる処理を実行する
		textureManager.DeleteTextureAll();
		modelManager.DeleteAll();

		// DxLib版
		DxLib_End();
	}

	bool Library::IsLoopFinish()
	{
		int ret = ProcessMessage();
		if (CheckHitKey(KEY_INPUT_ESCAPE) || ret != 0)
		{
			// ループ終了
			return true;
		}
		// ループ継続
		return false;
	}

	void Library::UpdateDevice()
	{
		// Dxlibの場合はProcessMessageでDeviceの更新を行っているので空

		input.Update();
	}



}