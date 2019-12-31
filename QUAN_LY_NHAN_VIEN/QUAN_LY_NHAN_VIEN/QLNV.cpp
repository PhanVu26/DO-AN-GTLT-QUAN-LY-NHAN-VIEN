#include "QLNV.h"
#include <iomanip>
#include <ctime>
#include <iostream>
using namespace std;
QLNV::QLNV()
{
	this->head = NULL;
}

bool QLNV::IsEmpty() {
	return (head == NULL) ? true : false;
}
int QLNV::Length(QLNV &list) {
	int c = 0;
	Node *p = list.head;
	if (IsEmpty()) {
		return 0;
	}
	else {
		while (p) {
			c++;
			p = p->next;
		}
	}
	return c;
}
void QLNV::Add(NhanVien &nv) {
	Node *newNode = new Node();
	newNode->data = nv;
	newNode->next = this->head;
	this->head = newNode;
}
void QLNV::InsertSort(NhanVien &nv) {
	Node *p = this->head;
	Node *pre = this->head;
	Node *newNode = new Node();
	newNode->data = nv;
	while ((p != NULL) && (p->data.ma_NV.compare(nv.ma_NV) < 0)) {
		pre = p;
		p = p->next;
	}
	newNode->next = p;
	if (p != NULL) {
		if (head == p) {
			this->head = newNode;
		}
		else {
			pre->next = newNode;
		}
	}
}

void QLNV::Delete() {
	if (IsEmpty()) {
		cout << "Danh sach rong.";
	}
	else {
		head = head->next;
	}
}

void QLNV::Delete_index_k(QLNV &l, Node *t) {
	Node *after = l.head;  
	Node *before = NULL;
	while ((after != NULL) && (after != t))
	{ before = after;   
	after = after->next; }  
	if (after != NULL) {
		if (l.head == t)   l.head = t->next;// 1’  
		else  before->next = t->next;// 1    
		delete  t;
	}
}
void QLNV::DeleteByAge(QLNV &l) {

	time_t rawtime;
	struct tm timeinfo;  
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	Node *temp = NULL,*p = l.head;
	while ((p != NULL)) {
		if (((timeinfo.tm_year + 1900) - p->data.ngay_sinh.year) > 50) {
			temp = p;
			Delete_index_k(l, temp);
			p = l.head;
		}else
			p = p->next;
	}
}
void QLNV::DeleteByMaNV(QLNV &l,string maNV) {
	Node *p = l.head;
	while (p != NULL) {
		if (p->data.ma_NV.compare(maNV) == 0) {
			Delete_index_k(l, p); break;
		}else 
		p = p->next;
	}
}
void QLNV::Show_List(QLNV& list) {
	cout << "\n\n*******************************************   DANH SACH NHAN VIEN CONG TY   ***********************************************"<<endl;
	cout << setfill('_') << setw(125) << "_" << endl <<setfill(' ');
	cout << setw(3) << left << "STT";
	cout << setw(10) << left << "|Ma NV";
	cout << setw(12) << left << "|Ho";
	cout << setw(15) << left << "|Ten";
	cout << setw(11) << left << "|Gioi Tinh";
	cout << setw(13) << left << "|Ngay Sinh";
	cout << setw(10) << left << "|Chuc Vu";
	cout << setw(9) << left << "|Don Vi";
	cout << setw(13) << left << "|He So Luong";
	cout << setw(10) << left << "|Phu Cap";
	cout << setw(9) << left << "|Luong";
	cout << setw(11) << left << "|Thuc Linh"<< endl;
	cout << setfill('_') << setw(125) << "_"<<endl;
	Node *p = list.head;
	int c = 0;
	while (p) {
		c++;
		cout << setfill(' ');
		cout << setw(3) << left << c;
		cout << p->data << endl;
		p = p->next;
	}
}

QLNV QLNV::TimkiemTheoTieuchi(string key,string type) {
	Node *p = this->head;
	QLNV list;
	while (p != NULL) {
		if (type.compare("ma_NV") == 0) {
			if (p->data.ma_NV.compare(key) == 0) {
				list.Add(p->data);
			}
		}
		else if (type.compare("ten") == 0) {
			if (p->data.ten.compare(key) == 0) {
				list.Add(p->data);
			}
		}
		else {
			if (p->data.don_vi.compare(key) == 0) {
				list.Add(p->data);
			}
		}
		p = p->next;
	}
	return list;
}

