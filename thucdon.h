#pragma once
#include<iostream>
using namespace std;
class thucdon
{
	
public:
	int so_item = 0;
	char mainMenu[15][50] = { "1. Tao day so ngau nhien    ",
							  "2. Nhap day tu file         ",
							  "3. Them ve dau danh sach    ",
							  "4. Liet ke day so           ",
							  "5. Xoa cac phan tu bang x   ",
							  "6. Them so vao ds co thu tu ",
							  "7. Loc phan tu trung        ",
							  "8. Dao nguoc danh sach      ",
							  "9. Xoa tren ds co thu tu    ",
							  "10.Ket thuc chuong trinh    ",
							  "11. Tao day so ngau nhien    ",
							  "12. Nhap day tu file         ",
							  "13. Them ve dau danh sach    ",
							  "14. Liet ke day so           ",
							  "15. Xoa cac phan tu bang x   "};
	char thucDonChucNang1[3][50] = {	"1. Them the doc gia	",
								"2. Xoa the doc gia		",
								"3. Sua the doc gia		" };
	char thucDonChonGioiTinh[3][50] = { "1. Nam	",
								"2. Nu		" };
	char thucDonYesNo[3][50] = { "1. Co	",
								"2. Khong		" };
	thucdon();
	~thucdon();
};

