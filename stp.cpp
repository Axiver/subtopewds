#include <stdlib.h>
#include <Windows.h>

#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0500
#include <windows.h>

class SubBot
{
private:
	INPUT _buffer[1];

public:
	SubBot();
	void KeyUp(char key);
	void KeyDown(char key);
	void KeyClick(char key);
};

SubBot::SubBot()
{
	_buffer->type = INPUT_KEYBOARD;
	_buffer->ki.wScan = 0;
	_buffer->ki.time = 0;
	_buffer->ki.dwExtraInfo = 0;
}

void SubBot::KeyUp(char key)
{
	_buffer->ki.wVk = key;
	_buffer->ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, _buffer, sizeof(INPUT));
}

void SubBot::KeyDown(char key)
{
	_buffer->ki.wVk = key;
	_buffer->ki.dwFlags = 0;
	SendInput(1, _buffer, sizeof(INPUT));
}

void SubBot::KeyClick(char key)
{
	KeyDown(key);
	Sleep(10);
	KeyUp(key);
}

int main(void)
{
	system("start https://www.youtube.com/channel/UC-lHJZR3Gqxm24_Vd_AJ5Yw");
	Sleep(5000); //wait 5000 ms

	SubBot bot;
	int i = 0;

	while (i < 12) {
		if (i < 11) {
			bot.KeyDown(0x09); //Press tab key 11 times
			bot.KeyUp(0x09);
		}
		else {
			bot.KeyDown(0x0D); //Click subscribe lol
			bot.KeyUp(0x0D);
		}
		i++;
	}
}
