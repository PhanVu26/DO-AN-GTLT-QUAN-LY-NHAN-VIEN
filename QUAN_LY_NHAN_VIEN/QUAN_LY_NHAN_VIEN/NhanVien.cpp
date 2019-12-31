#include "NhanVien.h"
#include <iostream>
#include <iomanip>
#define LUONG_CO_BAN  850;
using namespace std;


NhanVien::NhanVien() {
	this->ho = "Phan";
	this->ten = "Van Vu";
	this->ma_NV = "NV01";
	this->don_vi = "A";
	this->chuc_vu = "NV";
	this->he_so_luong = 0;
	this->luong = 0;
	this->phu_cap = 0;
	this->thuc_linh = 0;
}

NhanVien::NhanVien(string ma_NV, string don_vi, string chuc_vu, double he_so_luong) {
	this->ma_NV = ma_NV;
	this->ho = ho;
	this->ten = ten;
	this->gioi_tinh = gioi_tinh;
	this->ngay_sinh = ngay_sinh;
	this->don_vi = don_vi;
	this->chuc_vu = chuc_vu;
	this->he_so_luong = he_so_luong;
	this->luong = 0;
	this->phu_cap = 0;
	this->thuc_linh = 0;
}

ostream& operator << (ostream &o, NhanVien &nv) {
	char ch = '|';
	o << setfill(' ');
	o << ch << setw(9) << left << nv.ma_NV;
	o << ch << setw(11) << left << nv.ho;
	o << ch << setw(14) << left << nv.ten;
	if (!nv.gioi_tinh) {
		o << ch << setw(10) << left << "Nu";
	}
	else {
		o << ch << setw(10) << left <<  "Nam";
	}
	o << ch << left << nv.ngay_sinh;
	o << ch << setw(9) << left << nv.chuc_vu;
	o << ch << setw(8) << left << nv.don_vi;
	o << ch << setw(12) << left << nv.he_so_luong;
	o << ch << setw(9) << left << nv.phu_cap;
	o << ch << setw(8) << left << nv.luong;
	o << ch << setw(10) << left << nv.thuc_linh;
	return o;
}

istream& operator >> (istream &i, NhanVien &nv) {
	i.ignore();
	cout << "Nhap ma so nhan vien : ";
	getline(i, nv.ma_NV);
	cout << "Nhap Ho nhan vien : ";
	getline(i, nv.ho);
	cout << "Nhap Ten nhan vien : ";
	getline(i, nv.ten);
	cout << "Nhap gioi tinh (1: Nam, 0: Nu) :";
	cin >> nv.gioi_tinh;
	cin >> nv.ngay_sinh;
	i.ignore();
	cout << "Nhap don vi (Nhan su, Ke toan, Quan ly) : ";
	getline(i, nv.don_vi);
	cout << "Nhap chuc vu (GD, PGD, TP, PP, NV) : ";
	getline(i, nv.chuc_vu);
	cout << "Nhap he so luong : ";
	i >> nv.he_so_luong;
	i.ignore();
	nv.luong = 0;
	nv.phu_cap = 0;
	nv.thuc_linh = 0;
	return i;
}


void NhanVien::Nhap_Thong_Tin() {
	cout << "Nhap ma so nhan vien : ";
	getline(cin, this->ma_NV);
	cout << "Nhap Ho nhan vien : ";
	getline(cin, this->ho);
	cout << "Nhap Ten nhan vien : ";
	getline(cin, this->ten);
	cout << "Nhap gioi tinh : ";
	cin >> this->gioi_tinh;
	this->ngay_sinh.Nhap();
	cin.ignore();
	cout << "Nhap don vi : ";
	getline(cin, this->don_vi); 
	cout << "Nhap chuc vu : ";
	getline(cin, this->chuc_vu);
	cout << "Nhap he so luong : ";
	cin >>this->he_so_luong;
}

void NhanVien::Hien_Thi_Thong_Tin() {
	cout << setw(10) << this->ma_NV;
	cout << setw(10) << this->ho;
	cout << setw(10) << this->ten;
	if (this->gioi_tinh == 1) {
		cout << setw(20) << "Nu";
	}
	else {
		cout << setw(20) << "Nam";
	}
	cout << setw(25) << this->ngay_sinh;
	cout << setw(10) << this->chuc_vu;
	cout << setw(10) << this->don_vi;
	cout << setiosflags(ios::showpoint) << setprecision(1);
	cout << setw(10) << this->luong;
	cout << setw(10) << this->phu_cap;
	cout << setw(10) << this->thuc_linh << endl;
}

double NhanVien::Tinh_Luong() {
	return this->he_so_luong*LUONG_CO_BAN;
}
double NhanVien::Tinh_Phu_Cap() {
	if (this->chuc_vu.compare("GD") == 0 || this->chuc_vu.compare("PGD") == 0) {
		return this->luong * 0.4;
	}
	else if(this->chuc_vu.compare("TT") == 0 || this->chuc_vu.compare("PP") == 0){
		return this->luong * 0.25;
	}
	else return 0;
}
double NhanVien::Tinh_Thuc_linh() {
	return this->luong + this->phu_cap;
}
NhanVien::~NhanVien()
{
}
