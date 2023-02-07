#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#include<iostream>
#define Max 100
using namespace std;
struct phanSo
{
	int TuSo;
	int MauSo;
};

void NhapPS(phanSo * &PS,int &n)
{
	printf("Nhap vao Element: ");
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++)
	{
		printf("Nhap vao Tu So: ");
		scanf("%d",&PS[i].TuSo);
		printf("Nhap vao Mau So: ");
		scanf("%d",&PS[i].MauSo);
		try
		{
			if(PS[i].MauSo==0)
				throw 101;
		}
		catch (int error)
		{
			if(error==101)
				printf("\tMAU SO KHONG THE BANG 0 !");
			return;
		}
	}
}
void XuatPS(phanSo *PS, int n)
{
	for(int i = 0; i < n ; i++)
	{
		printf("\nPhan so thu %d : ",i+1);
		printf("%d/%d",PS[i].TuSo,PS[i].MauSo);
		printf("\n");
	}
}
int USCLN(int a,int b)
{
	if(a == 0 || a == 0) return 1;
	a = abs(a);
	b = abs(b);
	while(a!=b)
	{
		if(a>b)
			a=a-b;
		else
			b=b-a;
	}
	return a;
}
void KiemTraDoiDau(phanSo &x)
{
	if(x.MauSo < 0)
	{
		x.TuSo *= -1;
		x.MauSo *= -1;
	}
}
void RutGonPhanSo(phanSo &x)
{
	KiemTraDoiDau(x);
	int usc = USCLN(x.TuSo, x.MauSo);
	x.TuSo /= usc;
	x.MauSo /= usc;
}
float giatri(float a, float b)
{
	float s;
	s = a/b;
	return s;
}
float Giatri(phanSo*PS)
{
	return (float)(PS.Pnguyen*a.PS.MauSo+a.PS.TuSo)/a.PS.MauSo;
}


int main()
{
	phanSo *PS=new phanSo; int n=0;
	NhapPS(PS,n);
	XuatPS(PS,n);
	PhanSoLonNhat(PS,n);
	return 0;
}
