#include<stdio.h>
#include<iostream>
#include<conio.h>
#include <cstdlib> 
#include<fstream>

#define Max 100
using namespace std;
// khai bao 1 c�i struct Node 
struct Node
{
	int data;
	struct Node *pLeft;
	struct Node *pRight;
};
typedef struct Node NODE;
typedef  NODE* TREE;

// Khoi Tao Hang Doi
struct Queue{
	int Front, Rear;
	int data[Max];
	int count;
};
typedef struct Queue QUEUE;

void Init(QUEUE &q)
{
	q.Front = 0;
	q.Rear = -1;
	q.count = 0;
}

int Isempty (QUEUE q) //kiem tra Queue rong
{
    if (q.count == 0) //so phan tu = 0 => rong
        return 1;
    return 0;
}
 
int Isfull (QUEUE q) //kiem tra Queue day
{
    if (q.count == Max) //so phan tu = Max => day
        return 1;
    return 0;
}

void Push(QUEUE &q, int x) //them phan tu vao cuoi Queue
{
    if (Isfull(q)) printf("Hang doi day !");
    else
    { 
        q.data[++q.Rear] = x; //tang Rear len va gan phan tu vao
        q.count++; //tang so phan tu len
    }
}

int Pop(QUEUE &q) //Loai bo phan tu khoi dau hang doi
{
    if (Isempty(q)) printf("Hang doi rong !");
    else
    {
        int x = q.data[q.Front];
        for (int i=q.Front; i<q.Rear; i++) //di chuyen cac phan tu ve dau hang
            q.data[i] = q.data[i+1];
        q.Rear--; // giam vi tri phan tu cuoi xuong
        q.count--;//giam so phan tu xuong
        return x; //tra ve phan tu lay ra
    }
}

// khoi tao cay
void KhoiTaoCay(TREE &t)
{
	t =NULL ;
}

