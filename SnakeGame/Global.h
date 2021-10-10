#pragma once
#include <cstdint>
enum class eAsciiKey
{
	EXTENDED_0x00 = 0,
	ESC = 27,
	SPACE_BAR = 32,
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80,
	EXTENDED_0xE0 = 224
};
enum class eMapSize
{
	X = 40,
	Y = 30
};
enum class eFirstSnakePos
{
	X = static_cast<uint8_t>(eMapSize::X) / 2,
	Y = static_cast<uint8_t>(eMapSize::Y) / 2
};
