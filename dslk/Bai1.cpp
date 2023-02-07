#include<iostream>
using namespace std;
#include<string.h>
#include<fstream>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<iomanip>

struct CuonSach
{
	char MaSach[10];
	char TenSach[10];
	int SoTrang;
	float GiaBan;
	int NamXuatBan;	
};
typedef struct CuonSach SACH;

struct node{
	SACH data;
	node* pNext;
};
typedef struct node NODE;


struct list{
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;

void KhoiTao(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

// =============== khoitao node
NODE *KhoiTaoNODE(SACH x)
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

void Doc_Du_Lieu_Tu_File(LIST &l)
{
	int n;
	ifstream in;
	in.open("DataBai12.TXT", ios::in);
	in >> n;
	in.ignore();
	for(int i = 0 ; i <n ; i++)
	{
		SACH x;
		in.getline(x.MaSach, 10);
		in.getline(x.TenSach, 30);
		in >> x.SoTrang;
		in >> x.GiaBan;
		in >> x.NamXuatBan;
		in.ignore(2); // ham dich sang phai 2 ky tu
		NODE *p = KhoiTaoNODE(x);
		ThemVaoCuoi(l,p);
		l.pTail->pNext = NULL;
	}
	in.close();
}


void Show(LIST l,SACH x )
{
	for(NODE *k = l.pHead; k!= NULL ; k=k->pNext)
	{
		cout<< "Ma Sach la: "<< k->data.MaSach;
		cout<< "\nTen Sach la: "<< k->data.TenSach;
		cout<< "\nSo Trang la: "<< k->data.SoTrang;
		cout<< "\nGia Ban la: "<< k->data.GiaBan;
		cout<< "\nNam Xuat Ban la:  "<< k->data.NamXuatBan;
		printf("\n\n");
	}
}

void showTitle()
{
	cout << left << setw(20) << "Ma Sach" << left << setw(35) << "Ten Sach" << left << setw(20) << "So Trang" << left << setw(20) << "Gia Ban" << "Nam Xuat Ban" << endl;
}

void showList(LIST l)
{
	showTitle();
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << left << setw(20) << k->data.MaSach << left << setw(35) << k->data.TenSach << left << setw(20) << k->data.SoTrang << left << setw(20) << k->data.GiaBan << k->data.NamXuatBan << endl;
	}
}

void Page500AndNXB2018(LIST l,SACH x )
{
	for(NODE *k = l.pHead; k != NULL ; k=k->pNext)
	{
		if(k->data.SoTrang >500 && k->data.NamXuatBan < 2018)
		{
			cout<< "Ma Sach la: "<< k->data.MaSach;
			cout<< "\nTen Sach la: "<< k->data.TenSach;
			cout<< "\nSo Trang la: "<< k->data.SoTrang;
			cout<< "\nGia Ban la: "<< k->data.GiaBan;
			cout<< "\nNam Xuat Ban la:  "<< k->data.NamXuatBan;
			printf("\n\n");
		}
	}
}

void XoaSachLonHon100k(LIST &l, SACH x)
{
	if(l.pHead->data.GiaBan > 100.000)
	{
		 XoaDau(l);
	}
	if(l.pTail->data.GiaBan > 100.000)
	{
		XoaCuoi(l);
	}
	NODE *g = new NODE;// node se tro den node nam truoc node 
	for(NODE *k = l.pHead ; k != NULL ; k=k->pNext)
	{
		if(k->data.GiaBan > 100.000)
		{
			g->pNext = k->pNext;
			delete k;
		}
		g = k;
	}
}



int main()
{
	SACH x;
	LIST l;
	KhoiTao(l);
    int chon = 0;
    do
    {
        system("cls");
        printf("\t\t\t ============MENU================================\n");
        printf("\t\t\t |1. Doc DU LIEU TU FILE                        |\n");
        printf("\t\t\t |2. XUAT DU LIEU TU FILE                       |\n");
        printf("\t\t\t |3. XUAT Thong Tin PAGE >500 and NXB < 2018    |\n");
        printf("\t\t\t |4. Xoa Tat Ca Cuon Sach Gia Ban lon hon 100k  |\n");
        printf("\t\t\t |6. Thoat                                      |\n");
        printf("\t\t\t ================================================\n");
        printf("Ban chon: ");
        scanf("%d", &chon);
        switch(chon)
        {
            case 1:
                Doc_Du_Lieu_Tu_File(l);
                break;
            case 2:
                showList(l);
                _getch();
                break;
            case 3:
                Page500AndNXB2018(l,x);
                _getch();
                break;
            case 4:
                XoaSachLonHon100k(l,x);
                break;
            case 5:
                
                break;
            case 6:
                break;
            default:
                printf("Ban chon sai. Moi ban chon lai MENU!\n");
                break;
        }
    }while(chon!=6);
    _getch();
    return 0;
}



















