#include <DxLib.h>
#include "TextureManager.h"

namespace TEngine
{
	bool TextureManager::LoadTexture(const char* keyword_, const char* file_name_)
	{
		// ���ɓo�^�ς݂�texture�Ƃ��Ĉ���
		if (textures.count(keyword_) > 0)
		{
			return true;
		}

		int handle = LoadGraph(file_name_);
		if (handle < 0)
		{
			// �ǂݍ��ݎ��s
			return false;
		}

		textures[keyword_] = handle;

		// �ǂݍ��ݐ���
		return true;
	}

	bool TextureManager::LoadDivTexture(const char* keyword_, const char* file_name_, int div_num_, int x_num_, int y_num_, int div_size_x_, int div_size_y_)
	{
		if (divTextures.count(keyword_) > 0)
		{
			// ���łɃL�[���[�h�����݂���̂œǂݍ��݊����Ƃ���
			return true;
		}
		// 1024 => ����ȗ\���ɂ�镪���̍ő吔
		int handles[1024];

		int result = LoadDivGraph(file_name_, div_num_, x_num_, y_num_, div_size_x_, div_size_y_, handles);

		if (result != 0)
		{
			// �ǂݍ��ݎ��s
			return false;
		}

		// �n���h���̕ۑ�
		for (int i = 0; i < div_num_; i++)
		{
			divTextures[keyword_].push_back(handles[i]);

		}
		// �ǂݍ��ݐ���
		return true;
	}


	void TextureManager::DeleteTexture(const char* keyword_)
	{
		if (textures.count(keyword_) > 0)
		{
			// �e�N�X�`�����폜
			DeleteGraph(textures[keyword_]);
			// �z�񂩂�������폜����
			textures.erase(keyword_);
		}
	}

	void TextureManager::DeleteDivTexture(const char* keyword_)
	{
		if (divTextures.count(keyword_) == 0)
		{
			return;
		}
		for (int& handle : divTextures[keyword_])
		{
			DeleteGraph(handle);
		}
		divTextures.erase(keyword_);
	}


	void TextureManager::DeleteTextureAll()
	{
		for (auto itr : textures)
		{
			DeleteGraph(itr.second);
		}
		textures.clear();

		for (auto itr : divTextures)
		{
			for (int& handle : itr.second)
			{
				DeleteGraph(handle);
			}
		}
		divTextures.clear();
	}

	int TextureManager::GetTexture(const char* keyword_)
	{
		// �L�[���[�h������΂��̒l��Ԃ�
		if (textures.count(keyword_) > 0)
		{
			return textures[keyword_];
		}

		return -1;
	}

	int TextureManager::GetDivTexture(const char* keyword_, int div_no_)
	{
		// �L�[���[�h�`�F�b�N
		if (divTextures.count(keyword_) == 0)
		{
			return -1;
		}

		// div_no_�̕s���`�F�b�N
		if (div_no_ < 0 || div_no_ >= divTextures[keyword_].size())
		{
			return -1;
		}

		return divTextures[keyword_][div_no_];
	}

}