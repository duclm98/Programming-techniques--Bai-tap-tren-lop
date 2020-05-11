// Tuan2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void InputArray_1D(int*& a, int &n) {
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

void OutputArray_1D(int*& a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void FreeArray_1D(int*& a) {
	free(a);
}

void bai1()
{
	int  *a, n;
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;
	a = (int*)malloc(n * sizeof(int));
	if (a == NULL) {
		return;
	}
	InputArray_1D(a, n);
	cout << "Cac phan tu trong mang: " << endl;
	OutputArray_1D(a, n);
	FreeArray_1D(a);
	//OutputArray_1D(a, n);
	cout << "============================" << endl;
}


int main()
{
	int choose;
	do {
		cout << "1. Bai 1" << endl;
		cout << "1. Bai 2" << endl;
		cout << "Chon bai tap: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			bai1();
			break;
		case 2:
			break;
		default:
			break;
		}
	} while (choose >= 1 && choose <= 3);
	return 0;
}
