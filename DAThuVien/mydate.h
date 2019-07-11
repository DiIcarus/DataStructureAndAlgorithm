#pragma once
#include "myIO.h"
#include<iostream>
using namespace std;
class mydate
{
	struct Time {
		char Sec[3], Min[3], Hour[3];
	};
	struct Date {
		char Day[3], Month[3], Year[5];
	};
public:
	mydate();
	~mydate();
	/*unsigned int convertNumString2Int(string s);
	Time insertTime();
	Date insertDate();
	Time initTime();
	Date initDate();
	Time subTime(Time t1, Time t2);
	Date subDate(Date d1, Date d2);
	Time cmpTime();
	Date cmpDate();
	void printDate(Date d);
	void printTime(Time t);
	void insert(char * c);*/
	Time initTime() {
		Time temp;
		temp.Hour[0] = '0';
		temp.Min[0] = '0';
		temp.Sec[0] = '0';
		temp.Hour[1] = '0';
		temp.Min[1] = '0';
		temp.Sec[1] = '0';
		temp.Hour[2] = '\0';
		temp.Min[2] = '\0';
		temp.Sec[2] = '\0';
		return temp;
	}
	Date initDate() {
		Date temp;
		temp.Day[0] = '0';
		temp.Month[0] = '0';
		temp.Year[0] = '0';
		temp.Day[1] = '0';
		temp.Month[1] = '0';
		temp.Year[1] = '0';
		temp.Day[2] = '\0';
		temp.Month[2] = '\0';
		temp.Year[2] = '0';
		temp.Year[3] = '0';
		temp.Year[4] = '\0';
		return temp;
	}
	void insert(char *c) {
		char temp;
		int i = 0;
		do {
			temp = _getch();
			fflush(stdin);
			if (ZERO <= temp && temp <= NINE) {
				c[i] = temp;
				cout << temp;
				i++;
			}
			else {
				cout << "Phai nhap so!!";
			}

		} while (c[i] != '\0');
	}
	Time insertTime() {
		Time temp = initTime();
		cout << "Nhap gio:\n";
		insert(temp.Hour);
		cout << "Nhap phut:\n";
		insert(temp.Min);
		cout << "Nhap giay:\n";
		insert(temp.Sec);
		return temp;
	}
	Date insertDate() {
		Date temp = initDate();
		cout << "Nhap gio:\n";
		insert(temp.Day);
		cout << "Nhap phut:\n";
		insert(temp.Month);
		cout << "Nhap giay:\n";
		insert(temp.Year);
		return temp;
	}
	unsigned int convertNumString2Int(string s) {
		int i = 0;
		myio io;
		char *c = io.convertString2Char(s);
		unsigned int sum = 0;
		while (c[i] != '\0') {
			i++;
		}
		i--;
		for (i; i >= 0; i--) {
			sum = sum * 10 + int(c[i] - 48);
		}
		delete c;
		return sum;
	}
};

