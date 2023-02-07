#include "34Header.h"

/*--------------------MENU-----------------------*/
void MENU()
{
	cout << "===================MENU==================" << endl;
	cout << "0.Exit" << endl;
	cout << "1.Kiem tra su hop le cua dong mo ngoac" << endl;
	cout << "2.Kiem tra su trung lap cua dau ngoac" << endl;
	cout << "=========================================" << endl;
}

/*----------------Stack Node--------------------*/
//tao mot StackNode
SNode* createSNode(ItemType x)
{
	SNode* p = new SNode;
	if (p == NULL)
	{
		cout << "Khong du bo nho de cap phat!" << endl;
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	return p;
}

//xoa mot StackNode
void deleteSNode(SNode*& p)
{
	if (p == NULL)
		return;
	p->next = NULL;
	delete p;
}

/*--------------------Stack------------------------*/
//khoi tao mot stack
void initStack(Stack& s)
{
	s.Top = NULL;
}

//kiem tra Stack co rong hay khong
bool isEmpty(Stack s)
{
	return (s.Top == NULL);
}

//nhap vao mot stack tu ban phim
void createStack(Stack& s)
{
	int n;
	ItemType x;
	initStack(s);
	do
	{
		cout << "So phan tu cua danh sach: ";
		cin >> n;
		if (n <= 0)
			cout << "So phan tu phai la so duong!" << endl;
	} while (n <= 0);
	for (int i = 1; i <= n; i++)
	{
		cout << "Phan tu thu " << i << ": ";
		cin >> x;
		SNode* p = createSNode(x);
		push(s, p);
	}
	cout << "Da nhap xong Stack." << endl;
}

//xuat Stack 
void traverseStack(Stack s)
{
	if (isEmpty(s))
	{
		cout << "Stack rong." << endl;
		return;
	}
	for (SNode* p = s.Top; p != NULL; p = p->next)
		cout << p->info << "  ";
}

//them mot SNode moi vao stack (push)
int push(Stack& s, SNode* p)
{
	if (p == NULL)
		return 0;
	if (isEmpty(s))
		s.Top = p;
	else
	{
		p->next = s.Top;
		s.Top = p;
	}
	return 1;
}

//xoa mot SNode khoi danh sach (pop)
int pop(Stack& s, ItemType& x)
{
	if (isEmpty(s))
		return 0;
	SNode* p = s.Top;
	s.Top = s.Top->next;
	x = p->info;
	delete p;
	return 1;
}

//lay gia tri cua top SNode
int getTop(Stack s, ItemType& x)
{
	if (isEmpty(s))
		return 0;
	x = s.Top->info;
	return 1;
}

//kiem tra su hop le cua cac dau ngoac
bool dauNgoacHopLe(string str)
{
	Stack s;
	initStack(s);
	char x;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			push(s, createSNode(str[i]));
		switch (str[i])
		{
		case ')':
		{
			pop(s, x);
			if (x == '[' || x == '{')
				return false;
			break;
		}
		case ']':
		{
			pop(s, x);
			if (x == '(' || x == '{')
				return false;
			break;
		}
		case '}':
		{
			pop(s, x);
			if (x == '(' || x == '[')
				return false;
			break;
		}
		} //end switch
	}
	if (isEmpty(s) == true)
		return true;
	else return false;
}

//kiem tra dau ngoac don co bi trung lap hay khong
bool kiemTraTrungLapNgoacDon(string str)
{
	char x;
	Stack s;
	initStack(s);
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ')')
		{
			pop(s, x);
			int count = 0;
			while (x != '(')
			{
				count++;
				pop(s, x);
			}
			if (count == 0)
				return true;
		}
		else
			push(s, createSNode(str[i]));
	}
	return false;
}