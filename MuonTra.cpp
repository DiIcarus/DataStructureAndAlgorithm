#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<ctype.h>
#include<iostream>
#include"myDate.cpp"

using namespace std;
//////////////////////////////////////////
////////////TAO_STRUCT///////////////
struct MuonTra{
	string MASACH;
	Date ngayMuon,ngayTra;
	int trangThai;
};

struct Node{
	MuonTra thongTin;
	struct Node *next,*previous;
};

typedef struct Node *NodePtr;

typedef struct LienKetKep{
	NodePtr first,last;
}lienKet;

MuonTra muonTra,temp;
////////////////////////////////////////
//////////CAU_TRUC_DU_LIEU/////////
NodePtr newNode(void);
LienKetKep nodePointer(LienKetKep lienKet,int viTri);
int position(LienKetKep lienKet,NodePtr p);
void initialize(LienKetKep lienKet);
int isEmpty(LienKetKep lienKet);
void insertFirst(LienKetKep &lienKet,MuonTra nodeInfo);
void insertLast(LienKetKep &lienKet,MuonTra nodeInfo);
void insertAfter(NodePtr insertAfterThisNode, MuonTra nodeInfo);
void insertOrder(LienKetKep &lienKet,MuonTra nodeInfo);
void traverse(LienKetKep lienKet);
NodePtr searchInfo(LienKetKep lienKet,string maSach);
void deleteFirst(LienKetKep &lienKet);
void deleteLast(LienKetKep &lienKet);
void deleteAfter(NodePtr deleteNode);
void deleteOrder(LienKetKep &lienKet,string maSach);
void clearList(LienKetKep &lienKet);
////////////CHUONG_TRINH/////////
//void selection(node_ptr &first);
//void create_list(node_ptr &first);
//char menu();
//////////KET_THUC/////////
////////////////////////////////////////
NodePtr newNode(void){
	NodePtr conTroTraVe;
	conTroTraVe = (NodePtr)malloc(sizeof(struct Node));
	return conTroTraVe;
}
LienKetKep nodePointer(LienKetKep lienKet,int viTri){
	LienKetKep bienTraVe;
	int viTriTam = 1;
	bienTraVe.first = lienKet.first;
	while(bienTraVe.first!= NULL && viTriTam <viTri){
		bienTraVe.first = bienTraVe.first->next;
		viTriTam ++;
	}
	return bienTraVe;
}	
int position(LienKetKep lienKet,NodePtr p){
	int vitri = 1;
	NodePtr q;
	q = lienKet.first;
	while(q!= NULL && q!= p){
		q =q->next;
		vitri++;
	}
	if(q == NULL) return -1;
	return vitri;
}
void initialize(LienKetKep lienKet){
	lienKet.first = NULL;
	lienKet.last = NULL;
}
int isEmpty(LienKetKep lienKet){
	return((lienKet.first&&lienKet.last )== NULL ? true:false);
}
void insertFirst(LienKetKep &lienKet,MuonTra nodeInfo){
	NodePtr temp;
	temp = newNode();
	temp->thongTin = nodeInfo;
	temp->next = lienKet.first;
	lienKet.first->previous=temp;
	temp->previous = NULL;
	lienKet.first = temp;
}
void insertLast(LienKetKep &lienKet,MuonTra nodeInfo){
	NodePtr temp;
	temp = newNode();
	temp->thongTin = muonTra;
	temp->previous = lienKet.last;
	lienKet.last->next=temp;
	temp->next = NULL;
	lienKet.last = temp;
}
void insertAfter(NodePtr insertAfterThisNode, MuonTra nodeInfo){
	NodePtr nodeWillBeInserted;
	if(insertAfterThisNode == NULL){
		printf("khong them duoc");
	}else{
		nodeWillBeInserted = newNode();
		nodeWillBeInserted->thongTin = nodeInfo;
		nodeWillBeInserted->next = insertAfterThisNode->next;
		nodeWillBeInserted->previous = insertAfterThisNode->previous;
		insertAfterThisNode->next->previous = nodeWillBeInserted;
		insertAfterThisNode->next = nodeWillBeInserted;
	}
}
void insertOrder(LienKetKep &lienKet,MuonTra nodeInfo){
	NodePtr p,q;
	q = NULL;
	for(p = lienKet.first;p!=NULL && p->thongTin.MASACH<nodeInfo.MASACH;p = p->next) q=p;
	if(q == NULL) insertFirst(lienKet,nodeInfo);
	else insertAfter(q,nodeInfo);
}
void traverse(LienKetKep lienKet){
	NodePtr p;
	int stt = 0;
	p=lienKet.first;
	if(p == NULL) printf("Khong co sinh vien trong danh sach");
	while(p!= NULL){
		printf("");
		p=p->next;
	}
}
NodePtr searchInfo(LienKetKep lienKet,string maSach){
	NodePtr infoPosition;
	infoPosition=lienKet.first;
	while(infoPosition!= NULL && infoPosition->thongTin.MASACH !=maSach){
		infoPosition=infoPosition->next;
	}
	return infoPosition;
}
void deleteFirst(LienKetKep &lienKet){
	NodePtr deleteNode;
	if(isEmpty(lienKet)) printf("Khong con gi trong DS");
	else {
		deleteNode=lienKet.first;
		lienKet.first= deleteNode->next;
		lienKet.first->previous = NULL;
		free(deleteNode);
	}
}
void deleteLast(LienKetKep &lienKet){
	NodePtr deleteNode;
	if(isEmpty(lienKet)) printf("Khong con gi trong DS");
	else {
		deleteNode=lienKet.last;
		lienKet.last= deleteNode->previous;
		lienKet.last->next = NULL;
		free(deleteNode);
	}
}
void deleteAfter(NodePtr deleteNode){
	NodePtr q;
	if((deleteNode==NULL)||(deleteNode->next == NULL)||(deleteNode->previous == NULL)) printf("Khong the xoa");
	else{
		q = deleteNode->next;
		deleteNode->previous = q->previous;
		q->previous->next = q;
		free(deleteNode);
	}
}
void deleteOrder(LienKetKep &lienKet,string maSach){
	NodePtr deleteNode;
	deleteNode =searchInfo(lienKet,maSach);
	if(deleteNode->next==NULL){
		deleteFirst(lienKet);
	}else if(deleteNode->previous==NULL){
		deleteLast(lienKet);
	}else{
		deleteAfter(deleteNode);
	}
}
void clearList(LienKetKep &lienKet){
	NodePtr p,q;
	p = lienKet.first;
	while(lienKet.first != NULL){
		deleteFirst(lienKet);
	}
}
//void selection(node_ptr &first){
//	node_ptr p,q,pmin;
//	SinhVien min;
//	for(p=first;p->next !=NULL;p=p->next){
//		min = p->info;
//		pmin = p;
//		for(q = p->next;q!=NULL;q=q->next){
//			if(min.maso > q->info.maso) {
//				min = q->info;
//				pmin = q;
//			}
//		}
//		pmin->info = p->info;
//		p->info = min;
//	}
//}
//char menu(){
//	char chucnang;
//	do{
////	system("cls");
//	printf("\n\n\t\tCHUONG TRINH QUAN LY DANH SACH SINH VIEN");
//	printf("\n\n Cac chuc nang cua chuong trinh:\n");
//	printf(" 1:tao danh sach sinh vien\n");
//	printf(" 2:Them sv vao danh sach\n");
//	printf(" 3:Xem danhh sach sv\n");
//	printf(" 4:Hieu chinh sv\n");
//	printf(" 5:Xoa sv trong danh sach\n");
//	printf(" 6:Tim kiem sinh vien theo MSSV\n");
//	printf(" 7:Sap xep sanh sach theo MSSV\n");
//	printf(" 8:Them sinh vien vao danh sach da co thu tu\n");
//	printf(" 9:Xoa toan bo danh sach\n");
//	printf(" 0:Ket thuc chuong trinh\n");
//	printf("Chuc nang ban chon: ");
//	chucnang=getche();
//	}while(chucnang<'0'||chucnang>'9');
//	return chucnang;
//}
//void create_list(node_ptr &first){
//	node_ptr last,p;
//	SinhVien sv;
//	char maso[5],c;
//	clearlist(first);
//	printf("Ma so sinh vien: ");
//	gets(maso);
//	sv.maso = atoi(maso);
//	while(sv.maso !=0){
//		printf("Ho sinh vien: ");
//		gets(sv.ho);
//		printf("Ten sinh vien: ");
//		gets(sv.ten);
//		p= new_node();
//		p->info = sv;
//		if(first == NULL) first = p;
//		else last->next = p;
//		last = p;
//		p->next =NULL;
//		printf("Ma so sinh vien moi: ");
//		gets(maso);
//		sv.maso = atoi(maso);
//	}
//}
int main(){
	return 1;
//	int vitri;
//	char chucnang,c,maso[5],c_vitri[5];
//	initialize(first);
//	do{
//		chucnang = menu();
//		fflush(stdin);
//		switch(chucnang){
//			case '1':{
//				create_list(first);
//				break;
//			}
//			case '2':{
//				printf("\nvi tri them(1,2,3, . . .):");
//				gets(c_vitri);
//				vitri=atoi(c_vitri);
//				p = nodepointer(first,vitri-1);
//				if(vitri<=0||p==NULL){
//					printf("Vi tri khong hop le");
//					getche();
//				}else{
//					printf("Ma so sinh vien: ");
//					gets(maso);
//					sv.maso = atoi(maso);
//					printf("Ho sinh vien: ");
//					gets(sv.ho);
//					printf("Ten sinh vien: ");
//					gets(sv.ten);
//					if(vitri == 1) insert_first(first,sv);
//					else insert_after(p,sv);
//				}
//				break;
//			}
//			case '3':{
//				printf("Danh sach sinh vien: ");
//				printf("\n STT MSSV		HOTEN");
//				traverse(first);
//				getche();
//				break;
//			}
//			case '4':{
//				printf("vi tri hieu chinh(1,2,...):");
//				gets(c_vitri);
//				vitri = atoi(c_vitri);
//				p=nodepointer(first,vitri);
//				if(p == NULL){
//					printf("Vi tri khon phu hop");
//					getche();
//				}else{
//					printf("\n STT:%d MSSV:%d HO:%s TEN:%s",vitri,p->info.maso,p->info.ho,p->info.ten);
//					printf("\nMa sosv moi: ");
//					gets(maso);
//					sv.maso = atoi(maso);
//					printf("Ho sv moi: ");
//					gets(sv.ho);
//					printf("ten sv moi: ");
//					gets(sv.ten);
//					p->info = sv;
//				}
//				break;
//			}
//			case '5':{
//				printf("\nVi tri can xoa(1,2, ...)");
//				gets(c_vitri);
//				vitri = atoi(c_vitri);
//				p = nodepointer(first,vitri-1);
//				if(vitri <=0||p==NULL){
//					printf("vi tri khong hop le");
//					getche();
//				}else{
//					if(vitri ==1) delete_first(first);
//					else delete_after(p);
//				}
//				break;
//			}
//			case '6':{
//				cout<<"\n Ma so sinh vien can tim: ";
//				gets(maso);
//				sv.maso = atoi(maso);
//				p=search_info(first,sv.maso);
//				if(p ==NULL) printf("Khong co sinh vien co ma so %d trong danh sach",sv.maso);
//				else{
//					printf("Tim thay o vi tri %d trong danh sach",position(first,p));
//					getche();
//				}
//				break;
//			}
//			case '7':{
//				cout<<"ban cho chac khong ??";
//				c = toupper(getche());
//				if(c == 'C') selection(first);
//				break;
//			}
//			case '8':{
//				cout<<"Ban nho sap xep danh sach truowc. Nhan phim bat ky . .. ";
//				getche();
//				cout<<"ma so sinh vien: ";
//				gets(maso);
//				sv.maso = atoi(maso);
//				cout<<"Ho sinh vien: ";
//				gets(sv.ho);
//				cout<<"ten sinh vien: ";
//				gets(sv.ten);
//				insert_order(first,sv);
//				break;
//			}
//			case '9':{
//				cout<<"Ban co chac khong(c/k):";
//				c = getche();
//				if(c=='c'||c=='C') clearlist(first);
//				break;
//			}
//			
//		}
//	}while(chucnang != '0');
//	clearlist(first);
}
