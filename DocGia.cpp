#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<ctype.h>
#include<iostream>

using namespace std;

struct SinhVien{
	int maso;
	char ten[10],ho[10];
};

struct node{
	SinhVien info;
	struct node *next;
};
typedef struct node *node_ptr;
node_ptr first;
SinhVien sv;
node_ptr p;
node_ptr new_node(void){
	node_ptr p;
	p = (node_ptr)malloc(sizeof(struct node));
	return p;
}
node_ptr nodepointer(node_ptr first,int i){
	node_ptr p;
	int vitri = 1;
	p = first;
	while(p!= NULL && vitri <i){
		p = p->next;
		vitri ++;
	}
	return p;
}	
int position(node_ptr first,node_ptr p){
	int vitri = 1;
	node_ptr q;
	q = first;
	while(q!= NULL && q!= p){
		q =q->next;
		vitri++;
	}
	if(q == NULL) return -1;
	return vitri;
}
void initialize(node_ptr first){
	first = NULL;
}
int empty(node_ptr first){
	return(first == NULL ? true:false);
}
void insert_first(node_ptr &first,SinhVien x){
	node_ptr p;
	p = new_node();
	p->info = x;
	p->next = first;
	first = p;
}
void insert_after(node_ptr p, SinhVien x){
	node_ptr q;
	if(p == NULL){
		printf("khong them duoc");
	}else{
		q = new_node();
		q->info = x;
		q->next = p->next;
		p->next = q;
	}
}
void delete_first(node_ptr &first){
	node_ptr p;
	if(empty(first)) printf("Khong con SV trong DS");
	else {
		p=first;
		first= p->next;
		free(p);
	}
}
void delete_after(node_ptr p){
	node_ptr q;
	if((p==NULL)||(p->next == NULL)) printf("Khong the xoa");
	else{
		q = p->next;
		p->next = q->next;
		free(q);
	}
}
void insert_order(node_ptr &first,SinhVien x){
	node_ptr p,q;
	q = NULL;
	for(p = first;p!=NULL && p->info.maso<x.maso;p = p->next) q=p;
	if(q == NULL) insert_first(first,x);
	else insert_after(q,x);
}
void clearlist(node_ptr &first){
	node_ptr p,q;
	p = first;
	while(first != NULL){
		p = first;
		first = first->next;
		free(p);
	}
}
void traverse(node_ptr first){
	node_ptr p;
	int stt = 0;
	p=first;
	if(p == NULL) printf("Khong co sinh vien trong danh sach");
	while(p!= NULL){
		printf("%5d%8d%-30s%-10s",++stt,p->info.maso,p->info.ho,p->info.ten);
		p=p->next;
	}
}
node_ptr search_info(node_ptr first,int x){
	node_ptr p;
	p=first;
	while(p!= NULL && p->info.maso !=x){
		p=p->next;
	}
	return p;
}
void selection(node_ptr &first){
	node_ptr p,q,pmin;
	SinhVien min;
	for(p=first;p->next !=NULL;p=p->next){
		min = p->info;
		pmin = p;
		for(q = p->next;q!=NULL;q=q->next){
			if(min.maso > q->info.maso) {
				min = q->info;
				pmin = q;
			}
		}
		pmin->info = p->info;
		p->info = min;
	}
}
char menu(){
	char chucnang;
	do{
//	system("cls");
	printf("\n\n\t\tCHUONG TRINH QUAN LY DANH SACH SINH VIEN");
	printf("\n\n Cac chuc nang cua chuong trinh:\n");
	printf(" 1:tao danh sach sinh vien\n");
	printf(" 2:Them sv vao danh sach\n");
	printf(" 3:Xem danhh sach sv\n");
	printf(" 4:Hieu chinh sv\n");
	printf(" 5:Xoa sv trong danh sach\n");
	printf(" 6:Tim kiem sinh vien theo MSSV\n");
	printf(" 7:Sap xep sanh sach theo MSSV\n");
	printf(" 8:Them sinh vien vao danh sach da co thu tu\n");
	printf(" 9:Xoa toan bo danh sach\n");
	printf(" 0:Ket thuc chuong trinh\n");
	printf("Chuc nang ban chon: ");
	chucnang=getche();
	}while(chucnang<'0'||chucnang>'9');
	return chucnang;
}
void create_list(node_ptr &first){
	node_ptr last,p;
	SinhVien sv;
	char maso[5],c;
	clearlist(first);
	printf("Ma so sinh vien: ");
	gets(maso);
	sv.maso = atoi(maso);
	while(sv.maso !=0){
		printf("Ho sinh vien: ");
		gets(sv.ho);
		printf("Ten sinh vien: ");
		gets(sv.ten);
		p= new_node();
		p->info = sv;
		if(first == NULL) first = p;
		else last->next = p;
		last = p;
		p->next =NULL;
		printf("Ma so sinh vien moi: ");
		gets(maso);
		sv.maso = atoi(maso);
	}
}
int main(){
	int vitri;
	char chucnang,c,maso[5],c_vitri[5];
	initialize(first);
	do{
		chucnang = menu();
		fflush(stdin);
		switch(chucnang){
			case '1':{
				create_list(first);
				break;
			}
			case '2':{
				printf("\nvi tri them(1,2,3, . . .):");
				gets(c_vitri);
				vitri=atoi(c_vitri);
				p = nodepointer(first,vitri-1);
				if(vitri<=0||p==NULL){
					printf("Vi tri khong hop le");
					getche();
				}else{
					printf("Ma so sinh vien: ");
					gets(maso);
					sv.maso = atoi(maso);
					printf("Ho sinh vien: ");
					gets(sv.ho);
					printf("Ten sinh vien: ");
					gets(sv.ten);
					if(vitri == 1) insert_first(first,sv);
					else insert_after(p,sv);
				}
				break;
			}
			case '3':{
				printf("Danh sach sinh vien: ");
				printf("\n STT MSSV		HOTEN");
				traverse(first);
				getche();
				break;
			}
			case '4':{
				printf("vi tri hieu chinh(1,2,...):");
				gets(c_vitri);
				vitri = atoi(c_vitri);
				p=nodepointer(first,vitri);
				if(p == NULL){
					printf("Vi tri khon phu hop");
					getche();
				}else{
					printf("\n STT:%d MSSV:%d HO:%s TEN:%s",vitri,p->info.maso,p->info.ho,p->info.ten);
					printf("\nMa sosv moi: ");
					gets(maso);
					sv.maso = atoi(maso);
					printf("Ho sv moi: ");
					gets(sv.ho);
					printf("ten sv moi: ");
					gets(sv.ten);
					p->info = sv;
				}
				break;
			}
			case '5':{
				printf("\nVi tri can xoa(1,2, ...)");
				gets(c_vitri);
				vitri = atoi(c_vitri);
				p = nodepointer(first,vitri-1);
				if(vitri <=0||p==NULL){
					printf("vi tri khong hop le");
					getche();
				}else{
					if(vitri ==1) delete_first(first);
					else delete_after(p);
				}
				break;
			}
			case '6':{
				cout<<"\n Ma so sinh vien can tim: ";
				gets(maso);
				sv.maso = atoi(maso);
				p=search_info(first,sv.maso);
				if(p ==NULL) printf("Khong co sinh vien co ma so %d trong danh sach",sv.maso);
				else{
					printf("Tim thay o vi tri %d trong danh sach",position(first,p));
					getche();
				}
				break;
			}
			case '7':{
				cout<<"ban cho chac khong ??";
				c = toupper(getche());
				if(c == 'C') selection(first);
				break;
			}
			case '8':{
				cout<<"Ban nho sap xep danh sach truowc. Nhan phim bat ky . .. ";
				getche();
				cout<<"ma so sinh vien: ";
				gets(maso);
				sv.maso = atoi(maso);
				cout<<"Ho sinh vien: ";
				gets(sv.ho);
				cout<<"ten sinh vien: ";
				gets(sv.ten);
				insert_order(first,sv);
				break;
			}
			case '9':{
				cout<<"Ban co chac khong(c/k):";
				c = getche();
				if(c=='c'||c=='C') clearlist(first);
				break;
			}
			
		}
	}while(chucnang != '0');
	clearlist(first);
}
