#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	int data;
	Node *next;
};


struct LinkedList{
	Node *Head;
	Node *Tail;
};


Node *CreateNode(int init_data)
{
	Node *node = new Node;
	node->data = init_data;
	node->next = NULL;
	return node;
}

void CreateList(LinkedList &l)
{
	l.Head = NULL;
	l.Tail = NULL;
}

void AddTail(LinkedList &l, Node *node){
	if(l.Head == NULL){
		l.Head == node;
		l.Tail == node;
	}
	else{
		l.Tail->next == node;
		l.Tail == node;
	}
}

void ShowNode(LinkedList l, Node *node)
{
	node = l.Head;
	while(node != NULL)
	{
		printf("%d",node->data);
		node = node->next;
	}
}


int main()
{
	
	LinkedList list;
	CreateList(list);
	Node* node;
	for(int i = 0; i < 5; i++)
	{
		node = CreateNode(i);
		AddTail(list,node);
	}
	ShowNode(list,node);
	
	
	
	return 0;
}
