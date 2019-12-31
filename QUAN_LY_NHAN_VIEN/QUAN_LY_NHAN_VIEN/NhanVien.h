#pragma once
#include<iostream>
#include<string>
#include "Person.h"
using namespace std;
class NhanVien:public Person 
{
	friend class QLNV;
	friend class QuanLyFile;
	friend int main();
	string ma_NV;
	string don_vi;
	string chuc_vu;
	double he_so_luong;
	double luong;
	double phu_cap;
	double thuc_linh;

public:
	friend void DocFileNhanVien(ifstream&, NhanVien&);
	friend ostream& operator << (ostream &, NhanVien &);
	friend istream& operator >> (istream &, NhanVien &);
	void Nhap_Thong_Tin();
	void Hien_Thi_Thong_Tin();
	double Tinh_Phu_Cap();
	double Tinh_Thuc_linh();
	double Tinh_Luong();
	NhanVien();
	NhanVien(string ma_NV, string don_vi, string chuc_vu, double he_so_luong);
	~NhanVien();
};

