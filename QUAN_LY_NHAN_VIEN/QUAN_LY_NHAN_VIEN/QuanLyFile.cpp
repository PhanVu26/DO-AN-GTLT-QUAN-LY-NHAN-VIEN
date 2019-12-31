#include "QuanLyFile.h"
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;


QuanLyFile::QuanLyFile()
{
}


QuanLyFile::~QuanLyFile()
{
}


const string WHITESPACE = " \n\r\t\f\v";
string ltrim(const string& s)
{
	size_t start = s.find_first_not_of(WHITESPACE);
	return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string& s)
{
	size_t end = s.find_last_not_of(WHITESPACE);
	return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string& s)
{
	return rtrim(ltrim(s));
}



void QuanLyFile::GhiFile(QLNV list,string tenFile) {
	this->ofs.open(tenFile);
	cout << "\nGhi du lieu toi file.\n" << endl;
	ofs << setfill(' ');
	ofs << "***************************************DANH SACH NHAN VIEN CONG TY******************************************" << endl;
	ofs << setfill('-') << setw(108) << "-" << endl << setfill(' ');
	ofs << setw(3) << left << "STT";
	ofs << setw(10) << left << "|Ma NV";
	ofs << setw(12) << left << "|Ho";
	ofs << setw(15) << left << "|Ten";
	ofs << setw(13) << left << "|Gioi Tinh";
	ofs << setw(11) << left << "|Ngay Sinh";
	ofs << setw(10) << left << "|Chuc Vu";
	ofs << setw(9) << left << "|Don Vi";
	ofs << setw(13) << left << "|He So Luong";
	ofs << setw(10) << left << "|Phu Cap";
	ofs << setw(9) << left << "|Luong";
	ofs << setw(11) << left << "|Thuc Linh" << endl;
	Node *p = list.head;
	int c = 1;
	while (p) {
		ofs << "\n" << setw(3) << c++ << p->data;
		p = p->next;
	}
	this->ofs.close();
	cout << "\nGHI DU LIEU TOI FILE ListNhanVien.txt THANH CONG.\n" << endl;
}


void QuanLyFile::ParseDouble(string s, double &n) {
	stringstream str(s);
	str >> n;
}
void QuanLyFile::ParseInt(string s, int &n) {
	stringstream str(s);
	str >> n;
}
void QuanLyFile::DocFileNhanVien(NhanVien &nv) {
	string gt, ns, cv, dv, pc,hesoLuong, luong, tl, stt, d = "00", m = "00", y = "0000";
	getline(ifs, stt, '|');
	getline(ifs, nv.ma_NV, '|');
	getline(ifs, nv.ho, '|');
	getline(ifs, nv.ten, '|');
	getline(ifs, gt, '|');
	getline(ifs, ns, '|');
	getline(ifs, nv.chuc_vu, '|');
	getline(ifs, nv.don_vi, '|');
	getline(ifs, hesoLuong);

	nv.chuc_vu = trim(nv.chuc_vu);
	nv.ten = trim(nv.ten);
	nv.don_vi = trim(nv.don_vi);
	nv.ma_NV = trim(nv.ma_NV);
	gt = trim(gt);
	if (gt.compare("Nam") == 0) nv.gioi_tinh = true;
	else nv.gioi_tinh = false;

	ns = trim(ns);
	for (int i = 0; i < 2; i++) {

		d[i] = ns[i];
		m[i] = ns[i + 3];
		y[i] = ns[i + 6];
		y[i + 2] = ns[i + 8];
	}
	ParseDouble(hesoLuong, nv.he_so_luong);
	nv.luong = 0;
	nv.phu_cap = 0;
	nv.thuc_linh = 0;
	ParseInt(d, nv.ngay_sinh.day);
	ParseInt(m, nv.ngay_sinh.month);
	ParseInt(y, nv.ngay_sinh.year);
}
QLNV& QuanLyFile::DocFile(string tenFile) {
	this->ifs.open(tenFile);
	QLNV list;
	int c = 0;
	string title, line, header, newLine;
	getline(ifs, title);
	getline(ifs, line);
	getline(ifs, header);
	getline(ifs, newLine);
	while (!ifs.eof()) {
		{
			NhanVien nv;
			DocFileNhanVien(nv);
			list.Add(nv);
		}
	}
	this->ifs.close();
	return list;
}

void QuanLyFile::Thongke(QLNV list,int &soNVNam, int &soNVNu,double &tongThuclinh) {
	Node *p = list.head;
	while (p != NULL) {
		tongThuclinh += p->data.thuc_linh;
		if (p->data.gioi_tinh) {
			soNVNam++;
		}
		else soNVNu++;
		p = p->next;
	}
}

void QuanLyFile::GhifileThongke(string donvi,int soNVNam, int soNVNu, double tongThuclinh) {
	ofs << setw(10) << left << donvi << "|";
	ofs << setw(12) << left << soNVNam << "|";
	ofs << setw(10) << left << soNVNu << "|";
	ofs << setw(11) << left << tongThuclinh;
	ofs << "\n";
}

void QuanLyFile::ThongkeTheoDonvi(QLNV &list) {
	string donvi[3] = {"Ke toan","Nhan su","Quan ly"};
	string tenFile = "Thongke.txt";
	ofs.open(tenFile);
	ofs << setw(53) << "*******   BANG THONG KE THUC LINH THEO DON VI    *****\n\n";
	ofs << setw(10) << left << "Don vi";
	ofs << setw(13) << left << "|So NV Nam";
	ofs << setw(11) << left << "|So NV Nu";
	ofs << setw(15) << left << "|Tong Thuc Linh\n";
	double tongThuclinh = 0;
	int soNVNam = 0, soNVNu = 0;
	for (int i = 0; i < 3; i++) {
		Thongke(list.TimkiemTheoTieuchi(donvi[i],"donvi"), soNVNam, soNVNu, tongThuclinh);
		GhifileThongke(donvi[i],soNVNam, soNVNu, tongThuclinh);
		soNVNam = soNVNu = 0;
		tongThuclinh = 0;
	}
	ofs.close();
	cout << "\nGHI DU LIEU VAO FILE Thongke.txt THANH CONG.\n";

}
