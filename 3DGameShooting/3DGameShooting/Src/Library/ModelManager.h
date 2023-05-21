#ifndef MODEL_MANAGER_H_
#define MODEL_MANAGER_H_

#include <unordered_map>
#include <string>

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
			3Dモデルの種類 => Fbx, Obj, MMD, XFile
			今回はdxlibを使用しているのでMV1
		*/
		std::unordered_map<std::string, int> models;

	};
}



#endif
