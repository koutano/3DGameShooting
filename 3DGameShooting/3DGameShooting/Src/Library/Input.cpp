#include "Input.h"

namespace TEngine 
{
	bool Input::IsKeyHeld(int key)
	{
		if (current_Key_Buffer[key] == true &&
			prev_Key_Buffer[key] == true)
		{
			// ����
			return true;
		}
		// ���s
		return false;
	}

	bool Input::IsKeyPushed(int key)
	{
		if (current_Key_Buffer[key] == true &&
			prev_Key_Buffer[key] == false)
		{
			// ����
			return true;
		}
		// ���s
		return false;
	}
	
	bool Input::IsKeyReleased(int key)
	{
		if (current_Key_Buffer[key] == false &&
			prev_Key_Buffer[key] == true)
		{
			// ����
			return true;
		}
		// ���s
		return false;
	}

	bool Input::GetMousePosition(int& x, int& y)
	{
		return GetMousePoint(&x, &y) == 0 ? true : false;
	}

	bool Input::IsMouseHeld(MouseType type_)
	{
		if (current_Mouse_Buffer[(int)type_] == true &&
			prev_Mouse_Buffer[(int)type_] == true)
		{
			return true;
		}
		return false;
	}

	bool Input::IsMousePushed(MouseType type_)
	{
		if (current_Mouse_Buffer[(int)type_] == true &&
			prev_Mouse_Buffer[(int)type_] == false)
		{
			return true;
		}
		return false;
	}

	bool Input::IsMouseReleased(MouseType type_)
	{
		if (current_Mouse_Buffer[(int)type_] == false &&
			prev_Mouse_Buffer[(int)type_] == true)
		{
			return true;
		}
		return false;
	}


	void Input::Update()
	{
		// �L�[�̍X�V�O�ɃL�[����prev�ɕۑ�����
		memcpy(prev_Key_Buffer, current_Key_Buffer, sizeof(char) * Max_Key);
		// �L�[�̍X�V
		GetHitKeyStateAll(current_Key_Buffer);
		
		memcpy(prev_Mouse_Buffer, current_Mouse_Buffer, sizeof(bool) * Max_Mouse_Type);

		int dx_mouse_defines[]
		{
			MOUSE_INPUT_LEFT,
			MOUSE_INPUT_RIGHT,
			MOUSE_INPUT_MIDDLE,
		};

		for (int i = 0; i < Max_Mouse_Type; i++)
		{
			current_Mouse_Buffer[i] = (GetMouseInput() & dx_mouse_defines[i]) != 0;
			/*
			* bool�^�Ȃ��̏������ɕύX�ł���
			if (GetMouseInput() & dx_mouse_defines[i] != 0)
			{
				current_Mouse_Buffer[i] = true;
			}
			else
			{
				current_Mouse_Buffer[i] = false;
			}*/
		}

	}
}