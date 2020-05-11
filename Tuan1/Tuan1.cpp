//
// Tuan1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<math.h>
using namespace std;

void bai1()
{
	cout << "Tinh gia tri cua bieu thuc" << endl;
	double x;
	double y;
	cout << "Nhap x: ";
	cin >> x;
	y = sqrt(1 + x * x);
	cout << "Gia tri bieu thuc y = " << y << endl;
	cout << "======================================" << endl << endl;
}

bool kiemTraNguyenTo(int n) {
	if (n == 1) {
		return false;
	}
	for (int i = 2; i < n; i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}

void bai2()
{
	cout << "Kiem tra so nguyen to" << endl;
	int n;
	bool check;
	cout << "Nhap n: ";
	cin >> n;
	check = kiemTraNguyenTo(n);
	if (check == true) {
		cout << "So ban vua nhap la so nguyen to." << endl;
	}
	else {
		cout << "So ban vua nhap khong la so nguyen to." << endl;
	}
	cout << "======================================" << endl << endl;
}

void hienThiSoPhuc(double thuc, double ao) {
	if (ao > 0) {
		cout << thuc << "+" << ao << "i" << endl;
	}
	else if (ao < 0) {
		cout << thuc << "" << ao << "i" << endl;
	}
	else
	{
		cout << thuc << endl;
	}
}

void bai3()
{
	cout << "So phuc" << endl;
	double a, b, c, d;
	cout << "Nhap phan thuc cua so phuc A: ";
	cin >> a;
	cout << "Nhap phan ao cua so phuc A: ";
	cin >> b;
	cout << "So phuc la: A=";
	hienThiSoPhuc(a, b);
	cout << "Modun so phuc la: |A| = " << sqrt(a*a + b * b) << endl;

	cout << "Nhap phan thuc cua so phuc B: ";
	cin >> c;
	cout << "Nhap phan ao cua so phuc B: ";
	cin >> d;
	cout << "So phuc thu hai la: B=";
	hienThiSoPhuc(c, d);

	cout << "A + B = ";
	hienThiSoPhuc(a + c, b + d);

	cout << "A - B = ";
	hienThiSoPhuc(a - c, b - d);

	cout << "A * B = ";
	hienThiSoPhuc(a * c - b * d, a * d + b * c);

	cout << "B / A = ";
	hienThiSoPhuc((a*c + b * d) / (a*a + b * b), (a*d - b * c) / (a*a + b * b));

	cout << "======================================" << endl << endl;
}

int main()
{
	int choose;
	do {
		cout << "1. Bai 1" << endl;
		cout << "1. Bai 2" << endl;
		cout << "3. Bai 3" << endl;
		cout << "Moi thay chon bai tap: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			bai1();
			break;
		case 2:
			bai2();
			break;
		case 3:
			bai3();
			break;
		default:
			break;
		}
	} while (choose >= 1 && choose <= 3);
	return 0;
}
