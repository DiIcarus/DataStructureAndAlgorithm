#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<ctype.h>
#include<iostream>
#include"MuonTra.cpp"
using namespace std;

struct DocGia{
	int MATHE;
	string Ho,Ten,Phai;
	bool trangThai;
	MuonTra *danhSachMuon;
};

struct NodeLead{
	DocGia thongTinDocGia;
	struct NodeLead *right,*left;
};
typedef struct NodeLead *NodeLeadPtr;
NodeLeadPtr root;
DocGia docGia;
///////////////////////////////////////////////////////////////////
///////////////////CAU_TRUC_DU_LIEU///////////////
NodeLeadPtr newNodeLead(void);
void initNodeLead(NodeLeadPtr &root);
int isNodeLeadEmpty(NodeLeadPtr root);
//node_ptr nodepointer(node_ptr first,int i);
//int position(node_ptr first,node_ptr p);
//void insert_first(node_ptr &first,SinhVien x);
//void insert_after(node_ptr p, SinhVien x);
//void insert_order(node_ptr &first,SinhVien x);
//node_ptr search_info(node_ptr first,int x);
//void traverse(node_ptr first);
//void delete_first(node_ptr &first);
//void delete_after(node_ptr p);
//void clearlist(node_ptr &first);
/////////////////CHUC_NANG////////////////////////
//void selection(node_ptr &first);
//char menu();
//void create_list(node_ptr &first);
////////////KET_THUC//////////////////////////////
/////////////////////////////////////////////////////////////////
NodeLeadPtr newNodeLead(void){
	NodeLeadPtr p;
	p = (NodeLeadPtr)malloc(sizeof(struct NodeLead));
	return p;
}

void initNodeLead(NodeLeadPtr &root){
	root = NULL;
}
int isNodeLeadEmpty(NodeLeadPtr root){
	return(root == NULL ? true:false);
}
//int LeftOf( const int value, const node_t* root ){
//    return value < root->data;
//}
//int RightOf( const int value, const node_t* root ){
//    return value > root->data;
//}
NodeLeadPtr makeNodeLead(NodeLead nodeLead){
   	NodeLeadPtr pointerNewNote = newNodeLead(); 
   	pointerNewNote->thongTinDocGia = nodeLead.thongTinDocGia;
   	pointerNewNote->left = pointerNewNote->right = NULL;
   	return pointerNewNote;
}
void insertNodeLead(NodeLeadPtr &root , NodeLead nodeLead){
    NodeLeadPtr pointerNewNode =makeNodeLead(nodeLead);
    NodeLeadPtr travelTree,nodeLeadEndOfTravel;
    if(root == NULL){
    	root = pointerNewNode;
    }
    else{
	    travelTree = root ;
	    nodeLeadEndOfTravel=NULL;
	    while(travelTree!=NULL){
	        nodeLeadEndOfTravel = travelTree;
	        if(nodeLead.thongTinDocGia.MATHE < travelTree->thongTinDocGia.MATHE){
	        	travelTree= travelTree->left;
	        }else{
	        	travelTree= travelTree->right;
	      	}
	    }
		if(nodeLead.thongTinDocGia.MATHE< nodeLeadEndOfTravel->thongTinDocGia.MATHE){
	        nodeLeadEndOfTravel->left = pointerNewNode;
	    }else{
	        nodeLeadEndOfTravel->right = pointerNewNode;
	    }
    }
}
NodeLeadPtr searchNodeLead(NodeLeadPtr root , NodeLead infoNodeLead)
{
   	NodeLeadPtr travelTree = root;
   	while(travelTree!=NULL)
   	{
    	if(travelTree->thongTinDocGia.MATHE== infoNodeLead.thongTinDocGia.MATHE) return travelTree;
    	else if(infoNodeLead.thongTinDocGia.MATHE < travelTree->thongTinDocGia.MATHE) travelTree = travelTree->left;
    	else travelTree = travelTree->right;
   	}
   	return NULL;//Khong tim thay
}
NodeLeadPtr leftMostNodeLead(const NodeLeadPtr nodeLeadPtr){
	NodeLeadPtr leftMostNodeLeadPointer = nodeLeadPtr;
    while ( leftMostNodeLeadPointer->left != NULL )
        leftMostNodeLeadPointer = leftMostNodeLeadPointer->left;
    return leftMostNodeLeadPointer;
}
int delNodeLead(NodeLeadPtr &root, NodeLead infoNodeLead){
   	NodeLeadPtr deletedNodeLeadPointer;
	NodeLeadPtr nodeLeadEndOfTravel;
	NodeLeadPtr swapedInfoNodeLeadPointer;
   	deletedNodeLeadPointer = searchNodeLead(root,infoNodeLead);
   	nodeLeadEndOfTravel = NULL;
   	if(deletedNodeLeadPointer==NULL) return 0;
   	else{
      	if((deletedNodeLeadPointer->left != NULL)&&(deletedNodeLeadPointer->right != NULL)){
		  	//nut xoa co 2 nhanh con
         	swapedInfoNodeLeadPointer = leftMostNodeLead(deletedNodeLeadPointer->right);
         	deletedNodeLeadPointer->thongTinDocGia = swapedInfoNodeLeadPointer->thongTinDocGia;
			delete (deletedNodeLeadPointer);
      	}else if((deletedNodeLeadPointer->left != NULL)&&(deletedNodeLeadPointer->right == NULL)){
			//nut can xoa co mot nhanh con ben trai 
			swapedInfoNodeLeadPointer = deletedNodeLeadPointer;		
      		while(swapedInfoNodeLeadPointer->left!=NULL){
				swapedInfoNodeLeadPointer->thongTinDocGia = swapedInfoNodeLeadPointer->left->thongTinDocGia;
      			swapedInfoNodeLeadPointer = swapedInfoNodeLeadPointer->left;
			}
			delete (swapedInfoNodeLeadPointer);
		}else if((deletedNodeLeadPointer->left == NULL)&&(deletedNodeLeadPointer->right != NULL)){//nut can xoa co mot nhanh con ben trai
      		//nut can xoa co mot nhanh con ben phai
      		swapedInfoNodeLeadPointer = deletedNodeLeadPointer;		
      		while(swapedInfoNodeLeadPointer->right!=NULL){
				swapedInfoNodeLeadPointer->thongTinDocGia = swapedInfoNodeLeadPointer->right->thongTinDocGia;
      			swapedInfoNodeLeadPointer = swapedInfoNodeLeadPointer->right;
			}
			delete (swapedInfoNodeLeadPointer);
		}else{
			//nut can xoa la nut la
      		delete (deletedNodeLeadPointer);
		}
      	return 1;
   	}
}
void preOrderNodeLead(NodeLeadPtr root){
    if(root != NULL)
    {
        printf("%d ", root->thongTinDocGia.MATHE);
        preOrderNodeLead(root->left);
        preOrderNodeLead(root->right);
    }
}
 
void inOrderNodeLead(NodeLeadPtr root){
    if(root != NULL)
    {
        inOrderNodeLead(root->left);
        printf("%d ", root->thongTinDocGia.MATHE);
        inOrderNodeLead(root->right);
    }
}
 
void postOrderNodeLead(NodeLeadPtr root){
    if(root != NULL)
    {
        postOrderNodeLead(root->left);
        postOrderNodeLead(root->right);
        printf("%d ", root->thongTinDocGia.MATHE);
    }
}
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
	return 0;
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
