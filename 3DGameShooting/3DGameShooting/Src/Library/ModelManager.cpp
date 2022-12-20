#include <DxLib.h>
#include "ModelManager.h"

namespace TEngine
{
	bool ModelManager::Load(const char* keyword_, const char* file_name_)
	{
		// すでに読み込まれているかチェック
		if (models.count(keyword_) > 0)
		{
			return true;
		}

		int handle = MV1LoadModel(file_name_);
		if (handle != -1)
		{
			// 読み込み成功
			models[keyword_] = handle;
			return true;
		}
		// 読み込み失敗
		return false;
	}
	void ModelManager::Delete(const char* keyword_)
	{
		if (models.count(keyword_) == 0)
		{
			return;
		}
		// モデルの解放
		MV1DeleteModel(models[keyword_]);
		// 要素の解放
		models.erase(keyword_);
	}
	void ModelManager::DeleteAll()
	{
		// 全モデルの解放
		for (auto itr : models)
		{
			MV1DeleteModel(itr.second);
		}
		// 全要素の削除
		models.clear();
	}
	int ModelManager::GetModel(const char* keyword_)
	{
		if (models.count(keyword_) > 0)
		{
			return models[keyword_];
		}

		// キーワードが存在しない => 読み込まれていない
		return -1;
	}
}