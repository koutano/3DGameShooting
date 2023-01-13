#include "ShockWave.h"
#include "../../Library/Library.h"
#define _USE_MATH_DEFINES
#include <math.h>

namespace Game
{
	ShockWave::ShockWave(VECTOR pos_) :
		ObjBase(pos_,VGet(1,1,1),VGet(0,180,0))
	{
	}

	void ShockWave::Update()
	{
		
	}

	void ShockWave::Draw()
	{
		TEngine::Library::DrawModel("enemy03", pos, degreeAngle, scale);
	}

}
