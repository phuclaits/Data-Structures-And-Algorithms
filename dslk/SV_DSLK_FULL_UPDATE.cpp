#include<iostream>
using namespace std;
#include<string.h>
#include<string>
#include<fstream>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<iomanip>
struct SinhVien
{
	char MaSV[12]; 
	char HoTen[25];
	char Lop[25];
	float DiemToan;
	float DiemLy;
   float DiemHoa;
   float dtb;
};
typedef struct SinhVien SV;

struct node{
	SV data;
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
NODE *KhoiTaoNODE(SV x)
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
	in.open("Data.TXT", ios::in);
	in >> n;
	in.ignore();
	for(int i = 0 ; i <n ; i++)
	{
		SV x;
		in.getline(x.MaSV, 12,'#');
		in.getline(x.HoTen, 25, '#');
		in.ignore(1);
      	in.getline(x.Lop, 25, '#');
		in >> x.DiemToan;
		in.ignore(1);
      	in >> x.DiemLy;
      	in.ignore(1);
      	in >> x.DiemHoa;
      	in.ignore(1);
		NODE *p = KhoiTaoNODE(x);
		ThemVaoCuoi(l,p);
		l.pTail->pNext = NULL;
	}
	in.close();
}

void Show(LIST l,SV x )
{
	for(NODE *k = l.pHead; k!= NULL ; k=k->pNext)
	{
		cout<< "Ma Sinh Vien la: "<< k->data.MaSV;
		cout<< "\nTen Sinh Vien la: "<< k->data.HoTen;
		cout<< "\nLop cua sinh vien la: "<< k->data.Lop;
		cout<< "\nDiem Toan: "<< k->data.DiemToan;
		cout<< "\nDiem Ly:  "<< k->data.DiemLy;
		cout<< "\nDiem Hoa la:  "<< k->data.DiemHoa;
		printf("\n\n");
	}
}

void showTitle()
{
	cout << left << setw(20) << "Ma Sinh Vien" << left << setw(35) << "Ten Sinh Vien" << left << setw(20) << "Lop SV" << left << setw(20) << "Diem Toan"<< left << setw(20) << "Diem Ly" << left << setw(20) << "Diem Hoa"<< endl;
}
void showList(LIST l)
{
	showTitle();
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << left << setw(20) << k->data.MaSV << left << setw(35) << k->data.HoTen << left << setw(20) << k->data.Lop << left << setw(20) << k->data.DiemToan<< left << setw(20) << k->data.DiemLy << left << setw(20) << k->data.DiemHoa << endl;
	}
}

void XuatDTB(LIST l)
{
	
	for(NODE *k = l.pHead; k!= NULL ; k=k->pNext)
	{
		cout<< "Ma Sinh Vien la: "<< k->data.MaSV;
		cout<< "\nTen Sinh Vien la: "<< k->data.HoTen;
		cout<< "\nLop cua sinh vien la: "<< k->data.Lop;
		cout<< "\nDiem Toan: "<< k->data.DiemToan;
		cout<< "\nDiem Ly:  "<< k->data.DiemLy;
		cout<< "\nDiem Hoa la:  "<< k->data.DiemHoa;
		k->data.dtb = (k->data.DiemToan +k->data.DiemLy + k->data.DiemHoa) / 3;
		printf("\nDiem Trung Binh cua SV la: %3f",k->data.dtb);
		printf("\n\n");
				
	}
}

void sort(LIST l)
{
	for(NODE *k = l.pHead; k!= NULL ; k=k->pNext)
	{	
		for(NODE *k1 = k->pNext; k1!= NULL ; k1=k1->pNext)
		{
			if(k->data.Lop == k1->data.Lop && k->data.dtb < k1->data.dtb)
			{
				 int tmp = k->data.dtb;
				 k->data.dtb = k1->data.dtb;
				 k1->data.dtb = tmp;	
			} 
		}
	}
}

