#include "34Header.h"

int main()
{
	Stack S;
	initStack(S);
	int op;
	do
	{
		system("cls");
		MENU();
		cout << "Nhap lua chon: ";
		cin >> op;
		switch (op)
		{
		case 0:
		{
			cout << "Exit." << endl;
			break;
		} 
		case 1:
		{
			string Str;
			cout << "Nhap vao chuoi dau ngoac: ";
			cin >> Str;
			if (dauNgoacHopLe(Str))
				cout << "Day dau ngoac hop le." << endl;
			else
				cout << "Day dau ngoac khong hop le." << endl;
			break;
		}
		case 2:
		{
			string Str;
			cout << "Nhap vao chuoi dau ngoac\n(Chi nhap bao gom ngoac don): ";
			cin >> Str;
			if (kiemTraTrungLapNgoacDon(Str))
				cout << "Co trung lap trong chuoi." << endl;
			else
				cout << "Khong co trung lap trong chuoi." << endl;
			break;
		}
		} //end switch
		if (op != 0)
		{
			cout << endl;
			system("pause");
			cout << endl;
		}
	} while (op != 0);
}