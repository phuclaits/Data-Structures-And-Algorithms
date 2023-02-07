#include<iostream>
using namespace std;
#include<string.h>
#include<fstream>
#include<stdio.h>
#include<math.h>
// khai bao 

struct Element
{
	int pt;
	
};
typedef struct Element ELEMENT;

struct node{
	ELEMENT data;
	node* pNext;
};
typedef struct node NODE;


struct list{
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;

// ========================= khoitao

void KhoiTao(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

// =============== khoitao node
NODE *KhoiTaoNODE(ELEMENT x)
{
	NODE *p = new NODE;
	if(p==NULL)
	{
		printf("KO DU BO NHO DE CAP PHAT !");
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

void ThemVaoDau(LIST &l, NODE *p)
{
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else{
		p->pNext = l.pHead;
		l.pHead = p;
	}	
}

void ThemVaoCuoi(LIST &l, NODE *p)
{
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else{
		l.pTail->pNext = p;
		l.pTail = p; // cap nhat lai p la node cuoi
	}	
}

void Doc_Du_Lieu_Tu_File(ifstream &filein, ELEMENT &ele)
{
	filein >> ele.pt;
}

void Xuat_Doc_File(ELEMENT ele)
{
	cout<< "\t"<< ele.pt;
}

void Doc_ALL(ifstream &filein,LIST &l)
{
	// doc den cuoi file thj dung 
	while(!filein.eof())
	{
		//doc tt
		ELEMENT ele;
		Doc_Du_Lieu_Tu_File(filein,ele);
		// khoi tao gan node zo
		NODE *p = KhoiTaoNODE(ele);
		//tHEM vao DS
		ThemVaoCuoi(l,p);
	}
}

void Xuat_DS_ALL(LIST l)
{
	for(NODE *k = l.pHead; k!= NULL ; k=k->pNext)
	{
		Xuat_Doc_File(k->data);
	}
}

void XoaDau(LIST &l)
{
	if(l.pHead == NULL)
	{
		return;
	}
	else
	{
		NODE *p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;		
	}
}

void XoaCuoi(LIST &l)
{
	if(l.pHead == NULL)
	{
		return;
	}
	else
	{
		for(NODE *k = l.pHead; k!= NULL; k=k->pNext)
		{
			if(k->pNext == l.pTail)
			{
				delete l.pTail;
				k->pNext = NULL;
				l.pTail = k;
			}
		}
	}
}

void XoaChan(LIST &l)
{
	if(l.pHead == NULL)
	{
		return;
	}
	else if(l.pHead->data % 2 == 0)
	{
		XoaDau(l);
	}
	else
	{
		for(NODE *k = l.pHead; k!= NULL; k=k->pNext)
		{
			if(k->data % 2 == 0)
			{
				delete l.pTail;
				k->pNext = NULL;
				l.pTail = k;
			}
		}
	}
}


int main()
{
	LIST l;
	KhoiTao(l);
	// mo file len 
	ifstream filein;
	filein.open("Databai1.TXT",ios::in);
	Doc_ALL(filein,l);
	XoaCuoi(l);
	Xuat_DS_ALL(l);
	printf("\n");
	filein.close();
	system("pause");
	return 0;
}










