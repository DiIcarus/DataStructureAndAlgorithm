#include"MuonTra.h"
#include"menudong.h"
#include"docgia.h"
#include"myrandom.h"

menudong menuDong;
myio io;
docgia danhsachdocgia;
myrandom random;
int MangMaThe[1000];
int demSoLuongDocGia = 0;
void chucNang1();
void chucNang1_Them();
void chucNang1_Xoa();
void chucNang1_Sua();
void baiTap2();
void baiTap3();
void baiTap4();
void baiTap5();
void baiTap6();
void baiTap7();
void baiTap8();


int main() {
	random.initArr(MangMaThe);
	random.intRand(MangMaThe);
	danhsachdocgia.initNodeLead(danhsachdocgia.root);
	{
		bool loop = true;
		while (loop) {
			switch (menuDong.MenuDong(menuDong.thucDon.mainMenu,15))
			{
			case 1:
			{
				chucNang1();
				break;
			}
			case 2:
			{
				baiTap2();
				break;
			}
			case 3:
			{
				baiTap3();
				break;
			}
			case 4:
			{
				baiTap4();
				break;
			}
			case 5:
			{
				baiTap5();
				break;
			}
			case 6:
			{
				baiTap6();
				break;
			}
			case 7:
			{
				baiTap7();
				break;
			}
			case 8:
			{
				baiTap8();
				break;
			}
			case 9:
			{
				baiTap8();
				break;
			}
			case 10:
			{
				baiTap8();
				break;
			}
			case 11:
			{
				baiTap8();
				break;
			}
			case 12:
			{
				baiTap8();
				break;
			}
			case 13:
			{
				baiTap8();
				break;
			}
			case 14:
			{
				baiTap8();
				break;
			}
			case 15:
			{
				baiTap8();
				break;
			}
			case 0:
			{
				loop = false;
			}
			}
		}
	}
	return 1;
}
/////////////////////////////////////////////////////////////////////////////////////////////
void chucNang1() {
	bool loop = true;
	while (loop) {
		switch (menuDong.MenuDong(menuDong.thucDon.thucDonChucNang1,3))
		{
		case 1:
		{
			chucNang1_Them();
			break;
		}
		case 2:
		{
			chucNang1_Xoa();
			break;
		}
		case 3:
		{
			chucNang1_Sua();
			break;
		}
		}
	}
}

void chucNang1_Them() {
	danhsachdocgia.insertNodeLead(danhsachdocgia.root, danhsachdocgia.createdNodeLead(MangMaThe[demSoLuongDocGia]));
	demSoLuongDocGia++;
}
void chucNang1_Xoa() {
	danhsachdocgia.delNodeLead(danhsachdocgia.root, danhsachdocgia.createdNodeLead(-1));
	demSoLuongDocGia--;
}
void chucNang1_Sua() {

}
/////////////////////////////////////////////////////////////////////////////////////////////
void baiTap2() {

}
void baiTap3() {

}
void baiTap4(){}
void baiTap5(){}
void baiTap6(){}
void baiTap7(){}
void baiTap8(){
	cout << "88888888888";
	_getch();
}