#include <iostream>
#include <Windows.h>
#include "Buoi05_BTree.h"
using namespace std;

TNode* createTNode(ItemType x)
{
	TNode* p = new TNode;
	if (p == NULL)
	{
		cout << "Không đủ bộ nhớ để cấp phát" << endl;
		return NULL;
	}
	p->Info = x;
	p->Left = NULL;
	p->Right = NULL;
	return p;
}
void showTNode(TNode* p)
{
	cout << p->Info << '\t';
}
void deleteTNode(TNode*& p)
{
	if (p == NULL) return;
	delete p;
}
void initBTree(BTree& bt)
{
	bt.Root = NULL;
}
int isEmpty(BTree bt)
{
	return bt.Root == NULL;
}
int insertTNodeLeft(TNode*& T, TNode* p)
{
	if (T == NULL || p == NULL)
		return 0;
	if (T->Left != NULL)
		return 0;
	T->Left = p;
	return 1;
}
int insertTNodeRight(TNode*& T, TNode* p)
{
	if (T == NULL || p == NULL)
		return 0;
	if (T->Right != NULL)
		return 0;
	T->Right = p;
	return 1;
}
int insertTNode(TNode*& root, TNode* p)
{
	if (p == NULL)
		return 0;
	if (root == NULL)
	{
		root = p;
		return 1;
	}
	if (root->Left == NULL)
		insertTNode(root->Left, p);
	else if (root->Right == NULL)
		insertTNode(root->Right, p);
	else
	{
		int x = rand() % 2;
		if (x == 0)
			insertTNode(root->Left, p);
		else
			insertTNode(root->Right, p);
	}
	return 1;
}
void traverseNLR(TNode* root)
{
	if (root == NULL)
		return;
	showTNode(root);
	traverseNLR(root->Left);
	traverseNLR(root->Right);
}
void traverseLNR(TNode* root)
{
	if (root == NULL)
		return;
	traverseLNR(root->Left);
	showTNode(root);
	traverseLNR(root->Right);
}
void traverseLRN(TNode* root)
{
	if (root == NULL)
		return;
	traverseLRN(root->Left);
	traverseLRN(root->Right);
	showTNode(root);
}
TNode* findNode(TNode* root, ItemType x)
{
	if (root == NULL)
		return NULL;
	if (root->Info == x)
		return root;
	TNode* p = findNode(root->Left, x);
	if (p != NULL)
		return p;
	return findNode(root->Right, x);
}
int isLeaf(TNode* T)
{
	if (T == NULL)
		return 0;
	return (T->Left == NULL) && (T->Right == NULL);
}
int deleteTNodeLeft(TNode* T, ItemType& x)//Xóa nút con bên trái của nút T
{
	if (T == NULL)
		return 0;
	TNode* p = T->Left;
	if (p == NULL)
		return 0;
	if ((p->Left != NULL) && (p->Right) != NULL)
		return 0;
	x = T->Info;////////ko cần thiết
	delete p;
	return 1;
}
int deleteTNodeRight(TNode* T, ItemType& x)//Xóa nút con bên phải của nút T
{
	if (T == NULL)
		return 0;
	TNode* p = T->Right;
	if (p == NULL)
		return 0;
	if ((p->Left != NULL) && (p->Right) != NULL)
		return 0;
	x = T->Info;/////////ko cần thiết
	delete p;
	return 1;
}
int countTNode(TNode* root)
{
	if (!root)
		return 0;
	int nl = countTNode(root->Left);
	int nr = countTNode(root->Right);
	return (1 + nl + nr);
}
int countTNodeisLeaf(TNode* root)
{
	if (!root)
		return 0;
	if ((root->Left == NULL) && (root->Right == NULL))
		return 1;
	int cnl = countTNodeisLeaf(root->Left);
	int cnr = countTNodeisLeaf(root->Right);
	return (cnl + cnr);
}
int countTNodeHaveTwoChild(TNode* root)
{
	if (root == NULL)
		return 0;
	if ((root->Left == NULL) || (root->Right == NULL))
		return 0;
	int cnl = countTNodeHaveTwoChild(root->Left);
	int cnr = countTNodeHaveTwoChild(root->Right);
	return (cnl + cnr + 1);
}
int sumTNode(TNode* root)
{
	if (root == NULL)
		return 0;
	int suml = sumTNode(root->Left);
	int sumr = sumTNode(root->Right);
	return (suml + sumr + root->Info);
}
int heightTree(TNode* root)
{
	if (root == NULL)
		return 0;
	int hl = heightTree(root->Left);
	int hr = heightTree(root->Right);
	if (hl > hr)
		return hl + 1;
	return hr + 1;
}
void createBTree_FromArray(BTree& bt, ItemType a[], int na)
{
	for (int i = 0; i < na; i++)
		insertTNode(bt.Root,createTNode(a[i]));
}
void traverseNLRGreaterThanX(TNode* root, ItemType x)
{
	if (root == NULL)
		return;
	if(root->Info > x)
		showTNode(root);
	traverseNLRGreaterThanX(root->Left, x);
	traverseNLRGreaterThanX(root->Right, x);
}
