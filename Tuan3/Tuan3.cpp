// Tuan3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory.h>
using namespace std;

struct sophuc
{
	float a, b;
};
typedef struct sophuc SOPHUC;

istream& operator>>(istream& inDev, SOPHUC& p) {
	inDev >> p.a >> p.b;

	return inDev;
}

ostream& operator<<(ostream& outDev, SOPHUC& p) {
	outDev << p.a << "+" << p.b << "i";

	return outDev;
}

int headSize = sizeof(int) + sizeof(int);

int memSize(int nItem, int szItem) {
	return headSize + nItem * szItem;
}

void* origin_addr(void* aData) {
	if (aData != NULL) {
		return (char*)aData - headSize;
	}
	return NULL;
}

void* data_addr(void* aOrigin) {
	if (aOrigin != NULL) {
		return (char*)aOrigin + headSize;
	}
	return NULL;
}

void* sizeItem_addr(void* aData) {
	if (aData != NULL) {
		return (char*)aData - sizeof(int);
	}
	return NULL;
}

int arrSize(void* aData) {
	if (aData != NULL) {
		return *(int*)origin_addr(aData);
	}
	return 0;
}

int arrItemSize(void*aData) {
	if (aData != NULL) {
		return *(int*)sizeItem_addr(aData);
	}
	return 0;
}

void arrFree(void* aData) {
	if (aData != NULL) {
		free(origin_addr(aData));	
	}
}

void* arrInit(int nItem, int szItem) {
	int sz = memSize(nItem, szItem);
	void* aOrigin = malloc(sz);
	if (aOrigin != NULL) {
		memset(aOrigin, 0, sz);
		void* aData = data_addr(aOrigin);
		*(int*)origin_addr(aData) = nItem;
		*(int*)sizeItem_addr(aData) = szItem;
		return aData;
	}
	return NULL;
}

void* arrResize(void* aData, int nItem) {
	if (aData == NULL || nItem < 0) {
		return NULL;
	}
	void* aOrgin = origin_addr(aData);
	int sizeItem = *(int*)sizeItem_addr(aData);
	int sz = memSize(nItem, sizeItem);
	void* aNew = realloc(aOrgin, sz);
	if (aNew != NULL) {
		aData = data_addr(aNew);
		*(int*)origin_addr(aData) = nItem;
		return aData;
	}
	return NULL;
}

int arrPushback(void** aData, void* x) {
	int nItem = arrSize(*aData), szItem = arrItemSize(*aData);
	void* aNew = arrResize(*aData, 1 + nItem);
	if (aNew != NULL) {
		memmove((char*)aNew + nItem * szItem, x, szItem);
		*aData = aNew;
		return 1;
	}
	return 0;
}

void* arrPopBack(void** aData) {
	int nItem = arrSize(*aData), szItem = arrItemSize(*aData);
	void* x = malloc(szItem);
	if (*aData != NULL && nItem > 0) {
		nItem--;
		memmove(x, (char*)(*aData) + nItem * szItem, szItem);
		void* aNew = arrResize(*aData, nItem);
		if (aNew != NULL) {
			*aData = aNew;
		}
	}
	return x;
}

SOPHUC* soPhucArrIn() {
	SOPHUC* a = (SOPHUC*)arrInit(0, sizeof(SOPHUC));
	SOPHUC x = { 0, 0 };
	int i = 0;
	cout << "Nhap so phuc thu " << ++i << ": " << endl;
	while (cin >> x) {
		arrPushback((void**)&a, &x);
		cout << "Nhap so phuc thu " << ++i << ": " << endl;
	}
	cin.clear();
	return a;
}

void soPhucArrOut(void* aData) {
	int nItem = arrSize(aData);
	for (int i = 0; i < nItem; i++) {
		cout << *(SOPHUC*)((char*)aData + i*(sizeof(SOPHUC)));
		cout << "\t";
	}
}

int main()
{
	cout << "Nhap cac phan tu so phuc: " << endl;
	SOPHUC* A = soPhucArrIn();
	cout << "Arr:\t";
	soPhucArrOut(A);
	SOPHUC* x = (SOPHUC*)arrPopBack((void**)&A);
	cout << endl << "Popped element: " << *x << endl;
	free(x);
	arrFree((SOPHUC*)A);

	return 0;
}
