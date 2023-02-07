struct BaiHat
{
	char tenBH[51];
	char tenCS[41];
	char tenTG[41];
	int thoiLuong;

	BaiHat(const char* tenBH = "", const char* tenCS = "", const char* tenTG = "", int thoiLuong = 0);
};

struct NodeBH
{
	BaiHat info;
	NodeBH* next;
	NodeBH();
};

struct SListBH
{
	NodeBH* head;
	NodeBH* tail;
};

void initBH(SListBH& l);
bool isEmpty(SListBH l);
void addHeadSListBH(SListBH&l, NodeBH* p);
void docListBH(SListBH&dsbh, const char* filename);
void traverse(SListBH l);
void printContentBH(NodeBH* p);

NodeBH* searchSList(const SListBH& l, BaiHat bh);
void deleteHeadSList(SListBH& l);
void deleteTailList(SListBH& l);
void deleteMidSList(SListBH& l, NodeBH* q);
void deleteSList(SListBH& l, BaiHat bh);
void interchangeAlphabeTenBHSList(SListBH l);
void interchangeAlphabeTenCSSList(SListBH l);