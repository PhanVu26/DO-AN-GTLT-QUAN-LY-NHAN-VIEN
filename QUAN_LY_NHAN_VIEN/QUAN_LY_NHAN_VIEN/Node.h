#pragma once
#include "NhanVien.h"
class Node
{
public:
	NhanVien data;
	Node *next;
public:
	Node* MakeNode(NhanVien &nv);
	Node();
	~Node();
};

