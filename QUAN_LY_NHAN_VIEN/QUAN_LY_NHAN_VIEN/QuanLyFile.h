#pragma once
#include "QLNV.h"
#include<fstream>
#include "NhanVien.h"
class QuanLyFile
{
	ifstream ifs;
	ofstream ofs;
public:
	void GhiFile(QLNV list,string tenFile);
	QLNV& DocFile(string tenFile);
	void DocFileNhanVien(NhanVien &nv);
	void ParseDouble(string, double&);
	void ParseInt(string, int&);
	void Thongke(QLNV list, int &soNVNam, int &soNVNu,double&);
	void ThongkeTheoDonvi(QLNV &list);
	void GhifileThongke(string, int, int, double);
	QuanLyFile();
	~QuanLyFile();
};

