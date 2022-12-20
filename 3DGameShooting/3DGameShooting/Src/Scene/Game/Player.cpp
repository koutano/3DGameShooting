#include "Player.h"
#include "../../Library/Library.h"
#define _USE_MATH_DEFINES
#include <math.h>



namespace Game
{
	Player::Player(BulletManager* bullet_manager_) :
		ObjBase(VGet(0.0f, 0.0f, 0.0f), VGet(0.5f, 0.5f, 0.5f), VGet(0.0f, 0.0f, 0.0f)),
		bulletManager(bullet_manager_)
	{
		TEngine::Library::LoadModel("player", "Res/Player.mv1");
	}

	Player::~Player()
	{
		TEngine::Library::DeleteModel("player");
	}

	void Player::Update()
	{

		if (TEngine::Library::IsKeyPushed(KEY_INPUT_P))
		{
			bulletManager->CreateBullet(this);
		}

		auto Move = [this](int key_, float degreeAngle_)
		{
			if (TEngine::Library::IsKeyHeld(key_))
			{
				pos.x += sinf(degreeAngle_ / 180 * M_PI) * speed;
				pos.y += cosf(degreeAngle_ / 180 * M_PI) * speed;
			}
		};

		Move(KEY_INPUT_A, degreeAngle.y - 90);
		Move(KEY_INPUT_D, degreeAngle.y + 90);
		Move(KEY_INPUT_W, degreeAngle.y);
		Move(KEY_INPUT_S, degreeAngle.y + 180);

		MoveArea();

	}

	void Player::Draw()
	{
		TEngine::Library::DrawModel("player", pos, degreeAngle, scale);
	}

	void Player::MoveArea()
	{
		if (pos.x > moveWidthArea)
		{
			pos.x = moveWidthArea;
		}
		else if (pos.x < -moveWidthArea)
		{
			pos.x = -moveWidthArea;
		}

		if (pos.y > moveHeightArea)
		{
			pos.y = moveHeightArea;
		}
		else if (pos.y < -moveHeightArea)
		{
			pos.y = -moveHeightArea;
		}
	}
}