void QLNV::Search(QLNV &list) {
	int key;
	bool ck = true;
	do {
		cout << "\n\n----------------------------" << endl;
		cout << "Lua chon tieu chi tim kiem." << endl;
		cout << "1. Tim kiem theo ma nhan vien" << endl;
		cout << "2. Tim kiem theo ten nhan vien" << endl;
		cout << "3. Tim kiem theo don vi" << endl;
		cout << "0. Thoat tim kiem." << endl;
		cout << "Nhap tieu chi can tim kiem :" << endl;
		cin >> key;
		switch (key)
		{
		case 1: {
			string maNV;
			cout << "Nhap ma nhan vien can tim kiem: ";
			cin >> maNV;
			cout << "\n\n-----------------------------KET QUA TIM KIEM--------------------------------" << endl;
			QLNV l = list.TimkiemTheoTieuchi(maNV, "ma_NV");
			list.Show_List(l);
			break;
		}
		case 2: {
			string ten;
			cout << "Nhap ten nhan vien can tim kiem: ";
			cin >> ten;
			cout << "\n\n-----------------------------KET QUA TIM KIEM--------------------------------" << endl;
			QLNV l = list.TimkiemTheoTieuchi(ten, "ten");
			list.Show_List(l);
			break;
		}
		case 3: {
			cin.ignore();
			string donvi = "";
			cout << "Nhap don vi nhan vien can tim kiem: ";
			getline(cin,donvi);
			cout << "\n\n-----------------------------KET QUA TIM KIEM--------------------------------" << endl;
			QLNV l = list.TimkiemTheoTieuchi(donvi, "donvi");
			list.Show_List(l);
			break;
		}
		case 0: {
			ck = false;
			break;
		}
		default:
		{
			cout << "Ban nhap khong hop le." << endl;
			break;
		}
		}
	} while (ck == true);
}


void QLNV::HoanVi(NhanVien &a, NhanVien &b) {
	NhanVien temp = a;
	a = b;
	b = temp;
}
void QLNV::SortAsc(QLNV &list) {
	Node *p, *q;
	for (p = list.head; p != NULL; p = p->next) {
		for (q = p->next; q != NULL; q = q->next) {
			if (p->data.ma_NV.compare(q->data.ma_NV) > 0) {
				HoanVi(p->data, q->data);
			}
		}
	}
}
void QLNV::SortDec(QLNV &list) {
	Node *p, *q;
	for (p = list.head; p != NULL; p = p->next) {
		for (q = p->next; q != NULL; q = q->next) {
			if (p->data.ma_NV.compare(q->data.ma_NV) < 0) {
				HoanVi(p->data, q->data);
			}
		}
	}
}
void QLNV::Sort(QLNV list) {
	int key;
	bool ck = true;
	do {
		cout << "\n\n----------------------------" << endl;
		cout << "Lua chon phuong an sap xep." << endl;
		cout << "1. Sap xep tang dan theo ma nhan vien" << endl;
		cout << "2. Sap xep giam dan theo ma nhan vien" << endl;
		cout << "0. Thoat sap xep." << endl;
		cout << "Nhap phuong an can sap xep :" << endl;
		cin >> key;
		switch (key)
		{
		case 1: {
			list.SortAsc(list);
			list.Show_List(list);
			break;
		}
		case 2: {
			list.SortDec(list);
			list.Show_List(list);
			break;
		}
		case 0: {
			ck = false;
			break;
		}
		default:
		{
			cout << "Ban nhap khong hop le." << endl;
			break;
		}
		}
	} while (ck == true);
}


void QLNV::TinhPhucap(NhanVien &nv) {
	if (nv.chuc_vu.compare("GD") == 0 || nv.chuc_vu.compare("PGD") == 0) {
		nv.phu_cap =  nv.luong * 0.4;
	}
	else if (nv.chuc_vu.compare("TP") == 0 || nv.chuc_vu.compare("PP") == 0) {
		nv.phu_cap =  nv.luong * 0.25;
	}
	else nv.phu_cap = 0;

}
void QLNV::TinhLuong(QLNV &list) {
	Node *p = list.head;
	while (p != NULL) {
		p->data.luong = p->data.he_so_luong * 850;
		TinhPhucap(p->data);
		TinhThuclinh(p->data);
		p = p->next;
	}
}
void QLNV::TinhThuclinh(NhanVien &nv) {
	nv.thuc_linh = nv.luong + nv.phu_cap;
}
QLNV::~QLNV()
{
}
