#ifndef BASE_SCENE_H_
#define BASE_SCENE_H_

namespace Game
{
	enum class Scene
	{
		Title,
		Game,
		None
	};

	class BaseScene
	{
	public:
		BaseScene() = default;
		virtual ~BaseScene() = default;

	public:
		virtual void Update() = 0;

		virtual void Draw() = 0;

		bool IsEnd()const { return isNextScene; }

		Scene GetNextScene()const { return nextScene; }

	protected:
		Scene nextScene{};
		bool isNextScene{ false };

	};
}
#endif	// !BASE_SCENE_H_