#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Buoi02_DSLK_BaiHat.h"
using namespace std;

BaiHat::BaiHat(const char* tenBH, const char* tenCS, const char* tenTG, int thoiLuong)
{
	strcpy(this->tenBH, tenBH);
	strcpy(this->tenTG, tenTG);
	strcpy(this->tenCS, tenCS);
	this->thoiLuong = thoiLuong;
}
////
NodeBH::NodeBH()
{
	strcpy(info.tenBH, "");
	strcpy(info.tenTG, "");
	strcpy(info.tenCS, "");
	info.thoiLuong = 0;
	next = NULL;
}
////
void initBH(SListBH& l)
{
	l.head = NULL;
	l.tail = NULL;
}
bool isEmpty(SListBH l)
{
	return l.head == NULL;
}
void addHeadSListBH(SListBH& l, NodeBH* p)
{
	if (p == NULL)	return;

	if (isEmpty(l))
		l.head = l.tail = p;
	else
	{
		p->next = l.head;
		l.head = p;
	}
}
void printContentBH(NodeBH* p)
{
	if (p != NULL)
	{
		cout << "Tên bài hát: " << p->info.tenBH << endl;
		cout << "Tên CS: " << p->info.tenCS << endl;
		cout << "Tên TG: " << p->info.tenTG << endl;
		cout << "Thời lượng: " << p->info.thoiLuong << endl;
		cout << endl;
	}
}
void traverse(SListBH l)
{
	if (isEmpty(l))
	{
		cout << "List is empty\n";
		return;
	}

	for (NodeBH* p = l.head; p != NULL; p = p->next)
		printContentBH(p);
}
void docListBH(SListBH& dsbh, const char* filename)
{
	int n = 0;
	ifstream in;
	in.open(filename);
	if (in)
	{
		in >> n;
		for (int i = 1; i <= n; i++)
		{
			NodeBH* p = new NodeBH;
			in >> p->info.tenBH;
			in >> p->info.tenCS;
			in >> p->info.tenTG;
			in >> p->info.thoiLuong;

			addHeadSListBH(dsbh, p);
		}
	}in.close();
}

NodeBH* searchSList(const SListBH& l, BaiHat bh)
{
	for (NodeBH* p = l.head; p != NULL; p = p->next)
		if ((strcmp(p->info.tenBH, bh.tenBH) == 0) && (strcmp(p->info.tenCS, bh.tenCS) == 0) && (strcmp(p->info.tenTG, bh.tenTG) == 0) && (p->info.thoiLuong == bh.thoiLuong))
			return p;
	return NULL;
}
void deleteHeadSList(SListBH& l)
{
	if (l.head == NULL)
		return;
	else
	{
		NodeBH* p = l.head;
		l.head = p->next;
		p->next = NULL;
		delete p;
	}
}
void deleteTailList(SListBH& l)
{
	if (l.head == NULL)
		return;
	else
	{
		NodeBH* p = l.tail;
		NodeBH* q = l.head;
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
void deleteMidSList(SListBH& l, NodeBH* q)
{
	if (l.head == NULL || q == NULL || q == l.tail)//list is empty or q is NULL or list has 1 element
		return;
	else
	{
		if (q->next == l.tail)
			deleteTailList(l);
		else
		{
			NodeBH* p = q->next;
			q->next = p->next;
			p->next = NULL;
			delete p;
		}
	}
}
void deleteSList(SListBH& l, BaiHat bh)
{
	if (isEmpty(l))
		return;
	for (NodeBH* q = l.head; q->next != NULL; q = q->next)
	{
		if ((q == l.head) && (strcmp(q->info.tenBH, bh.tenBH) == 0) && (strcmp(q->info.tenCS, bh.tenCS) == 0) && (strcmp(q->info.tenTG, bh.tenTG) == 0) && (q->info.thoiLuong == bh.thoiLuong))
		{
			deleteHeadSList(l);
			break;
		}
		else if ((strcmp(q->next->info.tenBH, bh.tenBH) == 0) && (strcmp(q->next->info.tenCS, bh.tenCS) == 0) && (strcmp(q->next->info.tenTG, bh.tenTG) == 0) && (q->next->info.thoiLuong == bh.thoiLuong))
		{
			deleteMidSList(l, q);
			break;
		}
	}

}
void interchangeAlphabeTenBHSList(SListBH l)
{
	for (NodeBH* p = l.head; p != l.tail; p = p->next)
		for (NodeBH* q = p->next; q != NULL; q = q->next)
			if (strcmp(p->info.tenBH, q->info.tenBH) > 0)
			{
				char tmp[51];
				strcpy(tmp, p->info.tenBH);
				strcpy(p->info.tenBH, q->info.tenBH);
				strcpy(q->info.tenBH, tmp);
			}
}
void interchangeAlphabeTenCSSList(SListBH l)
{
	for (NodeBH* p = l.head; p != l.tail; p = p->next)
		for (NodeBH* q = p->next; q != NULL; q = q->next)
			if (strcmp(p->info.tenCS, q->info.tenCS) < 0)
			{
				char tmp[51];
				strcpy(tmp, p->info.tenCS);
				strcpy(p->info.tenCS, q->info.tenCS);
				strcpy(q->info.tenCS, tmp);
			}
}