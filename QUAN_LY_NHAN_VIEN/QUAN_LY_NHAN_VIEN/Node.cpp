#include "Node.h"

Node* Node::MakeNode(NhanVien &nv) {
	Node *p = new Node();
	p->data = nv;
	return p;
}
Node::Node()
{
	this->next = NULL;
}


Node::~Node()
{
	
}
