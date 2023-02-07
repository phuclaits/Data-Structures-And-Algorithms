#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <fstream>
#include "Buoi02_DSLK_Int.h"
using namespace std;
/******* Node ********/
//Phương thức thiết lập
Node::Node()
{
	info = 0;
	next = NULL;
}
//Tạo node chứa giá trị x
Node* createNode(int x)
{
	Node* p = new Node;

	if (p == NULL)
	{
		cout << "Not enough memory to allocate!";
		return NULL;
	}

	p->info = x;
	p->next = NULL;

	return p;
}
//Xóa node
void deleteNode(Node*& p)
{
	if (p == NULL)	return;

	p->next = NULL;
	delete p;
}
//Xuất nội dung nút
void showNode(Node* p)
{
	cout << p->info;
}

/***** SList ******/
//Khởi tạo DSLK
void init(SList& l)
{
	l.head = NULL;
	l.tail = NULL;
}
//Kiểm tra danh sách rỗng
bool isEmpty(SList l)
{
	return l.head == NULL;
}
//Duyệt danh sách để xuất nội dung ra màn hình
void traverse(SList l)
{
	if (isEmpty(l))
	{
		cout << "List is empty\n";
		return;
	}

	for (Node* p = l.head; p != NULL; p = p->next)
		cout << p->info << '\t';
}

//a. Nhập danh sách liên kết đơn từ file text chứa các số nguyên
void addTailSList(SList& l, Node* p)
{
	if (p == NULL) return;

	if (isEmpty(l))
		l.head = l.tail = p;
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
void inputSList(SList& l, const char* filename)
{
	ifstream in;
	in.open(filename);
	if (in)
	{
		while (!in.eof())
		{
			Node* p = new Node;
			in >> p->info;
			addTailSList(l, p);
		}
	}
	in.close();
}
//b. Delete the head node of SList
void deleteHeadSList(SList& l)
{
	if (l.head == NULL)
		return;
	else
	{
		Node* p = l.head;
		l.head = p->next;
		p->next = NULL;
		delete p;
	}
}
//c. Delete node p after node q of SList
//Delete the tail node of SList
void deleteTailList(SList& l)
{
	if (l.head == NULL)
		return;
	else
	{
		Node* p = l.tail;
		Node* q = l.head;
		if (p == q)//list has 1 element
		{
			l.head = l.tail = NULL;
			delete p;
		}
		else
		{
			//find the node located right before tail
			while (q->next != l.tail)
				q = q->next;
			l.tail = q;
			l.tail->next = NULL;
			delete p;
		}
	}
}
Node* searchSList(SList l, int x)
{
	for (Node* q = l.head; q != NULL; q = q->next)
		if (q->info == x)
			return q;
	return NULL;
}
void deleteMidSList(SList& l, Node* q)
{
	if (l.head == NULL || q == NULL || q == l.tail)//list is empty or q is NULL or list has 1 element
		return;
	else
	{
		if (q->next == l.tail)
			deleteTailList(l);
		else
		{
			Node* p = q->next;
			q->next = p->next;
			p->next = NULL;
			delete p;
		}
	}
}
//d.Xóa các phần tử có giá trị bằng x
void deleteXSlist(SList& l, int x)
{
	if (isEmpty(l))
		return;
	for (Node* q = l.head; q->next != NULL; q = q->next)
	{
		if ((q->info) == x)
		{
			deleteHeadSList(l);
			break;
		}
		else if ((q->next->info) == x)
		{
			deleteMidSList(l, q);
			break;
		}
	}

}
void deleteAllXSlist(SList& l, int x)//////////
{
	Node* p;
	while (p = searchSList(l, x))
		deleteXSlist(l, p->info);
}
//e. Xóa toàn bộ danh sách
void deleteSlist(SList& l)
{
	if (isEmpty(l))
		return;
	while (!isEmpty(l))
	{
		Node* p = l.head;
		l.head = l.head->next;
		delete p;
	}
	l.tail = NULL;
}
//f. Viết hàm xóa các phần tử chẵn trong dslk
Node* searchEvenSList(SList l)
{
	for (Node* q = l.head; q != NULL; q = q->next)
		if ((q->info) % 2 == 0)
			return q;
	return NULL;
}
void deleteEvenSList(SList& l)
{
	if (isEmpty(l))	return;
	Node* p;
	while ((p = searchEvenSList(l)) != NULL)
	{
		if (p == l.head)
			deleteHeadSList(l);
		else if (p == l.tail)
			deleteTailList(l);
		else
		{
			Node* q = l.head;
			while (q->next != p) q = q->next;
			deleteMidSList(l, q);
		}
	}
}


