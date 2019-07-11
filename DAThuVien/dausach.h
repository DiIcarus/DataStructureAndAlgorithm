#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<ctype.h>
#include<iostream>
#include"myIO.h"
#include"menudong.h"
#include"danhmucsach.h"
using namespace std;
unsigned int const MAX_LIST = 1000;
class dausach
{
public:
	struct DauSach {
		char ISBN[6];
		string tenSach,tacGia,namxuatBan,theLoai;
		unsigned int soTrang;
		danhmucsach *danhMucSach;
	};
	struct NodeDS {
		int index;
		DauSach *PointerArr[MAX_LIST];
	};
	NodeDS danhSachDauSach;
	dausach();
	~dausach();
	void initPointerArr(NodeDS &danhSachDauSach) {
		danhSachDauSach.index = -1;
		for (int i = 0; i < MAX_LIST; i++) {
			danhSachDauSach.PointerArr[i] = new DauSach;
		}
	}
	bool isEmpty(NodeDS danhSachDauSach) {
		if (danhSachDauSach.index == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	bool isFull(NodeDS danhSachDauSach) {
		if (danhSachDauSach.index == MAX_LIST-1) {
			return true;
		}
		else {
			return false;
		}
	}
	DauSach makeNodePointerArr(string maSach) {
		DauSach temp;
		cout << "\nNhap Ten Sach:";
		temp.tenSach;
		cout << "\nNhap Ten Tac Gia:";
		temp.tacGia;
		cout << "\nNhap The Loai Sach:";
		temp.theLoai;
		cout << "\nNhap So Trang Sach:";
		temp.soTrang;
		cout << "\nNhap Nam Xuat Ban Sach:";
		temp.namxuatBan;
		cout << "\nNhap Danh Muc Sach:";
		temp.danhMucSach->create_list(temp.danhMucSach->first,maSach);
		return temp;
	}
	void insertPointerArr(NodeDS &danhSachDauSach,DauSach dauSach) {
		if (isFull(danhSachDauSach)) {
			cout << "\nKhong Them Duoc";
		}
		else {
			danhSachDauSach.PointerArr[danhSachDauSach.index] = &dauSach;
			danhSachDauSach.index++;
		}
		
	}
	void createdPointerArr(NodeDS &danhSachDauSach,string maSach) {
		insertPointerArr(danhSachDauSach, makeNodePointerArr(maSach));
	}
	void searchPointerArr(NodeDS danhSachDauSach, DauSach dauSach) {

	}
	void travelPointerArr(NodeDS danhSachDauSach) {
		for (int i = 0; i < danhSachDauSach.index+1; i++) {
			cout << "\nISBN:" << danhSachDauSach.PointerArr[i]->ISBN;
			cout << "\nTen Sach:" << danhSachDauSach.PointerArr[i]->tenSach;
			cout << "\nSo Trang:" << danhSachDauSach.PointerArr[i]->soTrang;
			cout << "\nTac Gia:" << danhSachDauSach.PointerArr[i]->tacGia;
			cout << "\nNam xuat ban:" << danhSachDauSach.PointerArr[i]->namxuatBan;
			cout << "\nThe Loai:" << danhSachDauSach.PointerArr[i]->theLoai;
			cout << "\nCac Ma Sach:" << danhSachDauSach.PointerArr[i]->danhMucSach->first->info.MASACH;
			cout << "\nTrang Thai:" << danhSachDauSach.PointerArr[i]->danhMucSach->first->info.trangThai;
		}
	}
	void delPointerArr(NodeDS &danhSachDauSach, DauSach dauSach) {
		if (isEmpty(danhSachDauSach)) {
			cout << "\nDanh Sach Trong";
		}
		else {
			danhSachDauSach.PointerArr[danhSachDauSach.index] = &dauSach;
			danhSachDauSach.index--;
		}
	}
	void sortPointerArr() {

	}
};

