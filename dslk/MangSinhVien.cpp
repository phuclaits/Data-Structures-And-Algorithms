#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAXSIZE 100

//-----------------------------------------------------------------
typedef struct SinhVien
{
	int STT;
	char mssv[11];
	char hoTen[30];
	float diemTieuLuan;
	double diemThiKetThucMon;
	double diemTongKet = (diemTieuLuan * 0.3) + (diemThiKetThucMon * 0.7);
}SV;
void NhapSV(SV &sv, int &n);
//=================================================================
void NhapSV(SV &sv, int &n)
{
		printf("\nNhap vao ma sinh vien: "); scanf("%s",sv.mssv); fflush(stdin);
		printf("\nNhap vao Ho Va Ten SV : "); gets(sv.hoTen); fflush(stdin);
		printf("\nNhap vao diem Tieu Luan : "); scanf("%f",&sv.diemTieuLuan); fflush(stdin);
		printf("\nNhap vao diem Ket Thuc Mon: "); scanf("%lf",&sv.diemThiKetThucMon);
		printf("\n===============================================");
}
void NhapDSSV(SV dssv[], int &n)
{
	printf("Nhap Danh Sach Sinh Vien\n");
	printf("\nNhap So Sinh Vien: ");
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++)
	{
		printf("\nNhap Thong Tin Sinh Vien Thu %d\n",i+1);
		NhapSV(dssv[i],n);
	}
}
void XuatSV(SV sv)
{
	printf("\nMSSV: %s",sv.mssv);
	printf("\nHo Va Ten SV: %s",sv.hoTen);
	printf("\nDiem Tieu Luan: %f",sv.diemTieuLuan);
	printf("\nDiem Ket Thuc Mon: %lf",sv.diemThiKetThucMon);
}
void XuatDSSV(SV dssv[], int n)
{
	printf("\nDanh sach sinh vien vua nhap la: \n");
	printf("\nSo Sinh Vien : %d",n);
	for(int i = 0 ; i <n ; i++)
	{
		XuatSV(dssv[i]);
		printf("\n\t========================\n");
	}
}
int tinhDiemTongKet(SV dssv[], int n)
{
	float diemtongket;
	for(int i = 0 ; i < n ; i++)
	{
		diemtongket = (dssv[i].diemTieuLuan *0.3) +(dssv[i].diemThiKetThucMon * 0.7);
		printf("\nTong Diem SV thu %d ",i+1);
		printf("\nDiem Tong Ket: %.3f ",diemtongket);
	}
	return 0;
}
void xuatMax(SV dssv[], int n)
{
	int i ,min,max, diemtongket[MAXSIZE];
	for( i = 0 ; i < n ; i++)
	{
		diemtongket[i] = (dssv[i].diemTieuLuan *0.3) +(dssv[i].diemThiKetThucMon * 0.7);	
	}
	max = diemtongket[0];
	printf("\nSinh Vien co Diem tong ket cao nhat:");
	for(i = 1 ; i < n ; i++)
	{
		if(diemtongket[i] > max)
		{
			max = diemtongket[i];
			printf("\nMSSV: %s",dssv[i].mssv);
			printf("\nHo Va Ten SV: %s",dssv[i].hoTen);
			printf("\nDiem Tieu Luan: %f",dssv[i].diemTieuLuan);
			printf("\nDiem Ket Thuc Mon: %lf",dssv[i].diemThiKetThucMon);
		}		
	}	
}
int SinhVienDat(SV dssv[], int n)
{
	int count = 0;
	float diemtongket[MAXSIZE];
	for(int i = 0 ; i < n ; i++)
	{
		diemtongket[i] = (dssv[i].diemTieuLuan *0.3) +(dssv[i].diemThiKetThucMon * 0.7);	
		if(diemtongket[i] > 4.0)
		{
			count++;
		}	
	}
	return count;	
}
void ChuyenHe10Sang4(SV dssv[], int n)
{
	float diemtongket[MAXSIZE];
	int diemhe4[MAXSIZE];
	for(int i = 0 ; i < n ; i++)
	{
		diemtongket[i] = (dssv[i].diemTieuLuan *0.3) +(dssv[i].diemThiKetThucMon * 0.7);
		diemhe4[i] = (diemtongket[i]/10) * 4;
		printf("\nMSSV: %s",dssv[i].mssv);
		printf("\nHo Va Ten SV: %s",dssv[i].hoTen);
		printf("\nDiem Tieu Luan: %f",dssv[i].diemTieuLuan);
		printf("\nDiem Ket Thuc Mon: %lf",dssv[i].diemThiKetThucMon);
		printf("\nDiem Tong Ket: %lf",diemtongket[i]);
		printf("\nDiem He 4: %d",diemhe4[i]);
	}	
}

void swap(int a, int b)
{
	int temp = a;
    a = b;
    b = temp;
}

void tangdanDTK(SV dssv[], int n)
{
	float diemtongket[MAXSIZE];
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = n - 1; j < 0; j--)
		{
			diemtongket[i] = (dssv[i].diemTieuLuan *0.3) +(dssv[i].diemThiKetThucMon * 0.7);	
			if(diemtongket[i] < diemtongket[j])
			{
				swap(diemtongket[i],diemtongket[j]);
				XuatDSSV(dssv,n);
			}
		}
	}		
}
int main()
{
	SV dssv[100];
	int n,x;
	int chonChucNang;
	do
	{
		printf("\n1.Nhap Xuat Sinh Vien ");
		printf("\n2.Xuat Diem Tong Ket MAX ");
		printf("\n3.So Luong Sinh Vien Dat ");
		printf("\n4. Chuyen diem he 10 sang he 4 ");
		printf("\n5.Tang Dan Theo Diem Tong Ket ");
		printf("\n6. ");
		printf("\nBan hay chon mot chuc nang bat ky: ");
		scanf("%d", &chonChucNang);
		switch (chonChucNang)
		{
			case 1:
				NhapDSSV(dssv,n);
				XuatDSSV(dssv,n);
				//tinhDiemTongKet(dssv,n);
				
				break;
			case 2:
				xuatMax(dssv,n);
				//SinhVienDat(dssv,n);
				break;
			case 3:
				printf("\nSo luong Sinh Vien Dat: %d ",SinhVienDat(dssv,n));
				break;
			case 4:
				printf("\nChuyen He 10 sang he 4: \n");
				ChuyenHe10Sang4(dssv,n);
				break;
			case 5: // chua lam ra
				printf("\nTang Dan Theo Diem Tong Ket\n");
				tangdanDTK(dssv,n);
				break;
			case 6:
				
				break;
		}
	} while (chonChucNang != 0);
}
//======================================================
