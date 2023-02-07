#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Buoi02_DSLK_QuanLyDiemSV.h"
using namespace std;

////////Phương thức thiết lập các CTDL
MonHoc::MonHoc()
{
	strcpy(maMH, "");
	strcpy(tenMH, "");
	soTC = 0;
	DTL = 0.0;
	DCK = 0.0;
	diemMH = 0.0;
}
NodeMH::NodeMH()
{
	next = NULL;
}
SListMH::SListMH()
{
	head = NULL;
	tail = NULL;
}
//////
SinhVien::SinhVien()
{
	strcpy(maSV, "");
	strcpy(hoDem, "");
	strcpy(tenSV, "");
	namSinh = 0;
	diemKQ = 0.0;
}
NodeSV::NodeSV()
{
	next = NULL;
}
SListSV::SListSV()
{
	head = NULL;
	tail = NULL;
}
/////
NodeMH* createNodeMH(MonHoc mh)
{
	NodeMH* p = new NodeMH;

	if (p == NULL)
	{
		cout << "Not enough memory to allocate!";
		return NULL;
	}

	strcpy(p->info.maMH, mh.maMH);
	strcpy(p->info.tenMH, mh.tenMH);
	p->info.soTC = mh.soTC;
	p->info.DTL = mh.DTL;
	p->info.DCK = mh.DCK;
	p->info.diemMH = mh.diemMH;

	p->next = NULL;

	return p;
}
NodeSV* createNodeSV(SinhVien sv)
{
	NodeSV* p = new NodeSV;

	if (p == NULL)
	{
		cout << "Not enough memory to allocate!";
		return NULL;
	}

	strcpy(p->info.maSV, sv.maSV);
	strcpy(p->info.hoDem, sv.hoDem);
	strcpy(p->info.tenSV, sv.tenSV);
	p->info.namSinh = sv.namSinh;

	//copy dsmh
	for (NodeMH* q = sv.dsmh.head; q != NULL; q = q->next)
		addTailSList(p->info.dsmh, q);
	p->info.diemKQ = sv.diemKQ;

	p->next = NULL;

	return p;
}
void showNodeMH(NodeMH* p)
{
	cout << "-----------Thông tin môn học------------" << endl;
	cout << "Mã môn học: " << p->info.maMH << endl;
	cout << "Tên môn học: " << p->info.tenMH << endl;
	cout << "Số tín chỉ: " << p->info.soTC << endl;
	cout << "Điểm tiểu luận: " << p->info.DTL << endl;
	cout << "Điểm cuối kỳ: " << p->info.DCK << endl;
	cout << "Điểm môn học: " << p->info.diemMH << endl;
}
void showNodeSV(NodeSV* p)
{
	cout << "/***********Thông tin sinh viên*********/" << endl;
	cout << "Mã sinh viên: " << p->info.maSV << endl;
	cout << "Họ tên SV: " << p->info.hoDem << " " << p->info.tenSV << endl;
	cout << "Năm sinh: " << p->info.namSinh << endl;
	cout << "Danh sách các môn học:\n";
	traverse(p->info.dsmh);
	cout << "Điểm kết quả học tập: " << p->info.diemKQ << endl;
	cout << "/**************************************/" << endl;
}
bool isEmpty(SListMH l)
{
	return l.head == NULL;
}
bool isEmpty(SListSV l)
{
	return l.head == NULL;
}
void traverse(SListMH l)
{
	if (isEmpty(l))
	{
		cout << "List is empty\n";
		return;
	}
	for (NodeMH* p = l.head; p != NULL; p = p->next)
		showNodeMH(p);
}
void traverse(SListSV l)
{
	if (isEmpty(l))
	{
		cout << "List is empty\n";
		return;
	}
	for (NodeSV* p = l.head; p != NULL; p = p->next)
		showNodeSV(p);
}
void addTailSList(SListMH& l, NodeMH* p)
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
void addTailSList(SListSV& l, NodeSV* p)
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
void addHeadSListSV(SListSV& l, NodeSV* p)
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
void addAfterNodeSVSList(SListSV& l, NodeSV* q, NodeSV* p)
{
	if (p == NULL)	return;
	else
	{
		if (q == NULL)
		{
			if (l.head == NULL)//list is empty
				l.head = l.tail = p;
			else//cannot find node q in list
				return;
		}
		else
		{
			if (q == l.tail)
				addTailSList(l, p);
			else
			{
				p->next = q->next;
				q->next = p;
			}
		}
	}
}
void interchangeAlphabeMaSVSList(SListSV l)
{
	for (NodeSV* p = l.head; p != l.tail; p = p->next)
		for (NodeSV* q = p->next; q != NULL; q = q->next)
			if (strcmp(p->info.maSV, q->info.maSV) > 0)
			{
				char tmp[51];
				strcpy(tmp, p->info.maSV);
				strcpy(p->info.maSV, q->info.maSV);
				strcpy(q->info.maSV, tmp);
			}
}
void interchangeAlphabeTenSVSList(SListSV l)
{
	for (NodeSV* p = l.head; p != l.tail; p = p->next)
		for (NodeSV* q = p->next; q != NULL; q = q->next)
			if (strcmp(p->info.tenSV, q->info.tenSV) > 0)
			{
				char tmp[51];
				strcpy(tmp, p->info.tenSV);
				strcpy(p->info.tenSV, q->info.tenSV);
				strcpy(q->info.tenSV, tmp);
			}
}
void deleteHeadSList(SListSV& l)
{
	if (l.head == NULL)
		return;
	else
	{
		NodeSV* p = l.head;
		l.head = p->next;
		p->next = NULL;
		delete p;
	}
}
void deleteTailList(SListSV& l)
{
	if (l.head == NULL)
		return;
	else
	{
		NodeSV* p = l.tail;
		NodeSV* q = l.head;
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
void deleteMidSList(SListSV& l, NodeSV* q)
{
	if (l.head == NULL || q == NULL || q == l.tail)//list is empty or q is NULL or list has 1 element
		return;
	else
	{
		if (q->next == l.tail)
			deleteTailList(l);
		else
		{
			NodeSV* p = q->next;
			q->next = p->next;
			p->next = NULL;
			delete p;
		}
	}
}
void deleteSList(SListSV& l, char* maSV)
{
	if (isEmpty(l))
		return;
	for (NodeSV* q = l.head; q->next != NULL; q = q->next)
	{
		if ((q == l.head) && (strcmp(q->info.maSV, maSV) == 0))
		{
			deleteHeadSList(l);
			break;
		}
		else if (strcmp(q->next->info.maSV, maSV) == 0)
		{
			deleteMidSList(l, q);
			break;
		}
	}

}