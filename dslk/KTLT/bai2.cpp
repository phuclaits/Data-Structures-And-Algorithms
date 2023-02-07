#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX_SIZE 100
//memory

bool ktsnt(int N)
{
    int i;
    if (N<2) return 0;
    for (i=2; i<=sqrt(N); i++)
        if (N%i==0)
            return 0;
    return 1;
}

int Search(int N)
{
    int i,s=0;
    for (i=2; i<N; i++)
        if (ktsnt(i)==1)
            printf("%3d",i);
    return 0;
}

int TimChuSoDauLe(int N)
{
	int donvi;
	N = abs(N);
	while(N >= 10)
	{
		donvi = N % 10;
		N /=10 ;
	}
	if(N % 2 == 0 )
	{
		return 0;
	}
	return 1;
}
int sum(int N)
{
	int i,sum = 0;
    for (i=2; i<N; i++)
    {
	    if (ktsnt(i)==1)
	    {
	    	if(TimChuSoDauLe(i) == 1)
	    	{
	    		sum += i;
			}
		}
	}
	return sum;
}

void NhapMang(int a[], int &n)
{
    for(int i = 0;i < n; ++i)
	{
        printf("\nNhap phan tu a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

void XuatMang(int a[], int n)
{
    for(int i = 0;i < n; ++i)
	{
        printf("\nPhan tu a[%d] = %d", i, a[i]);
    }
}
int SoLanXuatHienTrongMang(int a[], int n)
{
	int x;
	printf("\nNhap vao gia tri can tim: ");
	scanf("%d",&x);
	int count = 0 ;
	for(int i = 0 ; i < n ; i++)
	{
		if(a[i] == x )
		{
			count += 1;
		}
	}
	return count;
}
void swap(int &a , int &b)
{
	int temp = a; 
	a = b;
	b = temp;	
}	
void chantangdan(int a[], int n)
{
	int min = a[0];
	for(int i=0;i<n-1;i++)
	{	
		if(a[i] % 2 == 0)
		{
			printf("%3d",a[i]);
		}
	}
}
int KiemTraMangDoiXung(int a[], int n)
{
	for(int i = 0; i < n/2; i++)
	{
		if(a[i] != a[n - i - 1])
		{
			return -1;
			break;
		}
	}
	return 1;
}

int kiemTraMangToanChan(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0) {
			return -1;
			break;
		}
	}
	return 1;
}

// main 
int main()
{
	int N,x;
	int n;
	int a[MAX_SIZE];
	printf("\n Nhap vao so nguyen to N = ");
	scanf("%d",&N);
	Search(N);
	
	printf("\n");
	
	printf("\n Tong cac so chu so dau la le: %d",sum(N));
	printf("\n");
	
	printf("\n Nhap vao Element = ");
	scanf("%d",&n);
	NhapMang(a,n);
	XuatMang(a,n);
	printf("\nSo Lan Xuat Hien cua %d Trong Mang la: %d ",x,SoLanXuatHienTrongMang(a,n));
	printf("\nChan Tang Dan: ");
	chantangdan(a,n);
	printf("\n");
	if(KiemTraMangDoiXung(a,n) == 1)
		printf("\nMang doi xung ");
	else
		printf("\nMang khong doi xung ");
	printf("\n");
	if(kiemTraMangToanChan(a,n) == 1)
		printf("\nMang doi xung ");
	else
		printf("\nMang khong doi xung ");
	return 0;
}




