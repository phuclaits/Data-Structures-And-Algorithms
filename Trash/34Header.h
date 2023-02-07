#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;
typedef char ItemType;

//struct SNode
struct SNode
{
	ItemType info;
	SNode* next;
};

//struct Stack
struct Stack
{
	SNode* Top;
};

void MENU();
SNode* createSNode(ItemType x);
void deleteSNode(SNode*& p);
void initStack(Stack& s);
bool isEmpty(Stack s);
void createStack(Stack& s);
void traverseStack(Stack s);
int push(Stack& s, SNode* p);
int pop(Stack& s, ItemType& x);
int getTop(Stack s, ItemType& x);
bool dauNgoacHopLe(string str);
bool kiemTraTrungLapNgoacDon(string str);