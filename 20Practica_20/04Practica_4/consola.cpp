#include "stdafx.h"
#include <windows.h>

// ***************************************************************************************
// FUNCIONES AUXILIARES DE PINTADO
// ***************************************************************************************
void gotoxy(int x, int y)
{
	COORD pos = { static_cast<short>(x/2), static_cast<short>(y/2)};
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);

}

void hidecursor(void) {
	HANDLE hdl;
	hdl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO t;
	t.bVisible = false;
	SetConsoleCursorInfo(hdl, &t);
}

void clear()
{
	system("cls");
}