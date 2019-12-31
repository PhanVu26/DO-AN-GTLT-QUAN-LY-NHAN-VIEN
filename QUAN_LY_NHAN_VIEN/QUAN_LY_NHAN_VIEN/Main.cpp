#include<iostream>
#include<fstream>
#include "NhanVien.h"
#include"QLNV.h"
#include <iomanip>
#include <string>
#include <sstream>
#include"QuanLyFile.h"
using namespace std;

void ShowMenu() {
	cout << endl << endl;
	cout << "--------------------------MENU----------------------------" << endl;
	cout << "1. Them nhan vien vao dau danh sach." << endl;
	cout << "2. Xoa nhan vien theo ma so nhan vien." << endl;
	cout << "3. Tim kiem nhan vien theo cac tieu chi khac nhau." << endl;
	cout << "4. Sap xep danh sach nhan vien." << endl;
	cout << "5. Hien thi danh sach nhan vien." << endl;
	cout << "6. Them nhan vien dam bao thu tu tang dan theo ma nhan vien." << endl;
	cout << "7. Xoa nhan vien co tuoi > 50." << endl;
	cout << "8. Tinh luong, phu cap va thuc linh cua nhan vien." << endl;
	cout << "9. Thong ke thuc linh theo don vi." << endl;
	cout << "0. Thoat." << endl;
}

int main() {
	string NVFile = "ListNhanVien.txt";
	NhanVien nv,nv2,nv3,nv4;
	QLNV listNV;
	int selection;
	QuanLyFile qf;
	listNV = qf.DocFile(NVFile);
	bool bl = true;
	do {
		ShowMenu();
		cout << "Nhap lua chon cua ban : ";
		cin >> selection;
		switch (selection)
		{
		case 1:
		{
			cin >> nv;
			QLNV result = listNV.TimkiemTheoTieuchi(nv.ma_NV,"ma_NV");
			if (result.head != NULL) {
				cout << "\nError!!! Ma nhan vien da ton tai\n";
				break;
			}
			else {
				listNV.Add(nv);
				cout << "\nTHEM NHAN VIEN THANH CONG\n";
				listNV.Show_List(listNV);
			}
			break;
		}
		case 2:
		{
			string maNV;
			cout << "Nhap ma NV can xoa : ";
			cin >> maNV;
			listNV.DeleteByMaNV(listNV,maNV);
			cout << "\nXOA NHAN VIEN THANH CONG\n";
			listNV.Show_List(listNV);
			break;
		}
		case 3:
		{
			listNV.Search(listNV);
		
			break;
		}
		case 4:
		{
			listNV.Sort(listNV);
			cout << "\nSAP XEP THANH CONG\n";
			listNV.Show_List(listNV);
			break;
		}
		case 5: {
			listNV.Show_List(listNV);
			break;
		}
		case 6: {
			NhanVien nv;
			cin >> nv;
			listNV.SortAsc(listNV);
			listNV.InsertSort(nv);
			cout << "\nTHEM NHAN VIEN THANH CONG\n";
			listNV.Show_List(listNV);
			break;
		}
		case 7: {
			listNV.DeleteByAge(listNV);
			cout << "\nXOA NHAN VIEN THANH CONG\n";
			listNV.Show_List(listNV);
			break;
		}
		case 8: {
			listNV.TinhLuong(listNV);
			listNV.Show_List(listNV);
			break;
		}
		case 9: {
			listNV.TinhLuong(listNV);
			qf.ThongkeTheoDonvi(listNV);
			break;
		}
		case 0:
		{
			qf.GhiFile(listNV, NVFile);
			bl = false;
			break;
		}
		default:
			cout << "Ban nhap khong hop le." << endl;
			break;
		}
	} while (bl == true);
	system("pause");
	return 0;
}