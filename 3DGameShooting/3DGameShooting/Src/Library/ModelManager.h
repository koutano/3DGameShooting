#ifndef MODEL_MANAGER_H_
#define MODEL_MANAGER_H_

#include <unordered_map>

namespace TEngine
{
	class ModelManager
	{
	public:
		bool Load(const char* keyword_, const char* file_name_);

		void Delete(const char* keyword_);
		void DeleteAll();
		int GetModel(const char* keyword_);
	private:
		/*
			3D���f���̎�� => Fbx, Obj, MMD, XFile
			�����dxlib���g�p���Ă���̂�MV1
		*/
		std::unordered_map<std::string, int> models;

	};
}



#endif