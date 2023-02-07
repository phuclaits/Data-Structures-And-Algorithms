#include<stdio.h>
#include<iostream>
#include<conio.h>
#include <cstdlib> 
#include<fstream>

#define Max 100
using namespace std;

struct Node{
    int data;
    struct Node* pLeft;
    struct Node* pRight;
};

typedef struct Node NODE;
typedef  NODE* TREE;

void KhoiTaoCay(TREE &t)
{
    t = NULL;
}

void ThemNodeVaoCay(TREE &t , int x)
{
    if(t == NULL)
    {
        Node *p = new NODE;
        p->data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p;
    }
    else{
        if(t->data > x)
        {
            ThemNodeVaoCay(t->pLeft,x);
        }
        else if(t->data < x)
        {
            ThemNodeVaoCay(t->pRight,x);
        }
    }
}

void showCay(TREE t)
{
    printf("\t%d",t->data);
}


int CheckEmpty(TREE t)
{
    return (t== NULL)? 1 : 0;
}

void DuyetNLR(TREE t)
{
    if(t!= NULL)
    {
        printf("\t%d",t->data);
        DuyetNLR(t->pLeft);
        DuyetNLR(t->pRight);
    }
}

void DuyetNRL(TREE t)
{
    if(t!= NULL)
    {
        printf("\t%d",t->data);
        DuyetNLR(t->pRight);
        DuyetNLR(t->pLeft);
    }
}

void Doc_Du_Lieu_Tu_File(TREE &t, ifstream &in)
{
	int n;
	in >> n;
	for(int i = 0 ; i < n; i++)
	{
		int x;
		in >> x;
		ThemNodeVaoCay(t,x);
	}
}

int insertNODE(TREE &t, TREE p)
{
    if(p == NULL)
        return 0;
    if(t == NULL)
    {
        t = p;
        return 1;
    }
    if(t->data == p->data)
    {
        return 0; // trùng nút
    }
    if(p->data < t->data)
    {
        insertNODE(t->pLeft,p);
    }
    else
    {
        insertNODE(t->pRight,p);
    }
    return 1;
}

void MENU(TREE &t)
{
	
	while(true)
	{
		system("cls");
		printf("\n\t\t======================MENU===================");
		printf("\n\t\t|0. Thoat Chuong Trinh                       |");
		printf("\n\t\t|1. Doc Du Lieu tu File                      |");
		printf("\n\t\t|2. Duyet Cay NODE LEFT RIGHT                |");
        printf("\n\t\t|3. Duyet Cay NODE RIGHT LEFT                |");
        printf("\n\t\t|4. Them 1 NODE vao Cay                      |");
		printf("\n\t\t=============================================");
		int luachon;
		printf("\nNhap Lua Chon: ");
		scanf("%d",&luachon);
		if(luachon <0 || luachon > 100)
		{
			printf("\n LUA CHON KO HOP LE!");
		}
        else if(luachon == 0)
        {
            printf("\nBan da chon thoat chuong trinh!");
            break;
        }
		else if(luachon == 1)
		{
			ifstream in;
			in.open("Data1.txt",ios_base::in);
			Doc_Du_Lieu_Tu_File(t,in);
			int n;
			in >> n;
			in.close();
		}
        else if(luachon == 2)
        {
            DuyetNLR(t);
            _getch();
        }
        else if(luachon == 3)
        {
            DuyetNRL(t);
            _getch();
        }
        else if(luachon == 4)
        {
            TREE p;
            printf("\nNhap vao Node can them: ");
            scanf("%d",&p->data);
            insertNODE(t,p);
            _getch();
        }
    }
}

int main()
{
    TREE t;
	KhoiTaoCay(t);
    MENU(t);
    return 0;
}