// ham them phan tu  x vao cay
void ThemNodeVaoCay(TREE &t, int x)
{
	if( t == NULL)
	{
		NODE *p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else
	{
		if(t->data > x)
		{
			ThemNodeVaoCay(t->pLeft, x);
		}
		else if(t->data < x )
		{
			ThemNodeVaoCay(t->pRight, x);
		}
	}
}
void Duyet_NLR(TREE t)
{
	if(t != NULL)
	{
		printf("\t%d",t->data);
		Duyet_NLR(t->pLeft);
		Duyet_NLR(t->pRight);
	}
}
void Duyet_NRL(TREE t)
{
	if( t!= NULL)
	{
		printf("\t%d",t->data);
		Duyet_NRL(t->pRight);
		Duyet_NRL(t->pLeft);
	}	
}

void show(TREE t)
{
	printf("\t%d",t->data);
}
// duyet theo LNR tro thanh bai toan sap xep tu be den lon
void Duyet_LNR(TREE t)
{
	if( t!= NULL)
	{
		Duyet_LNR(t->pLeft);
		printf("\t%d",t->data);
		Duyet_LNR(t->pRight);
	}
}
void Duyet_RNL(TREE t)
{
	if(t != NULL)
	{
		Duyet_RNL(t->pRight);
		printf("\t%d",t->data);
		Duyet_RNL(t->pLeft);
	}
}
void Duyet_LRN(TREE t)
{
	if(t != NULL)
	{
		Duyet_RNL(t->pLeft);
		Duyet_RNL(t->pRight);
		printf("\t%d",t->data);
	}	
}
void Duyet_RLN(TREE t)
{
	if(t != NULL)
	
	{
		Duyet_RNL(t->pRight);
		Duyet_RNL(t->pLeft);
		printf("\t%d",t->data);
	}
}
int DemSoNutLa(TREE t)
{
	
	if(t == NULL)
	{
		return 0;
	}
	if(t->pLeft == NULL && t->pRight == NULL)
	{
		return 1;
	}
		return DemSoNutLa(t->pLeft) + DemSoNutLa(t->pRight);
}

int insertTNodeLeft(TREE t, NODE *p)
{
	if(t == NULL || p == NULL)
	{
		return 0;
	}
	if(t->pLeft != NULL) return 0;
	t->pLeft =p;
	return 1;
}

int insertTNodeRight(TREE t, NODE *p)
{
	if(t == NULL || p == NULL)
	{
		return 0;
	}
	if(t->pRight != NULL) return 0;
	t->pRight =p;
	return 1;
}

void LonHonX(TREE t, int q)
{
	if(t == NULL)
	{
		return;
	}
	if(t->data > q)
	{
		printf("\t%d",t->data);	
	}
	LonHonX(t->pLeft,q);
	LonHonX(t->pRight,q);
}

int ThemNutVaoCay(TREE t, NODE* p)
{
	if(p == NULL) return 0;
	if(t == NULL)
	{
		t = p;
		return 1;
	}
	else
	{
		int x = rand() % 2;
		if(x == 0)
		{
			ThemNutVaoCay(t->pLeft,p);
		}
		else
		{
			ThemNutVaoCay(t->pRight,p);
		}
	}
	return 1;
}


void TimKiem(TREE t, int p)
{
	if(t == NULL)
	{
		return;
	}
	if(t->data == p)
	{
		printf("\n\t\tCo Node %d trong cay",p);
	}	
	TimKiem(t->pLeft,p);
	TimKiem(t->pRight,p);	
}
int count(TREE t)
{
	if(!t) return 0;
	int nl = count(t->pLeft);
	int nr = count(t->pRight);
	return (1+nl+nr);
}
int SumTREE(TREE t)
{
	if(t == NULL) return 0;
	int suml = SumTREE(t->pLeft);
	int sumr = SumTREE(t->pRight);
	return suml+ sumr + t->data;
}
int ChieuCao(TREE t)
{
	if(t == NULL) return 0;
	int hl = ChieuCao(t->pLeft);
	int hr = ChieuCao(t->pRight);
	if(hl > hr)
	{
		return hl +1;
	}
	else
	{
		return hr + 1;
	}
}
NODE* find(TREE t, int x)
{
	if(t== NULL) return NULL;
	if(t->data == x)
	{
		return t;
	}
	NODE* p = find(t->pLeft,x);
	if(p!=NULL)
	{
		return p;
	}
	return find(t->pRight,x);
}



void Doc_Du_Lieu_Tu_File(TREE &t, ifstream &in)
{
	int n;
	in >> n;
	for(int i = 0 ; i < n; i++)
	{
		int x;
		in >> x;
		ThemNodeVaoCay(t,x);
	}
}





void MENU(TREE &t)
{
	
	while(true)
	{
		system("cls");
		printf("\n\t\t======================MENU===================");
		printf("\n\t\t|0. Thoat Chuong Trinh                       |");
		printf("\n\t\t|1. Nhap Du Lieu                             |");
		printf("\n\t\t|2. Duyet Cay theo NLR                       |");
		printf("\n\t\t|3. Duyet Cay theo NRL                       |");
		printf("\n\t\t|4. Duyet Cay theo LNR                       |");
		printf("\n\t\t|5. Duyet Cay theo RNL                       |");
		printf("\n\t\t|6. Duyet Cay theo LRN                       |");
		printf("\n\t\t|7. Duyet Cay theo RLN                       |");
		printf("\n\t\t|8. Dem so nut la                            |");
		printf("\n\t\t|9. In Ra Lon Hon X                          |");
		printf("\n\t\t|10. Tim Kiem phan tu X co trong cay ko?     |");
		printf("\n\t\t|11. Dem So nut tren cay.                    |");
		printf("\n\t\t|12. Sum TNODE.                              |");
		printf("\n\t\t|13. Chieu Cao Cua Cay                       |");
		printf("\n\t\t|14. Doc du lieu Mang 1 Chieu                |");
		printf("\n\t\t|15. Doc du lieu tu File                     |");
		printf("\n\t\t|16. Them Node vao ben Trai                  |");
		printf("\n\t\t|17. Them Node vao ben Phai                  |");
		printf("\n\t\t|18. Them Node Vao Cay                       |");
		printf("\n\t\t=============================================");
		int luachon;
		printf("\nNhap Lua Chon: ");
		scanf("%d",&luachon);
		if(luachon <0 || luachon > 100)
		{
			printf("\n LUA CHON KO HOP LE!");
		}
		else if(luachon == 1)
		{
			int x;
			printf("\nNhap vao so nguyen X: ");
			scanf("%d",&x);
			ThemNodeVaoCay(t,x);	
		}
		else if(luachon == 2)
		{
			printf("\n\t\tDUYET CAY THEO NLR\n");
			Duyet_NLR(t);
			_getch();
		}
		else if(luachon == 3)
		{
			printf("\n\t\tDUYET CAY THEO NRL\n");
			Duyet_NRL(t);
			_getch();
		}
		else if(luachon == 4)
		{
			printf("\n\t\tDUYET CAY THEO LNR\n");
			Duyet_LNR(t);
			_getch();
		}
		else if(luachon == 5)
		{
			printf("\n\t\tDUYET CAY THEO RNL\n");
			Duyet_RNL(t);
			_getch();
		}
		else if(luachon == 6)
		{
			printf("\n\t\tDUYET CAY THEO LRN\n");
			Duyet_LRN(t);
			_getch();
		}
		else if(luachon == 7)
		{
			printf("\n\t\tDUYET CAY THEO RLN\n");
			Duyet_RLN(t);
			_getch();	
		}
		else if(luachon == 8)
		{
			printf("\nCo %d so nut la\n",DemSoNutLa(t));
			_getch();
		}
		else if(luachon == 9)
		{
			int q;
			printf("Nhap vao Q: ");
			scanf("%d",&q);
			printf("\n In ra phan tu lon hon Q \n");
			LonHonX(t,q);
			_getch();	
		}
		else if(luachon == 10)
		{
			
			int p;
			printf("\nNhap vao phan tu can tim: ");
			scanf("%d",&p);
			TimKiem(t,p);
			_getch();
		}
		else if(luachon == 11)
		{
			//printf("Co %d Nut trong Cay",count(t));
			find(t,5);
			_getch();
		}
		else if(luachon == 12)
		{
			printf("\nSum Tree: %d", SumTREE(t));
			_getch();
		}
		else if(luachon == 13)
		{
			printf("\nChieu Cao Cua Cay la: %d",ChieuCao(t));
			_getch();
		}
		else if(luachon == 14)
		{
			int a[100]= {10,42,5,7,19,22,11,9,-5,-7,1,2,13};
			for(int i = 0; a[i] != NULL ; i++)
			{
				ThemNodeVaoCay(t,a[i]);
			}
			_getch();
		}
		else if(luachon == 15)
		{
			ifstream in;
			in.open("Data1.txt",ios_base::in);
			Doc_Du_Lieu_Tu_File(t,in);
			int n;
			in >> n;
			in.close();
		}
		else if(luachon == 16)
		{
			TREE p;
			p->data = 5;
			insertTNodeLeft(t,p);
			_getch();
		}
		else if(luachon == 17)
		{
			show(t);	
			_getch();
		}
		
		
		
		
		
		
		else if(luachon == 0)
		{
			break;
		}
	}
}


int main()
{
	TREE t;
	KhoiTaoCay(t);
	
	MENU(t);
	system("pause");
	return 0;
}












