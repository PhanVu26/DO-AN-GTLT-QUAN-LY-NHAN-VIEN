#pragma once
#include "Node.h"
#include "NhanVien.h"
class QLNV
{
public:
	Node *head;
public:
	bool IsEmpty();
	int Length(QLNV &);
	void Show_List(QLNV&l);
	void Add(NhanVien &nv);
	void InsertSort(NhanVien&);
	void Delete();
	void Delete_index_k(QLNV &, Node*);
	void DeleteByMaNV(QLNV &l,string maNv);
	void DeleteByAge(QLNV &);
	void SortAsc(QLNV &list);
	void SortDec(QLNV &list);
	void Sort(QLNV list);
	void HoanVi(NhanVien &a, NhanVien &b);
	QLNV TimkiemTheoTieuchi(string key,string);
	void Search(QLNV&);
	void TinhLuong(QLNV&);
	void TinhPhucap(NhanVien&);
	void TinhThuclinh(NhanVien&);
	QLNV();
	~QLNV();
};

