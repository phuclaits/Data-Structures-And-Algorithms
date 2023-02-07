#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#include<iostream>
using namespace std;
void Taomang(int* &a,int &n)
{
	a=(int*)malloc(sizeof(int)*15);
	n=15;
	srand((unsigned)time(NULL));
	for(int i=0;i<n;i++)
		*(a+i)=rand()%100-20;

}
void Xuatmang(int *a,int n)
{
	for(int i=0;i<n;i++)
		printf("%d   ",*(a+i));
}
void TaomangChan(int* &a,int &n)
{
	a=(int*)malloc(sizeof(int)*15);
	n=15;
	srand((unsigned)time(NULL));
	for(int i=0;i<n;i++)
	{
		*(a+i)=rand()%100-20;
		if(a[i]%2!=0)
			a[i]=a[i]+1;
	}
		

}
int LinearSeach(int *a,int n,int giatri)
{
	for(int i=0;i<n;i++)
		if(a[i]==giatri)
			return i;
	return -1;
}
int BinarySearch(int arr[], int l, int r, int x) 
{
  if (r >= l) 
  {
    int mid = l + (r - l) / 2; 
    if (arr[mid] == x)
      return mid;
    if (arr[mid] > x)
      return BinarySearch(arr, l, mid - 1, x);
    return BinarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
void InterchangeSortTang(int *a,int n)
{
	int i,j;
	for(i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
	}
}
void InterchangeSortGiam(int *a,int n)
{
	int i,j;
	for(i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
}
void SelectionSortTang(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
		min_idx = i;
		for (j = i+1; j < n; j++)
			if (arr[j] < arr[min_idx])
			min_idx = j;
			swap(arr[min_idx], arr[i]);
    }
}
void SelectionSortGiam(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
		min_idx = i;
		for (j = i+1; j < n; j++)
			if (arr[j] > arr[min_idx])
			min_idx = j;
			swap(arr[min_idx], arr[i]);
    }
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
    while(true)
	{
        while(left <= right && arr[left] < pivot) 
			left++;  
        while(right >= left && arr[right] > pivot) 
			right--;
        if (left >= right) break; 
        swap(arr[left], arr[right]);
        left++; 
        right--; 
    }
    swap(arr[left], arr[high]);
    return left; 
}
int partition1 (int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
    while(true)
	{
        while(left <= right && arr[left] > pivot) 
			left++; 
        while(right >= left && arr[right] < pivot) 
			right--; 
        if (left >= right) break;
        swap(arr[left], arr[right]); 
        left++; 
        right--;
    }
    swap(arr[left], arr[high]);
    return left; 
}
void quickSorttang(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSorttang(arr, low, pi - 1);
        quickSorttang(arr, pi + 1, high);
    }
}
void quickSortgiam(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition1(arr, low, high);
        quickSortgiam(arr, low, pi - 1);
        quickSortgiam(arr, pi + 1, high);
    }
}
void Menu()
{
	printf("\n-----------------MENU---------------------");
	printf("\n1. Tao mang ngau nhien");
	printf("\n2. Tao mang chua toan do chan");
	printf("\n3. LinearSearch");
	printf("\n4. Interchangsort Tang");
	printf("\n5. Interchangsort Giam");
	printf("\n6. BinarySearch");
	printf("\n7. Selectionsort tang");
	printf("\n8. Selectionsort giam");
	printf("\n9. Quicksort tang");
	printf("\n10. Quicksort giam");
	printf("\n-----------------------------------------");
}
void Process()
{
	int *a=new int;
	int n=0,chon,x,t;
	do
	{
		Menu();
		printf("\nNhap so thuc hien: ");
		scanf("%d",&chon);
		switch (chon)
		{
		case 1:
			Taomang(a,n);
			printf("Xuat mang:");
			Xuatmang(a,n);
			break;
		case 2:
			TaomangChan(a,n);
			printf("Xuat mang:");
			Xuatmang(a,n);
			break;
		case 3:
			printf("Nhap gia tri can tim:");
			scanf("%d",&x);
			t=LinearSeach(a,n,x);
			if(t!=-1)
				printf("\ntim thay %d tai vi  tri %d",x,t);
			else
				printf("Khong tim thay %d",x);
			break;
		case 4:
			InterchangeSortTang(a,n);
			Xuatmang(a,n);
			break;
		case 5:
			InterchangeSortGiam(a,n);
			Xuatmang(a,n);
			break;
		case 6:
			printf("Nhap gia tri can tim:");
			scanf("%d",&x);
			t=BinarySearch(a,0,n-1,x);
			if(t!=-1)
				printf("\ntim thay %d tai vi  tri %d",x,t);
			else
				printf("Khong tim thay %d",x);
			break;
		case 7:
			SelectionSortTang(a,n);
			Xuatmang(a,n);
			break;
		case 8:
			SelectionSortGiam(a,n);
			Xuatmang(a,n);
			break;
		case 9:
			quickSorttang(a,0,n-1);
			Xuatmang(a,n);
			break;
		case 10:
			quickSortgiam(a,0,n-1);
			Xuatmang(a,n);
			break;
		default:
			break;
		}
	}while(chon!=0);

}
int main()
{
	Process();
	system("pause");
	return 0;
}
