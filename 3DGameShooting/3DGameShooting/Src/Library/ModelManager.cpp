#include <DxLib.h>
#include "ModelManager.h"

namespace TEngine
{
	bool ModelManager::Load(const char* keyword_, const char* file_name_)
	{
		// ���łɓǂݍ��܂�Ă��邩�`�F�b�N
		if (models.count(keyword_) > 0)
		{
			return true;
		}

		int handle = MV1LoadModel(file_name_);
		if (handle != -1)
		{
			// �ǂݍ��ݐ���
			models[keyword_] = handle;
			return true;
		}
		// �ǂݍ��ݎ��s
		return false;
	}
	void ModelManager::Delete(const char* keyword_)
	{
		if (models.count(keyword_) == 0)
		{
			return;
		}
		// ���f���̉��
		MV1DeleteModel(models[keyword_]);
		// �v�f�̉��
		models.erase(keyword_);
	}
	void ModelManager::DeleteAll()
	{
		// �S���f���̉��
		for (auto itr : models)
		{
			MV1DeleteModel(itr.second);
		}
		// �S�v�f�̍폜
		models.clear();
	}
	int ModelManager::GetModel(const char* keyword_)
	{
		if (models.count(keyword_) > 0)
		{
			return models[keyword_];
		}

		// �L�[���[�h�����݂��Ȃ� => �ǂݍ��܂�Ă��Ȃ�
		return -1;
	}
}