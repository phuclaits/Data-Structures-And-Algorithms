#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include "Buoi05_BTree.h"
using namespace std;

void menu()
{
	cout << "*********************" << endl;
	cout << "Bài tập thực hành buổi 5" << endl;
	cout << "*********************" << endl;
	cout << "0. Thoát" << endl;
	cout << "1. Bài 1\n";
	cout << "2. Bài 2\n";
	cout << "3. Bài 3\n";
	cout << "4. Bài 4\n";
}
void menuBai1()
{
	cout << "*********************" << endl;
	cout << "Bài tập 1" << endl;
	cout << "*********************" << endl;
	cout << "0. Thoát" << endl;
	cout << "a. Tạo cây NP bằng 3 cách\n";
	cout << "b. Duyệt cây nhị phân bằng 6 cách\n";
	cout << "c. Thêm 1 nút có giá trị x làm con trái của nút có giá trị y của cây\n";
	cout << "d. Thêm 1 nút có giá trị x làm con phải của nút có giá trị y của cây\n";
	cout << "e. Đếm số nút trên cây\n";
	cout << "f. Tìm kiếm 1 nút có giá trị x có tồn tại trên cây hay không?\n";
	cout << "g. Liệt kê các nút có giá trị lớn hơn x\n";
	cout << "h. Thực hiện một số thao tác: Đếm số nút trên cây/số nút lá/số nút có 1 con/số nút có 2 con/tổng các nút trên cây/tổng nút lá/tổng nút có 1 con/tổng nút có 2 con/chiều cao...\n";
}
void menuBai2()
{
	cout << "*********************" << endl;
	cout << "Bài tập 1" << endl;
	cout << "*********************" << endl;
	cout << "0. Thoát" << endl;
	cout << "a. Tạo cây NP bằng 3 cách\n";
	cout << "b. Duyệt cây nhị phân bằng 6 cách\n";
	cout << "c. Thêm 1 nút có giá trị x làm con trái của nút có giá trị y của cây\n";
	cout << "d. Thêm 1 nút có giá trị x làm con phải của nút có giá trị y của cây\n";
	cout << "e. Đếm số nút trên cây\n";
	cout << "f. Tìm kiếm 1 nút có giá trị x có tồn tại trên cây hay không?\n";
	cout << "g. Liệt kê các nút có giá trị lớn hơn x\n";
	cout << "h. Thực hiện một số thao tác: Đếm số nút trên cây / số nút lá / số nút có 1 con / số nút có 2 con / tổng các nút trên cây / tổng nút lá / tổng nút có 1 con / tổng nút có 2 con / chiều cao...\n";
}
void menuBai3()
{
	cout << "*********************" << endl;
	cout << "Bài tập 1" << endl;
	cout << "*********************" << endl;
	cout << "0. Thoát" << endl;
	cout << "a. Tạo cây NP bằng 3 cách\n";
	cout << "b. Duyệt cây nhị phân bằng 6 cách\n";
	cout << "c. Thêm 1 nút có giá trị x làm con trái của nút có giá trị y của cây\n";
	cout << "d. Thêm 1 nút có giá trị x làm con phải của nút có giá trị y của cây\n";
	cout << "e. Đếm số nút trên cây\n";
	cout << "f. Tìm kiếm 1 nút có giá trị x có tồn tại trên cây hay không?\n";
	cout << "g. Liệt kê các nút có giá trị lớn hơn x\n";
	cout << "h. Thực hiện một số thao tác: Đếm số nút trên cây / số nút lá / số nút có 1 con / số nút có 2 con / tổng các nút trên cây / tổng nút lá / tổng nút có 1 con / tổng nút có 2 con / chiều cao...\n";
}
void menuBai4()
{
	cout << "*********************" << endl;
	cout << "Bài tập 1" << endl;
	cout << "*********************" << endl;
	cout << "0. Thoát" << endl;
	cout << "a. Tạo cây NP bằng 3 cách\n";
	cout << "b. Duyệt cây nhị phân bằng 6 cách\n";
	cout << "c. Thêm 1 nút có giá trị x làm con trái của nút có giá trị y của cây\n";
	cout << "d. Thêm 1 nút có giá trị x làm con phải của nút có giá trị y của cây\n";
	cout << "e. Đếm số nút trên cây\n";
	cout << "f. Tìm kiếm 1 nút có giá trị x có tồn tại trên cây hay không?\n";
	cout << "g. Liệt kê các nút có giá trị lớn hơn x\n";
	cout << "h. Thực hiện một số thao tác: Đếm số nút trên cây / số nút lá / số nút có 1 con / số nút có 2 con / tổng các nút trên cây / tổng nút lá / tổng nút có 1 con / tổng nút có 2 con / chiều cao...\n";
}
void main()
{
	SetConsoleOutputCP(CP_UTF8);
	int chonBai = 0;
	char chonCau = 0;
	do
	{
		system("cls");
		menu();
		cout << "\nChọn bài tập: ";
		cin >> chonBai;
		
		switch (chonBai)
		{
		case 0:
		{
			cout << "Thoát" << endl;
			break;
		}
		case 1:
		{
			do
			{
				system("cls");
				menuBai1();
				
				cout << "\nChọn câu: ";
				cin >> chonCau;

				switch (chonCau)
				{
				case 48:
				{
					cout << "Thoát" << endl;
					break;
				}
				case 'a'://Tạo cây NP bằng 3 cách
				{
					BTree bt;
					initBTree(bt);
					////Cách 1: Tạo cây NP từ mảng các phần tử cho trước
					int a[] = { 1, 2, 3, 4, 5 };
					int n = 5;
					createBTree_FromArray(bt, a, n);

					////Cách 2: Tạo cây NP từ mảng được nhập từ bàn phím
					/*int* a, n;
					cout << "Nhập số phần tử của mảng: ";
					cin >> n;
					a = new int[n];
					for (int i = 0; i < n; i++)
					{
						cout << "Nhập phần tử thứ " << i << ": ";
						cin >> a[i];
					}

					for (int i = 0; i < n; i++)
						cout << a[i] << '\t';
					cout << endl;
					createBTree_FromArray(bt, a, n);*/

					///Cách 3: Tạo cây NP ngẫu nhiên
					/*int n = 0;
					cout << "Nhập số phần tử của mảng: ";
					cin >> n;
					srand(time(NULL));
					for (int i = 0; i < n; i++)
					{
						int x = (rand() % 199) - 99;
						insertTNode(bt.Root, createTNode(x));
					}*/

					break;
				}
				case 'b'://Duyệt cây NLR, LNR, LRN
				{
					BTree bt;
					initBTree(bt);
					////Cách 1: Tạo cây NP từ mảng các phần tử cho trước
					int a[] = { 1, 2, 3, 4, 5 };
					int n = 5;
					createBTree_FromArray(bt, a, n);

					cout << "Duyệt cây theo NLR\n";
					traverseNLR(bt.Root);
					cout << endl;

					cout << "Duyệt cây theo LNR\n";
					traverseLNR(bt.Root);
					cout << endl;

					cout << "Duyệt cây theo LRN\n";
					traverseLRN(bt.Root);
					cout << endl;

					break;
				}
				case 'c'://Thêm 1 nút có giá trị x làm con trái của nút có giá trị y của cây
				{
					BTree bt;
					initBTree(bt);
					////Cách 1: Tạo cây NP từ mảng các phần tử cho trước
					int a[] = { 1, 2, 3, 4, 5 };
					int n = 5;
					createBTree_FromArray(bt, a, n);

					int x, y;
					cout << "Nhập giá trị x của nút cần thêm: ";
					cin >> x;
					cout << "Nhập giá trị y của nút cần tìm: ";
					cin >> y;
					TNode* p = findNode(bt.Root, y);
					if (p == NULL)
					{
						cout << "Không tìm thấy nút có giá trị y trong cây";
						break;
					}
					else if (p->Left != NULL)
					{
						cout << "Cây đã có nhánh trái\n";
						break;
					}
					else
						insertTNodeLeft(p, createTNode(x));

					traverseLNR(bt.Root);
					cout << endl;

					break;
				}
				case 'd'://Thêm 1 nút có giá trị x làm con phải của nút có giá trị y của cây
				{
					BTree bt;
					initBTree(bt);
					////Cách 1: Tạo cây NP từ mảng các phần tử cho trước
					int a[] = { 1, 2, 3, 4, 5 };
					int n = 5;
					createBTree_FromArray(bt, a, n);

					int x, y;
					cout << "Nhập giá trị x của nút cần thêm: ";
					cin >> x;
					cout << "Nhập giá trị y của nút cần tìm: ";
					cin >> y;
					TNode* p = findNode(bt.Root, y);
					if (p == NULL)
					{
						cout << "Không tìm thấy nút có giá trị y trong cây";
						break;
					}
					else if (p->Right != NULL)
					{
						cout << "Cây đã có nhánh phải\n";
						break;
					}
					else
						insertTNodeRight(p, createTNode(x));

					traverseLNR(bt.Root);
					cout << endl;
					
					break;
				}
				case 'e'://Đếm số nút trên cây
				{
					BTree bt;
					initBTree(bt);
					////Cách 1: Tạo cây NP từ mảng các phần tử cho trước
					int a[] = { 1, 2, 3, 4, 5 };
					int n = 5;
					createBTree_FromArray(bt, a, n);
					
					cout << "Số nút của cây: " << countTNode(bt.Root) << endl;

					break;
				}
				case 'f'://Tìm kiếm 1 nút có giá trị x có tồn tại trên cây hay không?
				{
					BTree bt;
					initBTree(bt);
					////Cách 1: Tạo cây NP từ mảng các phần tử cho trước
					int a[] = { 1, 2, 3, 4, 5 };
					int n = 5;
					createBTree_FromArray(bt, a, n);

					int x;
					cout << "Nhập giá trị x của nút cần tìm: ";
					cin >> x;
					if (findNode(bt.Root, x) != NULL)
						cout << "Tìm thấy nút có giá trị " << x << "\n";
					else
						cout << "Không tìm thấy nút có giá trị "<< x << "\n";
					break;
				}
				case 'g'://Liệt kê các nút có giá trị lớn hơn x
				{
					BTree bt;
					initBTree(bt);
					////Cách 1: Tạo cây NP từ mảng các phần tử cho trước
					int a[] = { 1, 2, 3, 4, 5 };
					int n = 5;
					createBTree_FromArray(bt, a, n);

					int x;
					cout << "Nhập giá trị x của nút cần tìm: ";
					cin >> x;
					traverseNLRGreaterThanX(bt.Root, x);

					break;
				}
				case 'h'://Thực hiện một số thao tác: Đếm số nút trên cây/số nút lá/số nút có 1 con/số nút có 2 con/tổng các nút trên cây/tổng nút lá/tổng nút có 1 con/tổng nút có 2 con/chiều cao
				{
					BTree bt;
					initBTree(bt);
					////Cách 1: Tạo cây NP từ mảng các phần tử cho trước
					int a[] = { 1, 2, 3, 4, 5 };
					int n = 5;
					createBTree_FromArray(bt, a, n);

					cout << "Số nút trên cây: " << countTNode(bt.Root) << endl;
					cout << "Số nút lá trên cây: " << countTNodeisLeaf(bt.Root) << endl;

					break;
				}
				default:
					break;
				}
				if (chonCau != 48)
					system("pause");
			} while (chonCau != 48);
			break;
		}
		case 2:
		{
			do
			{
				system("cls");
				menuBai2();
				cout << "\nChọn câu: ";
				cin >> chonCau;

				switch (chonCau)
				{
				case 48:
				{
					cout << "Thoát" << endl;
					break;
				}
				case 'a'://
				{
					
					break;
				}
				case 'b'://
				{
					
					break;
				}
				case 'c'://
				{
					
					break;
				}
				case 'd'://
				{
					
					break;
				}
				case 'e'://
				{
					
					break;
				}
				case 'f'://
				{
					
					break;
				}
				case 'g'://
				{
					
					break;
				}
				case 'h'://
				{
					
					break;
				}
				case 'i'://
				{

					break;
				}
				default:
					break;
				}
				if (chonCau != 48)
					system("pause");
			} while (chonCau != 48);
			break;
		}
		case 3:
		{
			do
			{
				system("cls");
				menuBai3();
				cout << "\nChọn câu: ";
				cin >> chonCau;

				switch (chonCau)
				{
				case 48:
				{
					cout << "Thoát" << endl;
					break;
				}
				case 'x'://
				{
					
					break;
				}
				case 'a'://
				{
					
					break;
				}
				case 'b'://
				{
					
					break;

				}
				case 'c'://
				{
					
					break;
				}
				case 'd'://
				{
					
					break;
				}
				case 'e'://
				{
					
					break;
				}
				case 'f'://
				{
					
					break;
				}
				case 'g'://
				{

					break;
				}
				case 'h'://
				{

					break;
				}
				case 'i'://
				{

					break;
				}
				case 'j'://
				{

					break;
				}
				case 'k'://
				{

					break;
				}
				case 'l'://
				{

					break;
				}
				case 'm'://
				{

					break;
				}
				default:
					break;
				}
				if (chonCau != 48)
					system("pause");
			} while (chonCau != 48);
			break;
		}
		case 4:
		{

			break;
		}

		default:
			break;
		}
		system("pause");
	} while (chonBai != 0);
}