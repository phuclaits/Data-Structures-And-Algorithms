#include<stdio.h>
#include<iostream>
#include<conio.h>
#include <cstdlib> 
#include<fstream>
#include<conio.h>
using namespace std;
struct TNode
{
	float data;
	TNode *pLeft;
	TNode *pRight;
};


struct BSTree{
	TNode* Root;
};

void khoitaocay(BSTree &bst)
{
	bst.Root = NULL;
}

TNode* createTNode(float x)
{
	TNode *p = new TNode;
	if(p == NULL)
	{
		printf("\nKhong Du bo nho de cap phat");
		_getch();
		return NULL;
	}
	p->data = x;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}

void showTNode(TNode* p)
{
	printf("%f", p->data);
}

void deleteTNode(TNode* &p)
{
	if(p == NULL) return;
	delete p;
}
int isEmpty(BSTree bst)
{ 
	return (bst.Root == NULL)? 1 : 0;
}
float insertTNode(TNode* &root, TNode* p)
{
	if(p == NULL)
		return 0; 
	if(root == NULL)
	{ 
		root = p;
		return 1; 
	}
	if(root->data == p->data)
		return 0; //B? trùng nút
	if(p->data < root->data)
		insertTNode(root->pLeft, p); //Them trai
	else
		insertTNode(root->pRight, p); //Them phai
	return 1; 
}

void Doc_Du_Lieu_Tu_File(BSTree &bst, ifstream &in)
{
	int n;
	in >> n;
	for(int i = 1 ; i <=n ;i++)
	{
		float x;
		in >> x;
		TNode *p = createTNode(x);
		insertTNode(bst.Root,p);
		//printf("%4d",bst.Root->data);
	}
	
}

void Duyet_NLR(TNode *root)
{
	if(root!= NULL)
	{
		printf("\t%.2f",root->data);
		Duyet_NLR(root->pLeft);
		Duyet_NLR(root->pRight);
	}
}

void Duyet_LNR(TNode *root)
{
	if(root!= NULL)
	{
		Duyet_LNR(root->pLeft);
		printf("\t%.2f",root->data);
		Duyet_LNR(root->pRight);
	}
}

TNode* TimKiem(TNode *root, float y)
{
	if(root == NULL)
	{
		return NULL;
	}
	else
	{
		if(y < root->data)
		{
			return TimKiem(root->pLeft,y);
		}
		else if(y > root->data)
		{
			return TimKiem(root->pRight,y);
		}
		else
		{
			return root; // tra ve nut can tim kiem
		}
	}	
}

TNode* findTNodeReplace(TNode* &p) // ham the mang	
{ 
	TNode * f =p;
	TNode *q = p->pRight;
	while(q->pLeft != NULL)
	{
		f = q;
		q = q->pLeft;
	}
	p->data = q->data;
	if(f=p)
	{
		return f->pRight = q->pRight;
	}
	else
		return f->pLeft = q->pRight;
	return q;
}


float deleteTNodeX1(TNode *&root, float x)
{
	if(root = NULL)
		return 0;
	if(root->data > x)
		return deleteTNodeX1(root->pLeft,x);
	else if(root->data < x)
		return deleteTNodeX1(root->pRight,x);
	else
	{ // truong hop khi cay ko co nhanh trai / phai
		TNode *p = root;
		if(root->pLeft == NULL) // ko co nhanh trai
		{
			root = root->pRight;
			delete p;
		}
		else if(root->pRight == NULL) // ko co nhanh phai
		{
			root = root->pLeft;
			delete p;
		}
		else
		{
			TNode * q = findTNodeReplace(p);
			delete q;
		}
		return 1;
	}
}

float SumTwoChild(TNode *root)
{
	float sum;
	if(root != NULL)
	{
		if(root->pLeft!= NULL && root->pRight!= NULL)
		{
			sum += root->data;
		}
		SumTwoChild(root->pLeft);
		SumTwoChild(root->pRight);
	}
	return sum;
	
	
}
		
void MENU_Tong()
{
	BSTree bst;
	khoitaocay(bst);
	while(true)
	{
		printf("\n\t\t======================MENU=========================");
		printf("\n\t\t|       0. Thoat Chuong Trinh                      |");
		printf("\n\t\t|       1. Nhap Du Lieu Tu File TEXT               |");
		printf("\n\t\t|       2. Duyet cay theo NLR                      |");
		printf("\n\t\t|       3. Tim kiem y co ton tai trong cay ko?     |");
		printf("\n\t\t|       4. Xoa phan tu y trong cay nhi phan        |");
		printf("\n\t\t|       5. Xuat cay theo thu tu tang dan           |");
		printf("\n\t\t|       6. Xoa phan tu y trong cay nhi phan        |");
		printf("\n\t\t|       7. Viet Ham dem nut chua so nho hon x muc k|");
		printf("\n\t\t|       8. Tong cac nut co 2 con trong cay         |");
		printf("\n\t\t====================================================");
		int luachon;
		printf("\nNhap Lua Chon: ");
		scanf("%d",&luachon);
		if(luachon <0 || luachon > 100)
		{
			printf("\n LUA CHON KO HOP LE!");
		}
		else if(luachon == 0)
		{
			printf("Ban da exit!");
			_getch();
			break;
		}
		else if(luachon == 1)
		{
			ifstream in;
			in.open("data1.txt",ios_base::in);
			Doc_Du_Lieu_Tu_File(bst,in);
			TNode *p = new TNode;
			_getch();
			system("cls");	
		}
		else if(luachon == 2)
		{
			printf("\nXuat cay: \n");
			Duyet_NLR(bst.Root);
			_getch();
			system("cls");
		}
		else if(luachon == 3)
		{
			float y;
			printf("\nNhap vao phan tu can tim kiem: ");
			scanf("%f",&y);
			TNode* p = TimKiem(bst.Root,y);
			if(p == NULL)
			{
				printf("\nPhan Tu y khong ton tai trong cay!");
			}
			else
			{
				printf("\nPhan Tu y co ton tai trong cay!");
			}
			_getch();
			system("cls");
		}
		else if(luachon == 4)
		{
			float x;
			printf("\nNhap vao Gia Tri Node can xoa: ");
			scanf("%f",&x);
			deleteTNodeX1(bst.Root,x);
			_getch();
			system("cls");
		}
		else if(luachon == 5)
		{
			Duyet_LNR(bst.Root);
			_getch();
			system("cls");
		}
		else if(luachon == 6)
		{
			
		}
		else if(luachon == 7)
		{
			
		}
		else if(luachon == 8)
		{
			printf("\n\tSUM Data: %f",SumTwoChild(bst.Root));
			_getch();
			system("cls");
		}
	}
}

void MENU_Bai1()
{
	
}

void MENU_Bai2()
{
	
}
int main()
{
	BSTree bst;
	khoitaocay(bst);	
	
	MENU_Tong();
	return 0;
	
}












