#include "Graphics.h"
#include <DxLib.h>

namespace TEngine
{
	void Graphics::StartRendering()
	{
		// �`��J�n�̏�������
		ClearDrawScreen();
	}

	void Graphics::FinishRendering()
	{
		// �`��I�����̏���
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
		// �n���h���̃`�F�b�N
		if (handle_ < 0)
		{
			return;
		}

		float rad = degree_ * (DX_PI / 180.0f);

		// ���l��L���ɂ���(�����Ń��l���w��)
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_);			
		
		// x,y�͍�����W�Ȃ̂ŁA����𒆐S���W�ɕϊ�����K�v������
		// �摜�T�C�Y�擾
		int width = 0;
		int height = 0;
		GetGraphSize(handle_, &width, &height);

		// ���ォ�璆�S��(�`����W�̎�������̏ꍇ�͂��������)
		/*x_ += width / 2.0f;
		y_ += height / 2.0f;*/

		DrawRotaGraph3(
			x_, y_,							// �`����W
			width / 2.0f, height / 2.0f,	// �摜�̒��S�ʒu
			scale_x_, scale_y_,				// �g�k��
			rad,							// ��]�p�x
			handle_,						// �摜�̃n���h��
			true,							// ���߂̗L��
			false							// ���]�̗L��
		);

		// �u�����h�̖�����
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	void Graphics::DrawModel(const char* keyword_, VECTOR pos_, VECTOR degree_, VECTOR scale_)
	{
		int handle = modelManager->GetModel(keyword_);
		if (handle == -1)
		{
			//�ǂݍ��ݎ��s
			return;
		}

		MV1SetPosition(handle, pos_);
		MV1SetScale(handle, scale_);
		VECTOR rad = VScale(degree_, (DX_PI / 180.0f));
		MV1SetRotationXYZ(handle, rad);

		MV1DrawModel(handle);
	}
}