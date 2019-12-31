#pragma once
#include<iostream>
using namespace std;
class Date
{
public:
	int day, month, year;
public:
	friend ostream& operator << (ostream &o, const  Date &d);
	friend istream& operator >> (istream &i, Date &d);
	void Nhap();
	void xuat();
	bool Kt_NamNhuan(int y);
	Date(int day = 1,int month = 1,int year = 2001);
	~Date();
};

