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
			テクスチャ読み込み関数
				戻り値 :
					読み込み結果 :
						true : 成功
						false : 失敗
				第一引数 :
					登録キーワード
				第二引数 :
					ファイル名(パス込み)
		*/
		bool LoadTexture(const char* kekyword_, const char* file_name_);

		/*
			テクスチャ読み込み関数
				戻り値 :
					読み込み結果 :
						true : 成功
						false : 失敗
				第一引数 :
					登録キーワード
				第二引数 :
					ファイル名(パス込み)
				第三引数 : 
					分割総数
				第四引数 : 
					x軸の分割数
				第五引数 :
					Y軸の分割数
				第六引数 :
					X軸の分割サイズ
				第七引数 :
					Y軸の分割サイズ
		*/
		bool LoadDivTexture(const char* keyword_, const char* file_name_, int div_num_, int x_num_, int y_num_, int div_size_x_, int div_size_y_);
		// テクスチャの削除
		void DeleteTexture(const char* keyword_);
		// 分割テクスチャの削除
		void DeleteDivTexture(const char* keyword_);
		// テクスチャの全削除
		void DeleteTextureAll();
		/**/
		int GetTexture(const char* keyword_);

		int GetDivTexture(const char* keyword_, int div_no_);
	private:
		/*
			unordered_map : 
				mapにあるsort機能を外したmapクラス
				sortを求めない場合はこちらのほうが早くなることが多い
		*/
		std::unordered_map <std::string, int> textures;

		// map<キーワード, グループ内で管理するハンドル>
		std::unordered_map <std::string, std::vector<int>> divTextures;
	};
}

#endif