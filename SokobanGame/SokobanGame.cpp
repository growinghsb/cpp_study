/*
	소코반 게임

	1. 파일에서 스테이지 정보를 읽어온다.
	   스테이지 정보에는 스테이지 명, 맵 정보가 있다.

	2. 맵정보는 #, P, O, o 가 표시 되어 있다.
	   # 은 벽, P는 플레이어, O 는 o 가
	   위치해야 하는 목적지이다.

	3. 플레이어는 o 를 O 로 옮겨야 하며,
	   벽으로는 움직일 수 없다.
	   o 를 O 로 옮기면 0으로 변경 되며,
	   맵에 모든 O 가 0으로 변경되면
	   다음 스테이지로 넘어간다.

	4. 플레이어는 w s a d 로 상하좌우
	   움직이게 된다.

	5. 총 움직인 횟수를 체크한다.
*/

#include<iostream>
#include<fstream> 
#include<conio.h>

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;

static char stageStream[512];
static int stageMapCount;
static int stageWidth;
static int playerLocation;

int readStage(const char* resource);
void printStage();
bool isMove(const int targetPoint, const int moveCount);
bool isObstacle(const int currnetLocation);
bool isBallMove(const int currentLocation, const int moveCount);
bool isSapce(const int currentLocation);
bool isHole(const int currentLocation);
bool isGoal(const int currentLocation, const int moveCount);
void swap(char& ch1, char& ch2);

int main()
{
	stageMapCount = readStage("C:/Users/pon05/SokobanMap/stage2.txt");

	while (true)
	{
		system("cls");
		printStage();

		cout << endl;

 	char inputDirection = _getch();

		switch (inputDirection)
		{
		case 'w':
			if (isMove(playerLocation - stageWidth, -stageWidth))
			{

				swap(stageStream[playerLocation], stageStream[playerLocation - stageWidth]);
				playerLocation -= stageWidth;
			}
			break;

		case 's':
			if (isMove(playerLocation + stageWidth, stageWidth))
			{
				swap(stageStream[playerLocation], stageStream[playerLocation + stageWidth]);
				playerLocation += stageWidth;
			}
			break;

		case 'a':
			if (isMove(playerLocation - 1, -1))
			{
				swap(stageStream[playerLocation], stageStream[playerLocation - 1]);
				playerLocation -= 1;
			}
			break;

		case 'd':
			if (isMove(playerLocation + 1, 1))
			{
				swap(stageStream[playerLocation], stageStream[playerLocation + 1]);
				playerLocation += 1;
			}
			break;
		}
	}

	return 0;
}

int readStage(const char* resource)
{
	ifstream fin;

	fin.open(resource);

	int stageNameCount = 0;
	int mapInfoCount = 0;
	int newLineCount = 0;
	char getWCh;

	while (true)
	{
		fin.get(getWCh);

		if (fin.fail() || '\n' == getWCh)
		{
			break;
		}

		stageStream[stageNameCount++] = getWCh;
	}

	mapInfoCount = stageNameCount;

	while (true)
	{
		fin.get(getWCh);

		if (fin.fail())
		{
			break;
		}

		if ('\n' == getWCh)
		{
			++newLineCount;
		}

		if ('P' == getWCh)
		{
			playerLocation = mapInfoCount;
		}

		stageStream[mapInfoCount++] = getWCh;
	}
	fin.close();

	stageWidth = (mapInfoCount - stageNameCount) / newLineCount;

	return mapInfoCount;
}

void printStage()
{
	for (int i = 0; i < stageMapCount; ++i)
	{
		cout << *(stageStream + i);
	}
}

bool isMove(const int targetPoint, const int moveCount)
{
	if (isObstacle(targetPoint))
	{
		return false;
	}

	if (isBallMove(targetPoint, moveCount))
	{
		return true;
	}

	if (isSapce(targetPoint))
	{
		return true;
	}

	if (isGoal(targetPoint, moveCount)) 
	{
		return false;
	}

	if (isHole(targetPoint)) 
	{
		return false;
	}

	return false;
}

bool isObstacle(const int currentLocation)
{
	if (0 > currentLocation
		|| stageMapCount <= currentLocation
		|| '#' == stageStream[currentLocation])
	{
		return true;
	}
	return false;
}

bool isBallMove(const int currentLocation, const int moveCount)
{
	if ('o' == stageStream[currentLocation])
	{
		int moveLocation = currentLocation + (moveCount);

		if (0 > moveLocation
			|| stageMapCount <= moveLocation
			|| '#' == stageStream[moveLocation]
			|| 'X' == stageStream[moveLocation])
		{
			return false;
		}

		if ('O' == stageStream[moveLocation])
		{
			stageStream[moveLocation] = 'X';
			stageStream[currentLocation] = ' ';

			return true;
		}

		if (' ' == stageStream[moveLocation])
		{
			stageStream[moveLocation] = 'o';
			stageStream[currentLocation] = ' ';

			return true;
		}
	}

	return false;
}

bool isSapce(const int currentLocation)
{
	if (' ' == stageStream[currentLocation])
	{
		return true;
	}
	return false;
}

bool isGoal(const int currentLocation, const int moveCount)
{
	if ('X' == stageStream[currentLocation])
	{
		int moveX = currentLocation + (moveCount);

		if ('O' == stageStream[moveX])
		{
			swap(stageStream[currentLocation], stageStream[moveX]);
			return isHole(currentLocation);
		}
	}
	return false;
}

bool isHole(const int currentLocation)
{
	if ('O' == stageStream[currentLocation])
	{
		stageStream[playerLocation] = ' ';
		stageStream[currentLocation] = '@';
		
		playerLocation = currentLocation;

		return true;
	}

	return false;
}

void swap(char& ch1, char& ch2)
{
	char tmp = ch1;
	ch1 = ch2;
	ch2 = tmp;
}
