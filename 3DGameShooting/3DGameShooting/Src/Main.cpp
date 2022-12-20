#include "Library/Library.h"
#include "Scene/SceneControl.h"

//const int window_width = 800;
//const int window_height = 600;
//const int color_bit = 32;

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (TEngine::Library::Initialized() == false)
	{
		return 0;
	}

	/*ChangeWindowMode(true);
	SetGraphMode(window_width, window_height, color_bit);*/

	//if (DxLib_Init() == -1)		// �c�w���C�u��������������
	//{
	//	return -1;			// �G���[���N�����璼���ɏI��
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
	//DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}
