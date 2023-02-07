#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
void NhapMaTran(int a[][MAX], int &n)
{
	int i,j;
	printf("Nhap cap cua ma tran :");scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void XuatMaTran(int a[][MAX],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}
}
int TongChinh(int a[][MAX], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if (i == j)
            sum = sum + a[i][j];
      }
   }
   return sum;
}
int TongPhu(int a[][MAX],int n)
{
	int i,j,tong=0,m;
	for(i=0;i<n;i++)
	{
		m = m - 1;
		for(j=0;j<n;j++)
		{
			if(i +j == n - 1)
			{
				tong+=a[i][j];
			}
		}
	}
	return tong;
}
void Random(int a[][MAX], int n){
	int i,j;
	printf("Nhap cap cua ma tran :");scanf("%d",&n);	
    srand(time(NULL));
    for(i = 0; i< n; i++)
      for(j = 0;j < n; j++)
          a[i][j]= rand() % 100;
}
int TongTrenChinh(int a[][MAX], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if (i < j)
            sum = sum + a[i][j];
      }
   }
   return sum;
}
int TongTrenPhu(int a[][MAX], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if (i + j < n - 1 )
            sum = sum + a[i][j];
      }
   }
   return sum;
}
int main()
{
	int a[MAX][MAX],n,chon;
	do{
		printf("\n1. Random ma tran");
		printf("\n2. Nhap xuat ma tran");
		printf("\n3. Tong cac phan tu nam tren duong cheo chinh");
		printf("\n4. Tong cac phan tu nam tren duong cheo phu");
		printf("\n5. Tong cac phan tu nam phia tren duong cheo chinh");
		printf("\n6. Tong cac phan tu nam phia tren duong cheo phu");
		printf("\nMoi chon : "); scanf("%d",&chon);
		switch(chon){
			case 1 :
				Random(a,n);
				XuatMaTran(a,n);
				break;
			case 2 : 
				NhapMaTran(a,n);
				XuatMaTran(a,n);
				break;
			case 3: 
				printf("\nTong cac phan tu nam tren duong cheo chinh la %d",TongChinh(a,n));
				break;
			case 4:
				printf("\nTong cac phan tu nam tren duong cheo phu la %d",TongPhu(a,n));
				break;
			case 5:
				printf("Tong cac phan tu nam phia tren duong cheo chinh %d",TongTrenChinh(a,n));
				break;
			case 6:
				printf("Tong cac phu tu nam phia tren duong cheo phu %d",TongTrenPhu(a,n));
				break;
		}
	}while(chon != 0);	
}
