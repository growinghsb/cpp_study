#include "GameBase.h"
#include "Global.h"
int main(void)
{
	uint8_t key;
	GameBase gameBase;
	gameBase.SetConsoleAttribute();
	gameBase.DrawMap();
	while (true)
	{
		key = _getch();
		switch (key)
		{
		case static_cast<uint8_t>(eAsciiKey::EXTENDED_0x00): // intentional fall through
		case static_cast<uint8_t>(eAsciiKey::EXTENDED_0xE0):
			key = _getch();
			break;
		case static_cast<uint8_t>(eAsciiKey::SPACE_BAR):
			gameBase.ShowGameResult(gameBase.StartGame());
			gameBase.DrawMap();
			break;
		case static_cast<uint8_t>(eAsciiKey::ESC):
			return 0;
		default:
			break;
		}
	}
	return 0;
}
