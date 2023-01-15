#ifndef SCORE_H_
#define SCORE_H_

namespace Game
{
	// スコア表示
	class Score
	{
	public:
		Score() = default;
		~Score() = default;
	public:
		void Draw();
		void SetScore(int score_) { score = score_; }
		void AddScore() { ++score; }
		void AddScore(int addScore_) { score += addScore_; }
		void SubScore(int subScore_) { score -= subScore_; }
	private:
		int score{ 0 };
	};
}

#endif // !SCORE_H_
