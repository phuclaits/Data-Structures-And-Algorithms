typedef int Data;

struct Node
{
	Data info;
	Node* next;

	Node();
};

struct SList
{
	Node* head;
	Node* tail;
};
/////////////////////
Node* createNode(int x);
void deleteNode(Node*& p);
void showNode(Node* p);

void init(SList& l);
bool isEmpty(SList l);
void traverse(SList l);

void addTailSList(SList& l, Node* p);
void inputSList(SList& l, const char* filename);//a. Nhập danh sách liên kết đơn từ file text chứa các số nguyên
void deleteHeadSList(SList& l);//b. Xóa phần tử đầu
void deleteTailList(SList& l);
Node* searchSList(SList l, int x);
void deleteMidSList(SList& l, Node* q);//c. Xóa một phần tử sau phần tử đã cho
void deleteXSlist(SList& l, int x);//Xóa một phần tử có giá trị bằng x
void deleteAllXSlist(SList& l, int x);//d. Xóa tất cả các phần tử có giá trị bằng x
void deleteSlist(SList& l);//e. Xóa toàn bộ danh sách
void deleteEvenSList(SList& l);//f. Xóa các phần tử chẵn trong DSLK
