#ifndef OBJ_BASE_H_
#define OBJ_BASE_H_

#include <DxLib.h>

namespace Game
{
	class ObjBase
	{
	public:
		ObjBase(VECTOR pos_,VECTOR scale_, VECTOR degreeAngle_) :
			pos(pos_),
			scale(scale_),
			degreeAngle(degreeAngle_)
		{
		}
		virtual ~ObjBase() = default;
		virtual void Update() = 0;
		virtual void Draw() = 0;
		
	public:
		VECTOR GetPos()const { return pos; }
		VECTOR GetScale()const { return scale; }
		VECTOR GetDegreeAngle()const { return degreeAngle; }
		void SetPos(VECTOR pos_) { pos = pos_; }
	protected:
		VECTOR pos{};
		VECTOR scale{};
		VECTOR degreeAngle{};
	};
}

#endif // !OBJ_BASE_H_
