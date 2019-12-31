#pragma once
#include<string>
#include <iostream>
#include "Date.h"
using namespace std;
class Person
{
protected:
	string ho;
	string ten;
	bool gioi_tinh;
	Date ngay_sinh;

public:
	void Nhap_Thong_Tin();
	void Hien_Thi_Thong_Tin();
	Person();
	Person(string ho, string ten, Date ngay_sinh);
	~Person();
};

