#include "ShockWave.h"
#include "../../Library/Library.h"

namespace Game
{
	ShockWave::ShockWave(ObjBase* obj_) :
		ObjBase(VGet(0, 0, 0), VGet(1, 1, 1), VGet(0, 180, 0))
	{
		pos = obj_->GetPos();
		degreeAngle = obj_->GetDegreeAngle();
	}

	void ShockWave::Update()
	{
		if (scale.x >= MaxRange &&
			scale.y >= MaxRange &&
			scale.z >= MaxRange)
		{
			endFlag = true;
			return;
		}
		scale.x++;
		scale.y++;
		scale.z++;
		
	}

	void ShockWave::Draw()
	{
		TEngine::Library::DrawModel("shockwave", pos, degreeAngle, scale);
	}

}
