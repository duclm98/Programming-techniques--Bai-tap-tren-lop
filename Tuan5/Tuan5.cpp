// Tuan5.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
		for (int j = i+1; j < n; j++) {
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
	float f[] = { 1.2,3.5,2.3,4.9,5.7 };
	PHANSO ps[] = { {1,2},{9,5},{2,5},{8,7},{3,8} };
	string s[] = { "hello","chao","bonjou","nihao","hei" };

	cout << "Sap xep tang: " << endl;
	sapXep(i, n, tang);
	xuatMang(i, n);
	sapXep(f, n, tang);
	xuatMang(f, n);
	sapXep(ps, n, tang);
	xuatMang(ps, n);
	sapXep(s, n, tang);
	xuatMang(s, n);

	cout << endl << "Sap xep giam: " << endl;
	sapXep(i, n, giam);
	xuatMang(i, n);
	sapXep(f, n, giam);
	xuatMang(f, n);
	sapXep(ps, n, giam);
	xuatMang(ps, n);
	sapXep(s, n, giam);
	xuatMang(s, n);
}
