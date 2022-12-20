#include "Library.h"
#include <DxLib.h>

namespace TEngine
{
	bool Library::Init()
	{
		// ���C�u�����ɕK�v�ȏ������������s��
		ChangeWindowMode(true);
		int window_width = 800;
		int window_height = 600;
		int color_bit = 32;
		SetGraphMode(window_width, window_height, color_bit);

		// ����������
		return DxLib_Init() != -1 ? true : false;
	}

	void Library::End()
	{
		// ���C�u�������I�������鏈�������s����
		textureManager.DeleteTextureAll();
		modelManager.DeleteAll();

		// DxLib��
		DxLib_End();
	}

	bool Library::IsLoopFinish()
	{
		int ret = ProcessMessage();
		if (CheckHitKey(KEY_INPUT_ESCAPE) || ret != 0)
		{
			// ���[�v�I��
			return true;
		}
		// ���[�v�p��
		return false;
	}

	void Library::UpdateDevice()
	{
		// Dxlib�̏ꍇ��ProcessMessage��Device�̍X�V���s���Ă���̂ŋ�

		input.Update();
	}



}