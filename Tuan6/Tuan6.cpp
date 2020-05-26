// Tuan6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

struct phanso
{
	int tu, mau;
};
typedef struct phanso PHANSO;

ostream& operator<<(ostream& outDev, PHANSO& ps) {
	if (ps.mau == 1 || ps.tu == 0) {
		outDev << ps.tu;
	}
	else
	{
		outDev << ps.tu << "/" << ps.mau;
	}
	return outDev;
}

template<typename T>
void hoanDoi(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

bool operator <(const PHANSO& a, const PHANSO&b) {
	if (a.tu*b.mau < b.tu*a.mau) {
		return true;
	}
	return false;
}

bool operator >(const PHANSO& a, const PHANSO& b) {
	if (a.tu*b.mau > b.tu*a.mau) {
		return true;
	}
	return false;
}

template<typename T>
bool tang(T a, T b) {
	return a > b;
}

template<typename T>
bool giam(T a, T b) {
	return a < b;
}

template<typename T>
void sapXep(T*arr, int n, bool(*loaiSapXep)(T, T)) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (loaiSapXep(arr[i], arr[j])) {
				hoanDoi(arr[i], arr[j]);
			}
		}
	}
}

template<typename T>
void xuatMang(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int n = 5;
	int i[] = { 2,8,1,4,9 };
	float f[] = { 1.2,3.5,2.3,5.1,4.9 };
	PHANSO ps[] = { {1,2},{9,5},{2,5},{8,7},{3,8} };
	string s[] = { "hello","chao","bonjou","nihao","hei" };

	int choose;
	do {
		cout << "1. Mang so nguyen" << endl;
		cout << "2. Mang so thuc" << endl;
		cout << "3. Mang phan so" << endl;
		cout << "4. Mang string" << endl;
		cout << "5. Thoat" << endl;
		cout << "Moi thay chon mang can sap xep: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Mang so nguyen" << endl;
			xuatMang(i, n);
			cout << "Sap xep tang: " << endl;
			sapXep(i, n, tang);
			xuatMang(i, n);

			cout<< "Sap xep giam: " << endl;
			sapXep(i, n, giam);
			xuatMang(i, n);
			cout << endl;

			break;
		case 2:
			cout << "Mang so thuc" << endl;
			xuatMang(f, n);
			cout << "Sap xep tang: " << endl;
			sapXep(f, n, tang);
			xuatMang(f, n);

			cout << "Sap xep giam: " << endl;
			sapXep(f, n, giam);
			xuatMang(f, n);
			cout << endl;

			break;
		case 3:
			cout << "Mang phan so" << endl;
			xuatMang(ps, n);
			cout << "Sap xep tang: " << endl;
			sapXep(ps, n, tang);
			xuatMang(ps, n);

			cout<< "Sap xep giam: " << endl;
			sapXep(ps, n, giam);
			xuatMang(ps, n);
			cout << endl;

			break;
		case 4:
			cout << "Mang chuoi" << endl;
			xuatMang(s, n);
			cout << "Sap xep tang: " << endl;
			sapXep(s, n, tang);
			xuatMang(s, n);

			cout<< "Sap xep giam: " << endl;
			sapXep(s, n, giam);
			xuatMang(s, n);
			cout << endl;

			break;
		default:
			break;
		}
	} while (choose >= 1 && choose <= 4);

	return 0;
}