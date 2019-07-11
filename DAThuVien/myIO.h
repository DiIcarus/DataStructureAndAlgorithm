#pragma once
#include<iostream>
#include<string>
#include <conio.h>
using namespace std;
int const ZERO = 48, NINE = 73, A = 65, Z = 90, a = 97, z = 122, Enter = 13, Space = 32, BS = 8, ESC = 27;
class myio
{
public:
	myio();
	~myio();
	int justInNum();
	char * justInChar(bool const mode);
	char * justInString(bool const mode, int leng);
	string outString(char const * listString);
	char * convertString2Char(string s);
	string insertStyleName(int leng);
	string uperCaseAll(string s);
	string rightName(string s);
	void delFirstArray(char *a);
	void delInArray(char *a, int n);
	void delLastArray(char *a);
	char convertLowcase2Uppercase(char c);
	char convertUppercase2Lowcase(char C);
	int char2int(const char cin);
	string inPassWord(int leng);
	string hashPassWord(string s);
	string int2String(int i);
};
