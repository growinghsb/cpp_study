#pragma once
#pragma warning(disable: 4996)
#include <conio.h>
#include <iostream>
#include <string>
#include <Windows.h>
#include "Global.h"
class GameBase final
{
public:
	GameBase(void) = default;
	virtual ~GameBase(void) = default;
	void SetConsoleAttribute(void);
	void DrawMap(void);
	bool StartGame(void);
	void ShowGameResult(const bool bGameClear);
	void MoveConsoleCursor(const uint32_t x, const uint32_t y);
	const bool(*GetMap(void))[static_cast<uint8_t>(eMapSize::X)];
private:
	void setConsoleSize(const int32_t cols, const int32_t lines);
	void setConsoleTitle(const std::string& title);
	void removeConsoleCursor(void);
private:
	static const bool MAP_ARR[static_cast<uint8_t>(eMapSize::Y)][static_cast<uint8_t>(eMapSize::X)];
};