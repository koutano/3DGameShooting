#ifndef INPUT_H_
#define INPUT_H_

#include <DxLib.h>

namespace TEngine
{
	enum class MouseType
	{
		Left,
		Right,
		Center,
		// 末尾が変わったらMaxMouseTypeの代入式の変更の必要あり
	};

	class Input
	{
	public:
		// defaultの説明してないからあとで
		Input()
		{
		}

		// キーボード
		// 押している状態
		bool IsKeyHeld(int key);
		// 押したフレーム
		bool IsKeyPushed(int key);
		// 離したフレーム
		bool IsKeyReleased(int key);

		// マウス
		// 座標取得
		bool GetMousePosition(int& x, int& y);
		// 押している状態
		bool IsMouseHeld(MouseType type_);
		// 押したフレーム
		bool IsMousePushed(MouseType type_);
		// 離したフレーム
		bool IsMouseReleased(MouseType type_);



		/*
			入力情報を更新する
			毎フレームに一度実行
		*/
		void Update();

	private:
		
		static const int Max_Key = 256;
		// 種類にMaxを追加するのはおかしいので最後の値に+1(Centerじゃない場合があるので注意)
		static const int Max_Mouse_Type = (int)(MouseType::Center) + 1;

	private:
		// キーボード用
		char current_Key_Buffer[Max_Key];	// 現フレーム
		char prev_Key_Buffer[Max_Key];		// 旧(ひとつ前)フレーム
		// マウス用
		bool current_Mouse_Buffer[Max_Mouse_Type];	// 現フレーム
		bool prev_Mouse_Buffer[Max_Mouse_Type];		// 旧フレーム
	};

}


#endif
