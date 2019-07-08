#pragma once
#include<iostream>
#include"mydate.h"
using namespace std;
class MuonTra
{
	struct muonTra {
		string MASACH;
		mydate ngayMuon, ngayTra;
		int trangThai;
	};

	struct Node {
		muonTra thongTin;
		struct Node *next, *previous;
	};

	typedef struct Node *NodePtr;

	typedef struct LienKetKep {
		NodePtr first, last;
	}lienKet;

	muonTra muonTra, temp;
	public:
		MuonTra();
		~MuonTra();
		//NodePtr newNode(void);
		//LienKetKep nodePointer(LienKetKep lienKet, int viTri);
		//int position(LienKetKep lienKet, NodePtr p);
		//void initNote(LienKetKep &lienKet);
		//int isEmpty(LienKetKep lienKet);
		//void insertFirst(LienKetKep &lienKet, MuonTra nodeInfo);
		//void insertLast(LienKetKep &lienKet, MuonTra nodeInfo);
		//void insertAfter(NodePtr insertAfterThisNode, MuonTra nodeInfo);
		//void insertOrder(LienKetKep &lienKet, MuonTra nodeInfo);
		//void traverse(LienKetKep lienKet);
		//NodePtr searchInfo(LienKetKep lienKet, string maSach);
		//void deleteFirst(LienKetKep &lienKet);
		//void deleteLast(LienKetKep &lienKet);
		//void deleteAfter(NodePtr deleteNode);
		//void deleteOrder(LienKetKep &lienKet, string maSach);
		//void clearList(LienKetKep &lienKet);
		//////////////CHUONG_TRINH/////////
		//void selection(node_ptr &first);
		//void create_list(node_ptr &first);
		//char menu();
		//////////KET_THUC/////////
		////////////////////////////////////////
		NodePtr newNode(void) {
			NodePtr conTroTraVe;
			conTroTraVe = new Node;
			return conTroTraVe;
		}
		LienKetKep nodePointer(LienKetKep lienKet, int viTri) {
			LienKetKep bienTraVe;
			int viTriTam = 1;
			bienTraVe.first = lienKet.first;
			while (bienTraVe.first != NULL && viTriTam < viTri) {
				bienTraVe.first = bienTraVe.first->next;
				viTriTam++;
			}
			return bienTraVe;
		}
		int position(LienKetKep lienKet, NodePtr p) {
			int vitri = 1;
			NodePtr q;
			q = lienKet.first;
			while (q != NULL && q != p) {
				q = q->next;
				vitri++;
			}
			if (q == NULL) return -1;
			return vitri;
		}
		void initNote(LienKetKep &lienKet) {
			lienKet.first = NULL;
			lienKet.last = NULL;
		}
		int isEmpty(LienKetKep lienKet) {
			return((lienKet.first == NULL && lienKet.last == NULL) ? true : false);
		}
		void insertFirst(LienKetKep &lienKet, MuonTra nodeInfo) {
			NodePtr temp;
			temp = newNode();
			temp->thongTin = nodeInfo.muonTra;
			temp->next = lienKet.first;
			lienKet.first->previous = temp;
			temp->previous = NULL;
			lienKet.first = temp;
		}
		void insertLast(LienKetKep &lienKet, MuonTra nodeInfo) {
			NodePtr temp;
			temp = newNode();
			temp->thongTin = nodeInfo.muonTra;
			temp->previous = lienKet.last;
			lienKet.last->next = temp;
			temp->next = NULL;
			lienKet.last = temp;
		}
		void insertAfter(NodePtr insertAfterThisNode, MuonTra nodeInfo) {
			NodePtr nodeWillBeInserted;
			if (insertAfterThisNode == NULL) {
				printf("khong them duoc");
			}
			else {
				nodeWillBeInserted = newNode();
				nodeWillBeInserted->thongTin = nodeInfo.muonTra;
				nodeWillBeInserted->next = insertAfterThisNode->next;
				nodeWillBeInserted->previous = insertAfterThisNode->previous;
				insertAfterThisNode->next->previous = nodeWillBeInserted;
				insertAfterThisNode->next = nodeWillBeInserted;
			}
		}
		void insertOrder(LienKetKep &lienKet, MuonTra nodeInfo) {
			NodePtr p, q;
			q = NULL;
			for (p = lienKet.first; p != NULL && p->thongTin.MASACH < nodeInfo.muonTra.MASACH; p = p->next) q = p;
			if (q == NULL) insertFirst(lienKet, nodeInfo);
			else insertAfter(q, nodeInfo);
		}
		void traverse(LienKetKep lienKet) {
			NodePtr p;
			int stt = 0;
			p = lienKet.first;
			if (p == NULL) printf("Khong co sinh vien trong danh sach");
			while (p != NULL) {
				printf("");
				p = p->next;
			}
		}
		NodePtr searchInfo(LienKetKep lienKet, string maSach) {
			NodePtr infoPosition;
			infoPosition = lienKet.first;
			while (infoPosition != NULL && infoPosition->thongTin.MASACH != maSach) {
				infoPosition = infoPosition->next;
			}
			return infoPosition;
		}
		void deleteFirst(LienKetKep &lienKet) {
			NodePtr deleteNode;
			if (isEmpty(lienKet)) printf("Khong con gi trong DS");
			else {
				deleteNode = lienKet.first;
				lienKet.first = deleteNode->next;
				lienKet.first->previous = NULL;
				free(deleteNode);
			}
		}
		void deleteLast(LienKetKep &lienKet) {
			NodePtr deleteNode;
			if (isEmpty(lienKet)) printf("Khong con gi trong DS");
			else {
				deleteNode = lienKet.last;
				lienKet.last = deleteNode->previous;
				lienKet.last->next = NULL;
				free(deleteNode);
			}
		}
		void deleteAfter(NodePtr deleteNode) {
			NodePtr q;
			if ((deleteNode == NULL) || (deleteNode->next == NULL) || (deleteNode->previous == NULL)) printf("Khong the xoa");
			else {
				q = deleteNode->next;
				deleteNode->previous = q->previous;
				q->previous->next = q;
				free(deleteNode);
			}
		}
		void deleteOrder(LienKetKep &lienKet, string maSach) {
			NodePtr deleteNode;
			deleteNode = searchInfo(lienKet, maSach);
			if (deleteNode->next == NULL) {
				deleteFirst(lienKet);
			}
			else if (deleteNode->previous == NULL) {
				deleteLast(lienKet);
			}
			else {
				deleteAfter(deleteNode);
			}
		}
		void clearList(LienKetKep &lienKet) {
			NodePtr p;
			p = lienKet.first;
			while (lienKet.first != NULL) {
				deleteFirst(lienKet);
			}
		}

};

