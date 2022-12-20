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
		// �������ς������MaxMouseType�̑�����̕ύX�̕K�v����
	};

	class Input
	{
	public:
		// default�̐������ĂȂ����炠�Ƃ�
		Input()
		{
		}

		// �L�[�{�[�h
		// �����Ă�����
		bool IsKeyHeld(int key);
		// �������t���[��
		bool IsKeyPushed(int key);
		// �������t���[��
		bool IsKeyReleased(int key);

		// �}�E�X
		// ���W�擾
		bool GetMousePosition(int& x, int& y);
		// �����Ă�����
		bool IsMouseHeld(MouseType type_);
		// �������t���[��
		bool IsMousePushed(MouseType type_);
		// �������t���[��
		bool IsMouseReleased(MouseType type_);



		/*
			���͏����X�V����
			���t���[���Ɉ�x���s
		*/
		void Update();

	private:
		
		static const int Max_Key = 256;
		// ��ނ�Max��ǉ�����̂͂��������̂ōŌ�̒l��+1(Center����Ȃ��ꍇ������̂Œ���)
		static const int Max_Mouse_Type = (int)(MouseType::Center) + 1;

	private:
		// �L�[�{�[�h�p
		char current_Key_Buffer[Max_Key];	// ���t���[��
		char prev_Key_Buffer[Max_Key];		// ��(�ЂƂO)�t���[��
		// �}�E�X�p
		bool current_Mouse_Buffer[Max_Mouse_Type];	// ���t���[��
		bool prev_Mouse_Buffer[Max_Mouse_Type];		// ���t���[��
	};

}


#endif
