#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
struct node{
	int data;
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
NODE *KhoiTaoNODE(int x)
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



void showDS(LIST l)
{
	printf("\nSHOW DANH SACH LIEN KET \n");
	for(NODE *k = l.pHead; k!= NULL; k=k->pNext)
	{
		printf("%d\t",k->data);
	}
}


int timMAX(LIST l)
{
	int max = l.pHead->data;
	for(NODE *k = l.pHead; k != NULL; k=k->pNext)
	{
		if(k->data > max)
		{
			max = k->data;
		}
	}
	return max;
}

int timMin(LIST l)
{
	int min = l.pHead->data;
	for(NODE *k = l.pHead; k != NULL; k=k->pNext)
	{
		if(k->data < min)
		{
			min = k->data;
		}
	}
	return min;
}

void themNodePsauNodeQ(LIST &l, NODE *p)
{
		int x;
		printf("Nhap vao gia tri Node q: ");
		scanf("%d",&x);
		NODE *q = KhoiTaoNODE(x);
		if(l.pHead->data == q->data && l.pHead->pNext == NULL)
		{
			ThemVaoCuoi(l,p);
		}
		else{
			for(NODE *k = l.pHead; k != NULL; k = k->pNext)
			{
				if(k->data == q->data)
				{
					
					NODE *h = KhoiTaoNODE(p->data);
					NODE *g = k->pNext ; //NODE TRUNG GIAN giu moi lien ket voi node sau 
					h->pNext = g; // cho cái 
					k->pNext = h;
				}
			}
		}
}

void themNodePtruocNodeQ(LIST &l, NODE *p)
{
		int x;
		printf("Nhap vao gia tri Node q: ");
		scanf("%d",&x);
		NODE *q = KhoiTaoNODE(x);
		if(l.pHead->data == q->data && l.pHead->pNext == NULL)
		{
			ThemVaoDau(l,p);
		}
		else{
			NODE *g = new NODE;
			for(NODE *k = l.pHead; k != NULL; k = k->pNext)
			{
				if(k->data == q->data)
				{
					NODE *h = KhoiTaoNODE(p->data);
					h->pNext = k;
					g->pNext = h;
				}
				g = k; // giu node truoc roi thuc hien bai toan them sau. 1 != 4 2!=4 3!=4 g lúc này = 3; 4=4 g = 3; vào if th?c hi?n
			}
		}
}

void sortTang(LIST &l)
{
	for(NODE *k = l.pHead; k != NULL ; k=k->pNext)
	{
		for(NODE *k2 = k->pNext; k2!= NULL ; k2=k2->pNext)
		{
			if(k->data > k2->data)
			{
				int tmp = k->data;
				k->data = k2->data;
				k2->data = tmp;
			}
		}
	}
}

int soNguyenTo(int soA)
{
    if (soA < 2)    
        return 0;

    for (int i = 2; i <= sqrt((float)soA); i ++)
    {
        if (soA%i==0)
        {
            return 0;
        }
    }
    return 1;
}


void checkSNT_DSLK(LIST l)
{
	int count = 0;
	for(NODE *k = l.pHead; k != NULL ; k=k->pNext)
	{
		if(soNguyenTo(k->data)){
			printf("\nSo nguyen to la so: %d",k->data);
			count++;
		}
	}
	if(count == 0)
	{
		printf("\nKhong co so nguyen to");
	}
	else{
		printf("\nCo %d so nguyen to trong DSLK ! ",count);
	}
}

int CheckSCP(int soB)
{
	int soC = sqrt(soB);
	if(soC*soC == soB)
		return 1;
}
void SumSCP_DSLK(LIST l)
{
	int sum = 0;
	for(NODE *k = l.pHead; k != NULL ; k=k->pNext)
	{
		if(CheckSCP(k->data))
		{
			sum += k->data;
		}
	}
	printf("\nTONG So Chinh Phuong trong DSLK la: %d",sum);
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

void XoaNodenamsauQ(LIST &l, NODE *q)
{
	for(NODE *k = l.pHead ; k != NULL ; k=k->pNext)
	{
		if(k->data == q->data)
		{
			NODE *g = k->pNext;
			k->pNext = g->pNext; // cap nhat moi lien ket giua node k voi node sau node q
			delete g;
		}
	}
}




int main(){
	LIST l;
	KhoiTao(l);
	int n;
	printf("Nhap so luong element: ");
	scanf("%d",&n);
	for(int i = 1; i<= n; i++)
	{
		int x;
		printf("Nhap gia tri so nguyen: ");
		scanf("%d",&x);
		NODE *p = KhoiTaoNODE(x);
		ThemVaoCuoi(l,p);
	}
	showDS(l);
	printf("\n\nGIA TRI LON NHAT TRONG DSLK: %d\n",timMAX(l));
	printf("\n\nGIA TRI NHO NHAT TRONG DSLK: %d\n",timMin(l));
	printf("\nThem Node P sau Node Q\n");
	int x;
	printf("Nhap vao gia tri Node p can them: ");
	scanf("%d",&x);
	NODE *p= KhoiTaoNODE(x);
	themNodePsauNodeQ(l,p);
	showDS(l);
	
	int u;
	printf("\nThem Node P truoc Node Q\n");
	printf("Nhap vao gia tri Node u can them: ");
	scanf("%d",&u);
	NODE *m= KhoiTaoNODE(u);
	themNodePtruocNodeQ(l,m);
	showDS(l);
	
	printf("\nSap Xep Tang Dan DSLK\n");
	sortTang(l);
	showDS(l);
	
	checkSNT_DSLK(l);
	SumSCP_DSLK(l);
	_getch();
	return 0;
	
}
















