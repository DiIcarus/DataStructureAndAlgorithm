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
#include"thucdon.h"
using namespace std;

class danhmucsach
{
public:
	myio iodanhmucsach;
	menudong menudanhmucsach;
	struct DanhMucSach {
		string MASACH;
		unsigned int trangThai;
		string viTri;
	};

	struct node {
		DanhMucSach info;
		struct node *next;
	};
	typedef struct node *node_ptr;
	node_ptr first;
	DanhMucSach danhMucSach;
	node_ptr p;
	node_ptr new_node(void) {
		node_ptr p;
		p = (node_ptr)malloc(sizeof(struct node));
		return p;
	}
	node_ptr nodepointer(node_ptr first, int i) {
		node_ptr p;
		int vitri = 1;
		p = first;
		while (p != NULL && vitri < i) {
			p = p->next;
			vitri++;
		}
		return p;
	}
	int position(node_ptr first, node_ptr p) {
		int vitri = 1;
		node_ptr q;
		q = first;
		while (q != NULL && q != p) {
			q = q->next;
			vitri++;
		}
		if (q == NULL) return -1;
		return vitri;
	}
	void initialize(node_ptr first) {
		first = NULL;
	}
	int empty(node_ptr first) {
		return(first == NULL ? true : false);
	}
	void insert_first(node_ptr &first, DanhMucSach x) {
		node_ptr p;
		p = new_node();
		p->info = x;
		p->next = first;
		first = p;
	}
	void insert_last(node_ptr &first, DanhMucSach x) {
		node_ptr p,q;
		q = new_node();
		p = first;
		while (p->next !=NULL)
		{
			p = p->next;
		}
		q->info = x;
		p->next = q;
		q->next = NULL;
		free(p);
	}
	void insert_after(node_ptr p, DanhMucSach x) {
		node_ptr q;
		if (p == NULL) {
			printf("khong them duoc");
		}
		else {
			q = new_node();
			q->info = x;
			q->next = p->next;
			p->next = q;
		}
	}
	void delete_first(node_ptr &first) {
		node_ptr p;
		if (empty(first)) printf("Khong con SV trong DS");
		else {
			p = first;
			first = p->next;
			free(p);
		}
	}
	void delete_after(node_ptr p) {
		node_ptr q;
		if ((p == NULL) || (p->next == NULL)) printf("Khong the xoa");
		else {
			q = p->next;
			p->next = q->next;
			free(q);
		}
	}
	void insert_order(node_ptr &first, DanhMucSach x) {
		node_ptr p, q;
		q = NULL;
		for (p = first; p != NULL && p->info.MASACH < x.MASACH; p = p->next) q = p;
		if (q == NULL) insert_first(first, x);
		else insert_after(q, x);
	}
	void clearlist(node_ptr &first) {
		node_ptr p;
		p = first;
		while (first != NULL) {
			p = first;
			first = first->next;
			free(p);
		}
	}
	void traverse(node_ptr first) {
		node_ptr p;
		int stt = 0;
		p = first;
		if (p == NULL) printf_s("Khong co sinh vien trong danh sach");
		while (p != NULL) {
			printf_s("%5d%8s%-30d%-10s", ++stt, p->info.MASACH, p->info.trangThai, p->info.viTri);
			p = p->next;
		}
	}
	node_ptr search_info(node_ptr first, string x) {
		node_ptr p;
		p = first;
		while (p != NULL && p->info.MASACH != x) {
			p = p->next;
		}
		return p;
	}
	void selection(node_ptr &first) {
		node_ptr p, q, pmin;
		DanhMucSach min;
		for (p = first; p->next != NULL; p = p->next) {
			min = p->info;
			pmin = p;
			for (q = p->next; q != NULL; q = q->next) {
				if (min.MASACH > q->info.MASACH) {
					min = q->info;
					pmin = q;
				}
			}
			pmin->info = p->info;
			p->info = min;
		}
	}
	int justInNum() {
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
		return (int)temp - 48;
	}
	void create_list(node_ptr &first,string maSach) {
		DanhMucSach danhMucSach;
		danhMucSach.MASACH = maSach;
		printf_s("\nNhap Vi Tri: ");
		danhMucSach.viTri = string(iodanhmucsach.justInString(1, 15));
		printf_s("\Chon Trang Thai: ");
		switch (menudanhmucsach.MenuDong(thucDonTrangThai,3))
		{
		case 0: {
			danhMucSach.trangThai = 0;
			break;
		}
		case 1: {
			danhMucSach.trangThai = 1;
			break;
		}
		case 2: {
			danhMucSach.trangThai = 2;
			break;
		}
		}
		insert_first(this->first, danhMucSach);
	}

	danhmucsach();
	~danhmucsach();
};



