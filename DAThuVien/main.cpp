#include"MuonTra.h"
#include"menudong.h"
#include"docgia.h"
#include"myrandom.h"
#include"dausach.h"
#include"myIO.h"

menudong menuDong;
myio io;
dausach danhsacgdausach;
docgia danhsachdocgia;
myrandom random;
int MangMaThe[1000],MangMaSach[1000];
int demSoLuongDocGia = 0;
int demSoLuongMaSach = 0;
void chucNang1();
void chucNang1_Them();
void chucNang1_Xoa();
void chucNang1_Sua();
void chucNang2();
void chucNang3(dausach danhsacgdausach);
void chucNang4();
void chucNang5();
void chucNang6();
void chucNang7();
void chucNang8();
void chucNang9();
void chucNang10();
void chucNang11();


int main() {
	random.initArr(MangMaThe);
	random.intRand(MangMaThe);
	random.initArr(MangMaSach);
	random.intRand(MangMaSach);
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
				chucNang2();
				break;
			}
			case 3:
			{
				chucNang3(danhsacgdausach);
				break;
			}
			case 4:
			{
				chucNang4();
				break;
			}
			case 5:
			{
				chucNang5();
				break;
			}
			case 6:
			{
				chucNang6();
				break;
			}
			case 7:
			{
				chucNang7();
				break;
			}
			case 8:
			{
				chucNang8();
				break;
			}
			case 9:
			{
				chucNang9();
				break;
			}
			case 10:
			{
				chucNang10();
				break;
			}
			case 11:
			{
				chucNang11();
				break;
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
	cout << "\nDa xoa xong!!";
	_getch();
}
void chucNang1_Sua() {

}
/////////////////////////////////////////////////////////////////////////////////////////////
void chucNang2() {}
/////////////////////////////////////////////////////////////////////////////////////////////
void chucNang3(dausach danhsacgdausach) {
	danhsacgdausach.createdPointerArr(danhsacgdausach.danhSachDauSach, io.int2String(MangMaSach[demSoLuongMaSach]));
}
/////////////////////////////////////////////////////////////////////////////////////////////
void chucNang4() {}
void chucNang5() {}
void chucNang6() {}
void chucNang7() {}
void chucNang8() {}
void chucNang9() {}
void chucNang10() {}
void chucNang11() {}