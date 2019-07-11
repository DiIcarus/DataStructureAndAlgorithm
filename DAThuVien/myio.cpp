#include "myIO.h"
#include<iostream>
using namespace std;


myio::myio()
{
}


myio::~myio()
{
}
int myio::char2int(const char cin) {
	return (int)cin - 48;
}
int	myio::justInNum() {
	char temp;
	int num = 0;
	do {
		temp = _getch();
		fflush(stdin);
		if (temp >= ZERO && temp <= NINE || temp == Enter) {
			num = num * 10 + (int)temp - 48;
		}
		else {
			cout << "Chi nhap so, moi nhap lai!!";
		}
	} while (temp != Enter);
	return char2int(temp);
}
char * myio::justInChar(bool const mode) {
	char character, *list1character;
	bool loop = true;
	do {
		character = _getch();
		fflush(stdin);
		if (mode) {
			if (character == Enter || character == Space) {
				loop = false;
			}
		}
		if ((character >= a && character <= z) || (character >= A && character <= Z)) {
			loop = false;
		}
		else {
			cout << "Chi nhap chu cai, moi nhap lai!!";
		}
	} while (loop);
	cout << character;
	list1character = &character;
	return list1character;
}
char * myio::justInString(bool const mode, int leng) {
	switch (mode) {
	case 0:
		cout << "\nHam chi nhap 1 ky tu abc:";
		return justInChar(0);
		break;
	case 1:/*
		cout << "\nHam nhap chuoi:";
		cout << "Nhap do dai chuoi:";
		cin >> leng;*/
		fflush(stdin);
		bool loop = true;
		char *string, temp;
		string = new char[leng];
		for (int i = 0; i < leng; i++) {
			string[i] = 0;
		}
		int i = 0;
		do {
			temp = _getch();
			fflush(stdin);
			string[i] = temp;
			cout << string[i];
			i++;
		} while (temp != Enter && i < leng);
		i = 0;
		while (string[i] && i < leng) {
			cout << string[leng];
			i++;
		}
		return string;
		break;
	}
}
char * myio::convertString2Char(string s) {
	char *c = new char[(s.size() + 1)];
	std::copy(s.begin(), s.end(), c);
	c[s.size()] = '\0';
	return c;
}
char myio::convertLowcase2Uppercase(char c) {
	return c + (A - a);
}
char myio::convertUppercase2Lowcase(char C) {

	return C - (A - a);
}
string myio::outString(char const * listString) {
	return string(listString);
}
string myio::uperCaseAll(string s) {
	char*c = convertString2Char(s);
	int i = 0;
	while (c[i] != '\0') {
		if (a <= c[i] && c[i] <= z) {
			c[i] = c[i] & '_';
		}
		i++;
	}
	s = string(c);
	delete[]c;
	return s;
}
void myio::delFirstArray(char *a) {
	int i = 0;
	while (a[i] != '\0') {
		a[i] = a[i + 1];
		i++;
	}
}
void myio::delInArray(char *a, int n) {
	int i = n;
	while (a[i] != '\0') {
		a[i] = a[i + 1];
		i++;
	}
}
void myio::delLastArray(char *a) {
	int i = 0;
	while (a[i] != '\0') {
		i++;
	}
	a[i - 1] = '\0';
}
string myio::rightName(string s) {
	char*c = convertString2Char(s);
	int i = 0;
	while (c[i] == Space) {
		delFirstArray(c);
	}
	while (c[i] != '\0') {
		if (A <= c[i] && c[i] <= Z) {
			c[i] = convertUppercase2Lowcase(c[i]);
		}
		i++;
	}
	while (c[i - 1] == Space && c[i] == '\0') {
		delLastArray(c);
		i--;
	}
	i = 0;
	while (c[i] != '\0') {
		if (c[i - 1] == Space && a <= c[i] && c[i] <= z) {
			c[i] = convertLowcase2Uppercase(c[i]);
		}
		if (c[i] == Space && c[i + 1] == Space) {
			delInArray(c, i);
			continue;
		}
		i++;
	}
	c[0] = convertLowcase2Uppercase(c[0]);
	s = string(c);
	delete[]c;
	return s;
}
string myio::insertStyleName(int leng) {
	fflush(stdin);
	bool loop = true;
	char *string, temp;
	string = new char[leng];
	for (int i = 0; i < leng; i++) {
		string[i] = 0;
	}
	string[leng] = '\0';
	int i = 0;
	do {
		temp = _getch();
		fflush(stdin);
		cout << temp;
		if ((A <= temp && temp <= Z) || (a <= temp && temp <= z) || temp == Space || temp == Enter || temp == BS) {
			string[i] = temp;
			if (temp == BS) {
				delLastArray(string);
				i--;
				continue;
			}
			i++;
			if (temp == Enter) {
				break;
			}
		}
		else {
			cout << "\nYeu cau chi nhap ky tu ABC!!";
			continue;
		}
	} while (temp != Enter && i < leng);
	return rightName(string);
}
string myio::hashPassWord(string s) {
	string add = "PTITHCM";
	s += add;
	char *c = convertString2Char(s);
	int i = 0;
	while (c[i] != '\0') {
		c[i] = (c[i] & 'a') | 'b';
		cout << c[i];
	}
	s = string(c);
	delete c;
	return s;
}
string myio::inPassWord(int leng) {
	cin >> leng;
	fflush(stdin);
	bool loop = true;
	char *string, temp;
	string = new char[leng];
	for (int i = 0; i < leng; i++) {
		string[i] = 0;
	}
	int i = 0;
	do {
		temp = _getch();
		fflush(stdin);
		string[i] = temp;
		cout << "*";
		i++;
	} while (temp != Enter && i < leng);
	return hashPassWord(string);
}
string myio::int2String(int i) {
	int dem = 0,temp =i;
	while (temp > 0) {
		dem++;
		temp = (temp - temp % 10) / 10;
	}
	char *c = new char[dem+1];
	char *c2 = new char[dem+1];
	c[dem] = '\0';
	c2[dem] = '\0';
	temp = i;
	for (int i = 0; i < dem;i++) {
		c[i] = temp % 10+48;
		temp = (temp - temp % 10) / 10;
	}
	for (int i = 0; i < dem;i++) {
		c2[i] = c[dem -i-1];
	}
	free(c);
	return string(c2);
}