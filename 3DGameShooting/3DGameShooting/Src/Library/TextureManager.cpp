#include <DxLib.h>
#include "TextureManager.h"

namespace TEngine
{
	bool TextureManager::LoadTexture(const char* keyword_, const char* file_name_)
	{
		// 既に登録済みのtextureとして扱う
		if (textures.count(keyword_) > 0)
		{
			return true;
		}

		int handle = LoadGraph(file_name_);
		if (handle < 0)
		{
			// 読み込み失敗
			return false;
		}

		textures[keyword_] = handle;

		// 読み込み成功
		return true;
	}

	bool TextureManager::LoadDivTexture(const char* keyword_, const char* file_name_, int div_num_, int x_num_, int y_num_, int div_size_x_, int div_size_y_)
	{
		if (divTextures.count(keyword_) > 0)
		{
			// すでにキーワードが存在するので読み込み官僚とする
			return true;
		}
		// 1024 => 勝手な予測による分割の最大数
		int handles[1024];

		int result = LoadDivGraph(file_name_, div_num_, x_num_, y_num_, div_size_x_, div_size_y_, handles);

		if (result != 0)
		{
			// 読み込み失敗
			return false;
		}

		// ハンドルの保存
		for (int i = 0; i < div_num_; i++)
		{
			divTextures[keyword_].push_back(handles[i]);

		}
		// 読み込み成功
		return true;
	}


	void TextureManager::DeleteTexture(const char* keyword_)
	{
		if (textures.count(keyword_) > 0)
		{
			// テクスチャを削除
			DeleteGraph(textures[keyword_]);
			// 配列からも情報を削除する
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
		// キーワードがあればその値を返す
		if (textures.count(keyword_) > 0)
		{
			return textures[keyword_];
		}

		return -1;
	}

	int TextureManager::GetDivTexture(const char* keyword_, int div_no_)
	{
		// キーワードチェック
		if (divTextures.count(keyword_) == 0)
		{
			return -1;
		}

		// div_no_の不正チェック
		if (div_no_ < 0 || div_no_ >= divTextures[keyword_].size())
		{
			return -1;
		}

		return divTextures[keyword_][div_no_];
	}

}