void XoaSV(LIST &l, SV x)
{
	char info[20];
	printf("\nNhap TEN SV can Xoa: ");
	scanf("%s",&info);
	if(l.pHead->data.HoTen == info)
	{
		 XoaDau(l);
	}
	if(l.pTail->data.HoTen == info)
	{
		XoaCuoi(l);
	}
	NODE *g = new NODE;// node se tro den node nam truoc node 
	for(NODE *k = l.pHead ; k != NULL ; k=k->pNext)
	{
		if(k->data.HoTen == info)
		{
			g->pNext = k->pNext;
			delete k;
		}
		g = k;
	}
}

void DemSV(LIST l)
{
	char Khoa[50];
	printf("Nhap vao Khoa can Kiem Tra: ");
	scanf("%s",&Khoa);
	int dem = 0;
	for(NODE *k = l.pHead; k!= NULL ; k=k->pNext)
	{
		if(k->data.Lop == Khoa)
		{
			dem++;
		}
	}
	printf("\n Co %d Sinh Vien Khoa %s\n",dem,Khoa);
}

void ThemSV(LIST &l)
{
	char info[25];
	printf("Nhap vao Ma SV can them sau: ");
	scanf("%s",&info);
	SV x;
	NODE *p = KhoiTaoNODE(x);
	printf("\nNhap vao Thong tin SV\n");
	cin.ignore();
	printf("Nhap vao ten Ma Sinh Vien: ");
	scanf("%s",&p->data.MaSV);
	fflush(stdin);
	printf("Nhap vao ten Sinh Vien ");
	scanf("%s",&p->data.HoTen);
	fflush(stdin);
	printf("Nhap vao lop Sinh Vien ");
	scanf("%s",&p->data.Lop);
	fflush(stdin);
	printf("\nNhap vao diem Toan : ");
	scanf("%f",&p->data.DiemToan);
	printf("\nNhap vao diem Ly : ");
	scanf("%f",&p->data.DiemLy);
	printf("\nNhap vao diem Hoa : ");
	scanf("%f",&p->data.DiemHoa);
	if(l.pHead->data.MaSV == info)
	{
		
	}
}
int main()
{
	SV x;
	LIST l;
	KhoiTao(l);
    int chon = 0;
    do
    {
        system("cls");
        printf("\t\t\t ============MENU================================\n");
        printf("\t\t\t |1. Doc DU LIEU TU FILE                        |\n");
        printf("\t\t\t |2. XUAT DU LIEU TU FILE                       |\n");
        printf("\t\t\t |3. XUAT DU LIEU THEO COT                      |\n");
        printf("\t\t\t |4. XUAT DIEM TRUNG BINH                       |\n");
        printf("\t\t\t |5. SAP XEP GIAM DAN THEO KHOA                 |\n");
        printf("\t\t\t |6. XOA SINH VIEN (NHAP TEN SV CAN XOA)        |\n");
        printf("\t\t\t |7. Dem Sinh Vien Khoa (NGUOI DUNG NHAP)       |\n");
        printf("\t\t\t |8. Them Sinh Vien                             |\n");
        printf("\t\t\t |9. Thoat                                      |\n");
        printf("\t\t\t ================================================\n");
        printf("Ban chon: ");
        scanf("%d", &chon);
        switch(chon)
        {
            case 1:
                Doc_Du_Lieu_Tu_File(l);
                break;
            case 2:
                Show(l,x);
                _getch();
                break;
            case 3:
                showList(l);
                _getch();
                break;
            case 4:
            	XuatDTB(l);
                _getch();
                break;
            case 5:
            	sort(l);
                XuatDTB(l);
                _getch();
                break;
            case 6:
            	XoaSV(l,x);
                break;
            case 7:
            	DemSV(l);
            	_getch();
                break;
            case 8:
                break;
            case 9:
                break;
            default:
                printf("Ban chon sai. Moi ban chon lai MENU!\n");
                break;
        }
    }while(chon!=10);
    _getch();
    return 0;
}













