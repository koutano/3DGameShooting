#ifndef LIBRARY_H_
#define LIBRARY_H_

#include "Graphics.h"
#include "Input.h"
#include <DxLib.h>
namespace TEngine
{
	class Library
	{
	public:
		// �O����
		// �E�B���h�E�̃T�C�Y�A�E�B���h�E���[�h�A�^�C�g���o�[�̕���
		static bool Initialized()
		{
			return Instance()->Init();
		}

		static void Finish()
		{
			Instance()->End();
		}

		static bool Update()
		{
			if (Instance()->IsLoopFinish() == false)
			{
				Instance()->UpdateDevice();
				// �X�V����
				return true;
			}
			// �X�V���s
			return false;
		}

		// �`�揈��
		// �`��J�n����
		static void StartRendering(){ Instance()->graphics.StartRendering(); }
		// �`��I������
		static void FinishRendering(){ Instance()->graphics.FinishRendering(); }
		// �e�N�X�`���`�揈��
		static void DrawTexture(const char* keyword_, float x_, float y_, unsigned char alpha_= 255, float degree_ = 0.0f, float scale_x_ = 1.0f, float scale_y_ = 1.0f) { Instance()->graphics.DrawTexture(keyword_, x_, y_, alpha_, degree_, scale_x_, scale_y_); }
		// �����e�N�X�`���`�揈��
		static void DrawDivTexture(const char* keyword_, int div_no_, float x_, float y_, unsigned char alpha_ = 255, float degree_ = 0.0f, float scale_x_ = 1.0f, float scale_y_ = 1.0f) { Instance()->graphics.DrawDivTesture(keyword_, div_no_, x_, y_, alpha_, degree_, scale_x_, scale_y_); }
		// 3D���f���`�揈��
		static void DrawModel(const char* keyword_, VECTOR pos_, VECTOR degree_, VECTOR scale_) { Instance()->graphics.DrawModel(keyword_, pos_, degree_, scale_); }

		// ���͏���
		// �����Ă�����
		static bool IsKeyHeld(int key_) { return Instance()->input.IsKeyHeld(key_); }
		// �������u��
		static bool IsKeyPushed(int key_) { return Instance()->input.IsKeyPushed(key_); }
		// �������u��
		static bool IsKeyReleased(int key_) { return Instance()->input.IsKeyReleased(key_); }

		// �}�E�X���W
		static bool GetMousePosition(int& x_, int& y_){ return Instance()->input.GetMousePosition(x_, y_); }

		static bool IsMouseHeld		(MouseType type_) { return Instance()->input.IsMouseHeld(type_); }
		static bool IsMousePushed	(MouseType type_) { return Instance()->input.IsMousePushed(type_); }
		static bool IsMouseReleased	(MouseType type_) { return Instance()->input.IsMouseReleased(type_); }

		// Texture�֌W�̏���
		// �e�N�X�`���ǂݍ���
		static bool LoadTexture(const char* keyword_, const char* file_name_) { return Instance()->textureManager.LoadTexture(keyword_, file_name_); }
		// �����e�N�X�`���ǂݍ���
		static bool LoadDivTexture(const char* keyword_, const char* file_name_, int div_num_, int x_num_, int y_num_, int div_size_x_, int div_size_y_) 
		{
			return Instance()->textureManager.LoadDivTexture(keyword_, file_name_, div_num_, x_num_, y_num_, div_size_x_, div_size_y_);
		}

		// �e�N�X�`���폜
		static void DeleteTexture(const char* keyword_) { Instance()->textureManager.DeleteTexture(keyword_); }
		// �����e�N�X�`���폜
		static void DeleteDivTexture(const char* keyword_) { Instance()->textureManager.DeleteDivTexture(keyword_); }
		// �e�N�X�`���̑S�폜
		static void DeleteTextureAll() { Instance()->textureManager.DeleteTextureAll(); }
		// ���f���Ǘ�����
		// ���f���ǂݍ���
		static bool LoadModel(const char* keyword_, const char* file_name_) { return Instance()->modelManager.Load(keyword_, file_name_); }
		// ���f���̍폜
		static void DeleteModel(const char* keyword_) { Instance()->modelManager.Delete(keyword_); }
		// ���f���̑S�폜
		static void DeleteModelAll() { Instance()->modelManager.DeleteAll(); }
		// ���f���n���h���擾�p
		static int GetModel(const char* keyword_) { return Instance()->modelManager.GetModel(keyword_); }

	private:
		static Library* Instance()
		{
			static Library instance;
			return &instance;
		}

		Library() :
			graphics(&textureManager, &modelManager),
			input(),
			textureManager(),
			modelManager()
		{
		}
		Library(Library&) = delete;

		// ������
		bool Init();
		void End();
		bool IsLoopFinish();
		void UpdateDevice();

	private:
		Graphics graphics;
		Input input;
		TextureManager textureManager;
		ModelManager modelManager;
		// Sound sound;
	};
}

#endif