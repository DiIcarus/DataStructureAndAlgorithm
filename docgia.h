#pragma once
#include "MuonTra.h"
#include"menudong.h"
#include"myIO.h"
#include "myrandom.h"
class docgia
{
public:
	myio io;
	menudong menu;
	struct DocGia {
		int MATHE;
		string Ho, Ten, Phai;
		bool trangThai;
		MuonTra *danhSachMuon;
	};

	struct NodeLead {
		DocGia thongTinDocGia;
		struct NodeLead *right, *left;
	};
	typedef struct NodeLead *NodeLeadPtr;
	NodeLeadPtr root;
	DocGia docGia;
	docgia();
	~docgia();
	NodeLeadPtr newNodeLead(void) {
		NodeLeadPtr p;
		p = new NodeLead;
		return p;
	}

	void initNodeLead(NodeLeadPtr &root) {
		root = NULL;
	}
	int isNodeLeadEmpty(NodeLeadPtr root) {
		return(root == NULL ? true : false);
	}
	/*int LeftOf( const int value, const node_t* root ){
	    return value < root->data;
	}
	int RightOf( const int value, const node_t* root ){
	    return value > root->data;
	}*/
	DocGia createdNodeLead(int maso) {
		DocGia taoDocGia;
		taoDocGia.trangThai = 1;
		cout << "\nNhap Ho:";
		taoDocGia.Ho = io.insertStyleName(10);
		cout << "\nNhap Ten:";
		taoDocGia.Ten = io.insertStyleName(10);
		if (io.char2int(menu.MenuDong(menu.thucDon.thucDonChonGioiTinh,2)) == 0) {
			taoDocGia.Phai = "Nu";
		}
		else {
			taoDocGia.Phai = "Nam";
		}
		taoDocGia.MATHE = maso;
		cout << "\nNhap hoan tat!";
		_getch();
		/*cout << "Ban co chac chan muon tao ??";
		switch (menu.MenuDong(menu.thucDon.thucDonYesNo,2))
		{
		case 0: {
			return NULL;
		}
		case 1: {
			return taoDocGia;
		}
		}*/
		return taoDocGia;
	}
	NodeLeadPtr makeNodeLead(DocGia reader) {
		NodeLeadPtr pointerNewNote = newNodeLead();
		pointerNewNote->thongTinDocGia = reader;
		try {
			pointerNewNote->left = NULL; pointerNewNote->right = NULL;
		}catch(exception e){
		}
		return pointerNewNote;
	}
	void insertNodeLead(NodeLeadPtr &root, DocGia reader) {
		NodeLeadPtr pointerNewNode = makeNodeLead(reader);
		NodeLeadPtr travelTree, nodeLeadEndOfTravel;
		if (root == NULL) {
			root = pointerNewNode;
		}
		else {
			travelTree = root;
			nodeLeadEndOfTravel = NULL;
			while (travelTree != NULL) {
				nodeLeadEndOfTravel = travelTree;
				if (reader.MATHE < travelTree->thongTinDocGia.MATHE) {
					travelTree = travelTree->left;
				}
				else {
					travelTree = travelTree->right;
				}
			}
			if (reader.MATHE < nodeLeadEndOfTravel->thongTinDocGia.MATHE) {
				nodeLeadEndOfTravel->left = pointerNewNode;
			}
			else {
				nodeLeadEndOfTravel->right = pointerNewNode;
			}
		}
	}
	void fixNodeLeadInfo(NodeLeadPtr &root){
		DocGia target = createdNodeLead(-1);
		NodeLeadPtr pointerForFixedNodeLead = searchNodeLead(root, target);
		cout << "\n||Sua thong tin||\n";
		string Variable;
		cout << "\nNhap Ho moi:";
		Variable = io.insertStyleName(10);
		pointerForFixedNodeLead->thongTinDocGia.Ho = Variable;
		cout << "\nNhap Ten moi:";
		Variable = io.insertStyleName(10);
		cout << "\nChon gioi tinh moi:";
		pointerForFixedNodeLead->thongTinDocGia.Ten = Variable;
		if (io.char2int(menu.MenuDong(menu.thucDon.thucDonChonGioiTinh, 2)) == 0) {
			Variable= "Nu";
		}
		else {
			Variable= "Nam";
		}
		pointerForFixedNodeLead->thongTinDocGia.Phai = Variable;
		cout << "\nBan co muon khoa the ??";
		if (io.char2int(menu.MenuDong(menu.thucDon.thucDonYesNo, 2)) == 0) {
			pointerForFixedNodeLead->thongTinDocGia.trangThai = 0;
		}
		else {
			pointerForFixedNodeLead->thongTinDocGia.trangThai = 1;
		}
	}
	NodeLeadPtr searchNodeLead(NodeLeadPtr root, DocGia reader)
	{
		NodeLeadPtr travelTree = root;
		while (travelTree != NULL)
		{
			if (travelTree->thongTinDocGia.MATHE == reader.MATHE) return travelTree;
			else if (reader.MATHE < travelTree->thongTinDocGia.MATHE) travelTree = travelTree->left;
			else travelTree = travelTree->right;
		}
		return NULL;//Khong tim thay
	}
	NodeLeadPtr leftMostNodeLead(const NodeLeadPtr nodeLeadPtr) {
		NodeLeadPtr leftMostNodeLeadPointer = nodeLeadPtr;
		while (leftMostNodeLeadPointer->left != NULL)
			leftMostNodeLeadPointer = leftMostNodeLeadPointer->left;
		return leftMostNodeLeadPointer;
	}
	int delNodeLead(NodeLeadPtr &root, DocGia reader) {
		NodeLeadPtr deletedNodeLeadPointer;
		NodeLeadPtr nodeLeadEndOfTravel;
		NodeLeadPtr swapedInfoNodeLeadPointer;
		deletedNodeLeadPointer = searchNodeLead(root, reader);
		nodeLeadEndOfTravel = NULL;
		if (deletedNodeLeadPointer == NULL) return 0;
		else {
			if ((deletedNodeLeadPointer->left != NULL) && (deletedNodeLeadPointer->right != NULL)) {
				//nut xoa co 2 nhanh con
				swapedInfoNodeLeadPointer = leftMostNodeLead(deletedNodeLeadPointer->right);
				deletedNodeLeadPointer->thongTinDocGia = swapedInfoNodeLeadPointer->thongTinDocGia;
				delete (deletedNodeLeadPointer);
			}
			else if ((deletedNodeLeadPointer->left != NULL) && (deletedNodeLeadPointer->right == NULL)) {
				//nut can xoa co mot nhanh con ben trai 
				swapedInfoNodeLeadPointer = deletedNodeLeadPointer;
				while (swapedInfoNodeLeadPointer->left != NULL) {
					swapedInfoNodeLeadPointer->thongTinDocGia = swapedInfoNodeLeadPointer->left->thongTinDocGia;
					swapedInfoNodeLeadPointer = swapedInfoNodeLeadPointer->left;
				}
				delete (swapedInfoNodeLeadPointer);
			}
			else if ((deletedNodeLeadPointer->left == NULL) && (deletedNodeLeadPointer->right != NULL)) {//nut can xoa co mot nhanh con ben trai
			   //nut can xoa co mot nhanh con ben phai
				swapedInfoNodeLeadPointer = deletedNodeLeadPointer;
				while (swapedInfoNodeLeadPointer->right != NULL) {
					swapedInfoNodeLeadPointer->thongTinDocGia = swapedInfoNodeLeadPointer->right->thongTinDocGia;
					swapedInfoNodeLeadPointer = swapedInfoNodeLeadPointer->right;
				}
				delete (swapedInfoNodeLeadPointer);
			}
			else {
				//nut can xoa la nut la
				delete (deletedNodeLeadPointer);
			}
			return 1;
		}
	}
	void preOrderNodeLead(NodeLeadPtr root) {
		if (root != NULL)
		{
			printf("%d ", root->thongTinDocGia.MATHE);
			preOrderNodeLead(root->left);
			preOrderNodeLead(root->right);
		}
	}

	void inOrderNodeLead(NodeLeadPtr root) {
		if (root != NULL)
		{
			inOrderNodeLead(root->left);
			printf("%d ", root->thongTinDocGia.MATHE);
			inOrderNodeLead(root->right);
		}
	}

	void postOrderNodeLead(NodeLeadPtr root) {
		if (root != NULL)
		{
			postOrderNodeLead(root->left);
			postOrderNodeLead(root->right);
			printf("%d ", root->thongTinDocGia.MATHE);
		}
	}
};

