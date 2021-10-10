#pragma once
#include <ctime>
#include <chrono>
#include <vector>
#include "GameBase.h"
class GameAlgorithm final
{
public:
	GameAlgorithm(void);
	virtual ~GameAlgorithm(void) = default;
	bool StartGame(void);
private:
	void initGame(void);
	void moveSnake(const uint8_t moveKey);
	void removeSnakeTail(void);
	void creatFood(void);
	void checkFood(void);
	bool isGameClear(void);
	bool isSnakeCollision(void);
	bool isWallCollision(void);
private:
	typedef struct SnakePos
	{
		int32_t X;
		int32_t Y;
	}SnakePos_t;
	SnakePos_t mSnakePos;
	std::vector<SnakePos_t> mSnake;
	int32_t mSnakeLength;
	int32_t mSnakeTmpX;
	int32_t mSnakeTmpY;
	bool mbFoodExist;
	int32_t mFoodX;
	int32_t mFoodY;
	int32_t mSpeed_us;
	int32_t mScore;
	GameBase gameBase;
	const bool(*MAP_ARR)[static_cast<uint8_t>(eMapSize::X)];
};
