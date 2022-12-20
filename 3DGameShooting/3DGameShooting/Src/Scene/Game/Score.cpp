#include "Score.h"
#include <DxLib.h>

namespace Game
{
	void Score::Draw()
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", score);
	}
}
