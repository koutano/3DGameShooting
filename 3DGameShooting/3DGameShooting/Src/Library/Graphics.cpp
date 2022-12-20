#include "Graphics.h"
#include <DxLib.h>

namespace TEngine
{
	void Graphics::StartRendering()
	{
		// 描画開始の準備処理
		ClearDrawScreen();
	}

	void Graphics::FinishRendering()
	{
		// 描画終了時の処理
		ScreenFlip();
	}

	void Graphics::DrawTexture(const char* keyword_, float x_, float y_, unsigned char alpha_, float degree_, float scale_x_, float scale_y_)
	{
		int handle = textureManager->GetTexture(keyword_);
		if (handle != -1)
		{
			DrawTexture(handle, x_, y_, alpha_, degree_, scale_x_, scale_y_);
		}
	}

	void Graphics::DrawDivTesture(const char* keyword_, int div_no_, float x_, float y_, unsigned char alpha_, float degree_, float scale_x_, float scale_y_)
	{
		int handle = textureManager->GetDivTexture(keyword_, div_no_);	
		if (handle != -1)
		{
			DrawTexture(handle, x_, y_, alpha_, degree_, scale_x_, scale_y_);
		}
	}

	void Graphics::DrawTexture(int handle_, float x_, float y_, unsigned char alpha_, float degree_, float scale_x_, float scale_y_)
	{
		// ハンドルのチェック
		if (handle_ < 0)
		{
			return;
		}

		float rad = degree_ * (DX_PI / 180.0f);

		// α値を有効にする(引数でα値を指定)
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_);			
		
		// x,yは左上座標なので、それを中心座標に変換する必要がある
		// 画像サイズ取得
		int width = 0;
		int height = 0;
		GetGraphSize(handle_, &width, &height);

		// 左上から中心へ(描画座標の軸が左上の場合はこれを実装)
		/*x_ += width / 2.0f;
		y_ += height / 2.0f;*/

		DrawRotaGraph3(
			x_, y_,							// 描画座標
			width / 2.0f, height / 2.0f,	// 画像の中心位置
			scale_x_, scale_y_,				// 拡縮率
			rad,							// 回転角度
			handle_,						// 画像のハンドル
			true,							// 透過の有無
			false							// 反転の有無
		);

		// ブレンドの無効化
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	void Graphics::DrawModel(const char* keyword_, VECTOR pos_, VECTOR degree_, VECTOR scale_)
	{
		int handle = modelManager->GetModel(keyword_);
		if (handle == -1)
		{
			//読み込み失敗
			return;
		}

		MV1SetPosition(handle, pos_);
		MV1SetScale(handle, scale_);
		VECTOR rad = VScale(degree_, (DX_PI / 180.0f));
		MV1SetRotationXYZ(handle, rad);

		MV1DrawModel(handle);
	}
}