#pragma once
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include <iostream>
#include "mylib.h"
#include <time.h>
#define PASSWORD "abcdef"
#define ENTER 13
#define BLUE 1
#define WHITE 15
using namespace std;

class mylib
{
public:
	mylib();
	~mylib();
	char* Pwd() {
		char S[40]; int i = 0;
		while ((S[i] = _getch()) != ENTER)
		{
			printf("%c", '*'); i++;
		}
		S[i] = '\0';
		return S;
	}

	int CheckPwd() {
		int dem = 0;
		for (dem = 1; dem <= 3; dem++)
		{
			printf("Password :");
			if (strcmp(Pwd(), PASSWORD) == 0)   return 1;
			else printf("\nPassword sai. Hay nhap lai\n");
		}
		return 0;
	}

	void gotoxy(short x, short y)
	{
		HANDLE hConsoleOutput;
		COORD Cursor_an_Pos = { x,y };
		hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
	}

	int wherex(void)
	{
		HANDLE hConsoleOutput;
		hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
		GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
		return screen_buffer_info.dwCursorPosition.X;
	}

	int wherey(void)
	{
		HANDLE hConsoleOutput;
		hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
		GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
		return screen_buffer_info.dwCursorPosition.Y;
	}
	void clreol() {
		COORD coord;
		DWORD written;
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
		coord.X = info.dwCursorPosition.X;
		coord.Y = info.dwCursorPosition.Y;
		FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ',
			info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
		gotoxy(info.dwCursorPosition.X + 1, info.dwCursorPosition.Y + 1);
	}

	void SetColor(WORD color)
	{
		HANDLE hConsoleOutput;
		hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
		GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

		WORD wAttributes = screen_buffer_info.wAttributes;
		color &= 0x000f;
		wAttributes &= 0xfff0;
		wAttributes |= color;

		SetConsoleTextAttribute(hConsoleOutput, wAttributes);
	}
	void Normal() {
		SetColor(WHITE);
		SetBGColor(0);
	}
	void HighLight() {
		SetColor(15);
		SetBGColor(1);
	}
	void SetBGColor(WORD color)
	{
		HANDLE hConsoleOutput;
		hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
		GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

		WORD wAttributes = screen_buffer_info.wAttributes;
		color &= 0x000f;
		color <<= 4;
		wAttributes &= 0xff0f;
		wAttributes |= color;

		SetConsoleTextAttribute(hConsoleOutput, wAttributes);
	}
};

