#include "Person.h"
#include<iostream>
#include<iomanip>
using namespace std;


void Person::Nhap_Thong_Tin() {
	cout << "Nhap Ho nhan vien : ";
	getline(cin, this->ho);
	cout << "Nhap Ten nhan vien : ";
	getline(cin, this->ten);
	cout << "Nhap gioi : ";
	cin >> this->gioi_tinh;
	cout << "Nhap ngay sinh :";
	this->ngay_sinh.Nhap();
}

void Person::Hien_Thi_Thong_Tin() {
	cout << setw(10) << this->ho;
	cout << setw(10) << this->ten;
	if (this->gioi_tinh) {
		cout << setw(10) << "Nam";
	}
	else {
		cout << setw(10) << "Nu";
	}
	cout << setw(10);
	this->ngay_sinh.xuat();
}
Person::Person()
{
}

Person::Person(string ho,string ten,Date ns)
{
	this->ho = ho;
	this->ten = ten;
	this->ngay_sinh = ns;
}

Person::~Person()
{
}
