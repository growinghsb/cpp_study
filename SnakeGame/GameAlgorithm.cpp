#include "GameAlgorithm.h"
/////////////////////////////////////////////////////////////////////////////////////////////////
// Public Method
GameAlgorithm::GameAlgorithm(void)
	: mSnakePos{ static_cast<uint8_t>(eFirstSnakePos::X), static_cast<uint8_t>(eFirstSnakePos::Y) }
	, mSnakeLength(1)
	, mSnakeTmpX(0)
	, mSnakeTmpY(0)
	, mbFoodExist(false)
	, mFoodX(0)
	, mFoodY(0)
	, mSpeed_us(100000)
	, mScore(0)
	, MAP_ARR(gameBase.GetMap())
{
	mSnake.reserve(static_cast<uint8_t>(eMapSize::X)* static_cast<uint8_t>(eMapSize::Y));
}
bool GameAlgorithm::StartGame(void)
{
	uint8_t key = NULL;
	uint8_t moveKey = static_cast<uint8_t>(eAsciiKey::LEFT);
	std::chrono::system_clock::time_point waitTime;
	initGame();
	while (true)
	{
		waitTime = std::chrono::system_clock::now() + std::chrono::microseconds(mSpeed_us);
		while (std::chrono::system_clock::now() < waitTime)
		{
			if (_kbhit())
			{
				key = _getch();
				if (key == static_cast<uint8_t>(eAsciiKey::EXTENDED_0x00) || key == static_cast<uint8_t>(eAsciiKey::EXTENDED_0xE0))
				{
					key = _getch();
				}
			}
		}
		if ((key == static_cast<uint8_t>(eAsciiKey::LEFT) && moveKey != static_cast<uint8_t>(eAsciiKey::RIGHT)) || (key == static_cast<uint8_t>(eAsciiKey::RIGHT) && moveKey != static_cast<uint8_t>(eAsciiKey::LEFT)) || (key == static_cast<uint8_t>(eAsciiKey::UP) && moveKey != static_cast<uint8_t>(eAsciiKey::DOWN)) || (key == static_cast<uint8_t>(eAsciiKey::DOWN) && moveKey != static_cast<uint8_t>(eAsciiKey::UP)))
		{
			moveKey = key;
		}
		if (mbFoodExist == true)
		{
			removeSnakeTail();
		}
		else
		{
			creatFood();
		}
		moveSnake(moveKey);
		checkFood();
		if (isGameClear() == true)
		{
			return true;
		}
		if (isSnakeCollision() == true || isWallCollision() == true)
		{
			return false;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////
// Private Method
void GameAlgorithm::initGame(void)
{
	mSnake.push_back(mSnakePos);
	gameBase.MoveConsoleCursor((static_cast<uint8_t>(eMapSize::X) / 2) - 5, (static_cast<uint8_t>(eMapSize::Y) / 2) - 2);
	std::cout << " ";
	gameBase.MoveConsoleCursor((static_cast<uint8_t>(eMapSize::X) / 2) - 5, (static_cast<uint8_t>(eMapSize::Y) / 2) - 1);
	std::cout << " ";
	gameBase.MoveConsoleCursor(static_cast<uint8_t>(eFirstSnakePos::X), static_cast<uint8_t>(eFirstSnakePos::Y));
	std::cout << "¡Ý";
	gameBase.MoveConsoleCursor(0, static_cast<uint8_t>(eMapSize::Y));
	std::cout << "SCORE = 0";
	creatFood();
}
void GameAlgorithm::moveSnake(const uint8_t moveKey)
{
	mSnakeTmpX = mSnake.back().X;
	mSnakeTmpY = mSnake.back().Y;
	if (mSnakeLength != 1)
	{
		for (auto itSnake = mSnake.rbegin(); itSnake != mSnake.rend() - 1; itSnake++)
		{
			(*itSnake).X = (*(itSnake + 1)).X;
			(*itSnake).Y = (*(itSnake + 1)).Y;
		}
	}
	switch (moveKey)
	{
	case static_cast<uint8_t>(eAsciiKey::LEFT):
		(mSnake.front().X)--;
		break;
	case static_cast<uint8_t>(eAsciiKey::RIGHT):
		(mSnake.front().X)++;
		break;
	case static_cast<uint8_t>(eAsciiKey::UP):
		(mSnake.front().Y)--;
		break;
	case static_cast<uint8_t>(eAsciiKey::DOWN):
		(mSnake.front().Y)++;
		break;
	default:
		break;
	}
	gameBase.MoveConsoleCursor(mSnake.front().X, mSnake.front().Y);
	std::cout << "¡Ý";
}
void GameAlgorithm::removeSnakeTail(void)
{
	gameBase.MoveConsoleCursor(mSnake.back().X, mSnake.back().Y);
	std::cout << " ";
}
void GameAlgorithm::creatFood(void)
{
	bool bSamePos;
	srand(static_cast<unsigned int>(time(NULL)));
	while (true)
	{
		bSamePos = false;
		mFoodX = rand() % (static_cast<uint8_t>(eMapSize::X) - 2) + 1;
		mFoodY = rand() % (static_cast<uint8_t>(eMapSize::Y) - 2) + 1;
		for (auto itSnake = mSnake.begin(); itSnake != mSnake.end(); itSnake++)
		{
			if ((*itSnake).X == mFoodX && (*itSnake).Y == mFoodY)
			{
				bSamePos = true;
			}
		}
		if (bSamePos == false)
		{
			break;
		}
	}
	mbFoodExist = true;
	gameBase.MoveConsoleCursor(mFoodX, mFoodY);
	std::cout << "¡Ú";
}
void GameAlgorithm::checkFood(void)
{
	if (mSnake.front().X == mFoodX && mSnake.front().Y == mFoodY)
	{
		mSnakePos.X = mSnakeTmpX;
		mSnakePos.Y = mSnakeTmpY;
		mSnake.push_back(mSnakePos);
		mbFoodExist = false;
		mSnakeLength++;
		mScore += 10;
		if (mScore % 50 == 0 && mSpeed_us != 100000)
		{
			mSpeed_us -= 10000;
		}
		gameBase.MoveConsoleCursor(4, static_cast<uint8_t>(eMapSize::Y));
		std::cout << mScore;
	}
}
bool GameAlgorithm::isGameClear(void)
{
	return mSnakeLength == ((static_cast<uint8_t>(eMapSize::Y) - 1) * (static_cast<uint8_t>(eMapSize::X) - 1)) ? true : false;
}
bool GameAlgorithm::isSnakeCollision(void)
{
	for (auto itSnake = mSnake.begin() + 1; itSnake != mSnake.end(); itSnake++)
	{
		if (mSnake.front().X == (*itSnake).X && mSnake.front().Y == (*itSnake).Y)
		{
			return true;
		}
	}
	return false;
}
bool GameAlgorithm::isWallCollision(void)
{
	return MAP_ARR[mSnake.front().Y][mSnake.front().X] ? true : false;
}
