#include "Date.h"
#include<iostream>
#include<string>
#include <iomanip>
using namespace std;

ostream& operator << (ostream &o, const Date &d) {
	char ch = '/';
	if (d.day < 10) {
		o << setfill('0') << "0" << d.day << ch;
	}else o << d.day << ch;
	if (d.month < 10) {
		o << setfill('0') << "0" << d.month <<ch;
	}
	else o << setfill(' ') << d.month <<ch;
	o << d.year << "  ";
	o << setfill(' ');
	return o;
}
istream& operator >> (istream &i, Date &d) {
	char ch = '/';
	int day_of_months[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	do {
		try
		{
			cout << "Nhap ngay thang nam theo dinh dang (dd/mm/yyyy) : ";
			i >> d.day >> ch >> d.month >> ch >> d.year;
			if (ch != '/') {
				throw "Loi dinh dang.";
			}
			if ((d.day < 0 || d.day > 31) || (d.day > day_of_months[d.month - 1])) {
				throw "Ngay khong hop le.";
			}
			if (d.month < 0 || d.month>12) {
				throw "Thang khong hop le.";
			}
			if (d.year < 0) {
				throw "Nam khong hop le.";
			}
		}
		catch (const char *s)
		{
			cout << s << endl;
		}
	} while (ch != '/' || (d.day < 0 || d.day>31) || 
		(d.month < 0 || d.month>12) || (d.year < 0) || 
		(d.day > day_of_months[d.month - 1]));
	return i;
}
Date::Date(int day,int month,int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}
bool Date::Kt_NamNhuan(int y) {
	return ((y % 400 == 0) || ((y % 4 == 0) && (y % 100 == 0))) ? true : false;
}
void Date::Nhap() {
	char ch = '/';
	int day_of_months[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	do {
		try
		{
			cout << "Nhap ngay thang nam theo dinh dang (dd/mm/yyyy) : ";
			cin >> this->day >> ch >> this->month >> ch >> this->year;
			if (ch != '/') {
				throw "Loi dinh dang.";
			}
			if ((day < 0 || day > 31) || (day > day_of_months[this->month - 1])) {
				throw "Ngay khong hop le.";
			}
			if (month < 0 || month>12) {
				throw "Thang khong hop le.";
			}
			if (year < 0) {
				throw "Nam khong hop le.";
			}
		}
		catch (const char *s)
		{
			cout << s << endl;
		}
	} while (ch != '/' || (day < 0 || day>31) || (month < 0 || month>12) || (year < 0) || (day > day_of_months[this->month - 1]));
}
void Date::xuat() {
	char ch = '/';
	cout << day << ch << month << ch << year;
}
Date::~Date()
{
}
