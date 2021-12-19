/*
	���ڹ� ����

	1. ���Ͽ��� �������� ������ �о�´�.
	   �������� �������� �������� ��, �� ������ �ִ�.

	2. �������� #, P, O, o �� ǥ�� �Ǿ� �ִ�.
	   # �� ��, P�� �÷��̾�, O �� o ��
	   ��ġ�ؾ� �ϴ� �������̴�.

	3. �÷��̾�� o �� O �� �Űܾ� �ϸ�,
	   �����δ� ������ �� ����.
	   o �� O �� �ű�� 0���� ���� �Ǹ�,
	   �ʿ� ��� O �� 0���� ����Ǹ�
	   ���� ���������� �Ѿ��.

	4. �÷��̾�� w s a d �� �����¿�
	   �����̰� �ȴ�.

	5. �� ������ Ƚ���� üũ�Ѵ�.
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
