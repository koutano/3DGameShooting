#ifndef TEXTURE_MANAGER_H_
#define TEXTURE_MANAGER_H_

#include <unordered_map>
#include <vector>
#include <string>
namespace TEngine
{
	class TextureManager
	{
	public:
		TextureManager() : 
		textures()
		{
		}
		

		/*
			�e�N�X�`���ǂݍ��݊֐�
				�߂�l :
					�ǂݍ��݌��� :
						true : ����
						false : ���s
				������ :
					�o�^�L�[���[�h
				������ :
					�t�@�C����(�p�X����)
		*/
		bool LoadTexture(const char* kekyword_, const char* file_name_);

		/*
			�e�N�X�`���ǂݍ��݊֐�
				�߂�l :
					�ǂݍ��݌��� :
						true : ����
						false : ���s
				������ :
					�o�^�L�[���[�h
				������ :
					�t�@�C����(�p�X����)
				��O���� : 
					��������
				��l���� : 
					x���̕�����
				��܈��� :
					Y���̕�����
				��Z���� :
					X���̕����T�C�Y
				�掵���� :
					Y���̕����T�C�Y
		*/
		bool LoadDivTexture(const char* keyword_, const char* file_name_, int div_num_, int x_num_, int y_num_, int div_size_x_, int div_size_y_);
		// �e�N�X�`���̍폜
		void DeleteTexture(const char* keyword_);
		// �����e�N�X�`���̍폜
		void DeleteDivTexture(const char* keyword_);
		// �e�N�X�`���̑S�폜
		void DeleteTextureAll();
		/**/
		int GetTexture(const char* keyword_);

		int GetDivTexture(const char* keyword_, int div_no_);
	private:
		/*
			unordered_map : 
				map�ɂ���sort�@�\���O����map�N���X
				sort�����߂Ȃ��ꍇ�͂�����̂ق��������Ȃ邱�Ƃ�����
		*/
		std::unordered_map <std::string, int> textures;

		// map<�L�[���[�h, �O���[�v���ŊǗ�����n���h��>
		std::unordered_map <std::string, std::vector<int>> divTextures;
	};
}

#endif