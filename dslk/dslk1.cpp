#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinhVien{
	int maSV;
	char tenSV[50];
	char lop[50];
	float diemTB;
	char HK[20];
};
typedef struct SinhVien SV;

struct Node{
	SV data;
	Node *next;
};

struct list{
	Node *Head;
	Node *Tail;
};

typedef struct list LIST;

void KhoiTaolist_Node(LIST &dssv){
	dssv.Head = NULL;
	dssv.Tail = NULL;
}

int CheckEmpty(LIST dssv){
	if(dssv.Head == NULL)
	{
		return 1;
	}
	return 0;
}

Node* CreateNode(SV x){
	Node *p = new Node;
	if(p == NULL){
		printf("Ko du bo nho");
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;
}
void ChenCuoi(LIST &dssv, Node *p){
	if(dssv.Head == NULL){
		dssv.Head = p;
		dssv.Tail = p;
	}
	else{
		dssv.Head->next = p;
		dssv.Tail =p;
	}
}
void NhapDSSV(LIST &dssv, int n)
{
	SV x;
	printf("Nhap Thong Tin Sinh Vien\n");
	for(int i = 0 ;i < n;i++){
		printf ("Nhap ma sinh vien : ");
		fflush(stdin);
		scanf("%d",&x.maSV);
		printf ("Nhap ten sinh vien : ");
		fflush(stdin);
        gets(x.tenSV);
        printf ("Nhap lop : ");
		fflush(stdin);
        gets(x.lop);
        printf ("Nhap diem Trung Binh : ");
		fflush(stdin);
        scanf("%f",&x.diemTB);
        printf ("Nhap hanh kiem : ");
		fflush(stdin);
        gets(x.HK);
        printf ("\n \n");
        Node *p = new Node;
        p = CreateNode(x);
        ChenCuoi(dssv,p);
	}
}
void XuatDSSV(LIST dssv)
{
	for(Node *p = dssv.Head; p != NULL ; p=p->next){
		printf("%d\t %s\t %s\t %f\t %s\n", p->data.maSV, p->data.tenSV, p->data.lop, p->data.diemTB, p->data.HK);
	}
}

int main(){
	LIST dssv;
	int n;
	printf("Nhap vao so luong sinh vien: ");
	scanf("%d",&n);
	KhoiTaolist_Node(dssv);
	NhapDSSV(dssv,n);
	printf("\nDANH SACH SINH VIEN\n");
	XuatDSSV(dssv);
	return 0;
	
}













