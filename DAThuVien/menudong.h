#pragma once
#include"mylib.h"
#include"thucdon.h"
#define ENTER 13
#define UP 72
#define DOWN 80

using namespace std;



class menudong
{
public:
	const int dong = 2;
	const int cot = 2;
	menudong();
	~menudong();
	thucdon thucDon;
	mylib mlib;
	const int MAXLIST = 100;
	void Normal() {
		mlib.SetColor(WHITE);
		mlib.SetBGColor(0);
	}
	void HighLight() {
		mlib.SetColor(15);
		mlib.SetBGColor(1);
	}
	int MenuDong(char td[][50],int so_item) {
		Normal();
		system("cls");   int chon = 0;
		int i;
		for (i = 0; i < so_item; i++)
		{
			mlib.gotoxy(this->cot, this->dong + i);
			cout << td[i];
		}
		HighLight();
		mlib.gotoxy(this->cot, this->dong + chon);
		cout << td[chon];
		char kytu;
		do {
			kytu = _getch();
			if (kytu == 0) kytu = _getch();
			switch (kytu) {
			case UP:if (chon + 1 > 1)
			{
				Normal();
				mlib.gotoxy(this->cot, this->dong + chon);
				cout << td[chon];
				chon--;
				HighLight();
				mlib.gotoxy(this->cot, this->dong + chon);
				cout << td[chon];
			}else{
				Normal();
				mlib.gotoxy(this->cot, this->dong);
				cout << td[0];
				chon=so_item-1;
				HighLight();
				mlib.gotoxy(this->cot, this->dong + so_item - 1);
				cout << td[so_item - 1];
			}
			break;
			case DOWN:if (chon + 1 < so_item)
			{
				Normal();
				mlib.gotoxy(this->cot, this->dong + chon);
				cout << td[chon];
				chon++;
				HighLight();
				mlib.gotoxy(this->cot, this->dong + chon);
				cout << td[chon];
			}else {
				Normal();
				mlib.gotoxy(this->cot, this->dong + chon);
				cout << td[chon];
				mlib.gotoxy(this->cot, this->dong);
				HighLight();
				cout << td[chon - so_item + 1];
				chon= chon - so_item + 1;
				mlib.gotoxy(this->cot, this->dong - so_item + 1);
			}
			break;
			case ENTER:
				return chon + 1;
			}

		} while (1);
	}

	int Menu(char td[][50], int so_item) {
		system("cls");
		int chon = 0;
		int i;
		for (i = 0; i < so_item; i++)
		{
			mlib.gotoxy(this->cot, this->dong + i);
			cout << td[i];
		}
	Nhaplai:
		mlib.gotoxy(this->cot, this->dong + so_item);
		cout << "Ban chon 1 so (1..10) :    ";
		mlib.gotoxy(this->mlib.wherex() - 4, this->mlib.wherey());
		cin >> chon;
		if (chon <1 || chon >so_item) goto Nhaplai;
		return chon;

	}
	/*void DayNgauNhien(PTR &First) {
		int n;
		cout << "So phan tu muon tao :";
		cin >> n;
		srand(time_t(NULL));
		for (int i = 0; i < n; i++)
			InsertLast(First, (rand() % 20) + 1);
	}*/
	/*void TaoDayTuFile(PTR &First, char *tenfile) {
		FILE *fp;  int n;
		fp = fopen(tenfile, "rt");
		if (fp == NULL) {
			cout << "Loi mo file de doc";		return;
		}
		fscanf(fp, "%d ", &n);	int so;
		for (int i = 0; i < n; i++) {
			fscanf(fp, "%d ", &so);	InsertLast(First, so);
		}
		fclose(fp);
	}*/
};

