#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include "TextureManager.h"
#include "ModelManager.h"
#include <DxLib.h>
namespace TEngine
{
	class Graphics
	{
	public:
		Graphics(TextureManager* texture_manager_, ModelManager* model_manager_) :
			textureManager(texture_manager_),
			modelManager(model_manager_)
		{
		}

		void StartRendering();
		void FinishRendering();

		void DrawTexture(const char* keyword_, float x, float y, unsigned char alpha = 255, float degree_ = 0.0f, float scale_x_ = 1.0f, float scale_y_ = 1.0f);
		// í«â¡Ç≈ägèkÇ‚Éøílê›íËÇ»Ç«çsÇ§ÇÃÇ‡ÇÊÇ¢

		void DrawDivTesture(const char* keyword_, int div_no, float x, float y, unsigned char alpha_ = 255, float degree_ = 0.0f, float scale_x_ = 1.0f, float scale_y_ = 1.0f);

		void DrawModel(const char* keyword_, VECTOR pos_, VECTOR degree_, VECTOR scale_);

	private:

		void DrawTexture(int handle_, float x_, float y_, unsigned char alpha_, float degree_, float scale_x_, float scale_y_);

	private:
		TextureManager* textureManager;
		ModelManager* modelManager;
	};
}

#endif