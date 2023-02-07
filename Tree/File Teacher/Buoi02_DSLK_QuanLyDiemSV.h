struct MonHoc
{
	char maMH[11];
	char tenMH[30];
	int soTC;

	double DTL;//Điểm tiểu luận
	double DCK;//Điểm cuối kỳ
	double diemMH;//Điểm môn học = 30% DTL + 70% DCK

	//DATE hocKy;//Có thể bổ sung thuộc tính này để cho biết môn học đó được tổ chức vào học kỳ nào

	MonHoc();
};

struct NodeMH
{
	MonHoc info;
	NodeMH* next;

	NodeMH();
};

struct SListMH
{
	NodeMH* head;
	NodeMH* tail;

	SListMH();
};
///////
struct SinhVien
{
	char maSV [11];
	char hoDem[26];
	char tenSV[8];
	int namSinh;

	SListMH dsmh;
	double diemKQ;// Điểm kết quả học tập của sinh viên là trung bình cộng điểm các môn học sinh viên đã đăng ký với trọng số là số tín chỉ.

	SinhVien();
};
struct NodeSV
{
	SinhVien info;
	NodeSV* next;

	NodeSV();
};

struct SListSV
{
	NodeSV* head;
	NodeSV* tail;

	SListSV();
};

NodeMH* createNodeMH(MonHoc mh);
NodeSV* createNodeSV(SinhVien sv);
void showNodeMH(NodeMH* p);
void showNodeSV(NodeSV* p);
bool isEmpty(SListMH l);
bool isEmpty(SListSV l);
void traverse(SListMH l);
void traverse(SListSV l);
void addTailSList(SListMH& l, NodeMH* p);
void addTailSList(SListSV& l, NodeSV* p);
void addHeadSListSV(SListSV& l, NodeSV* p);
void addAfterNodeSVSList(SListSV& l, NodeSV* q, NodeSV* p);//Thêm NodeSV p vào sau NodeSV q của danh sách
void interchangeAlphabeMaSVSList(SListSV l);
void interchangeAlphabeTenSVSList(SListSV l);

void deleteHeadSList(SListSV& l);
void deleteTailList(SListSV& l);
void deleteMidSList(SListSV& l, NodeSV* q);
void deleteSList(SListSV& l, char* maSV);