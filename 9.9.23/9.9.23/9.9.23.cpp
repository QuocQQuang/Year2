// 9.9.23.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}
void xuat(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void phatsinh(int arr[], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {

		arr[i] = rand() % 100;
	}
}
void qsort(int ar[], int le, int ri) {
	int p = ar[le];
	int l = le;
	int r = ri;

	while (l < r) 
	{
		while (ar[l] < p) {l++;}
		while (ar[r] > p) {r--;}
		if (l <= r) {
			swap(ar[l], ar[r]);
			l++;
			r--;
		}
	}

	if (le < r) {qsort(ar, le, r);}
	if (ri > l) {qsort(ar, l, ri);}
}

void merge(int arr[], int l, int m, int r) {
	int lsize = m - l + 1;
	int rsize = r - m;
	int * larr = new int[lsize];
	int * rarr = new int[rsize];
	for (int i = 0; i < lsize; i++) { larr[i] = arr[l + i]; } 
	for (int i = 0; i < rsize; i++) { rarr[i] = arr[m + i+1];}					   
	 //merge
	int i = 0;
	int j = 0;int k = l;								
	while (i < lsize && j < rsize) {
		if (larr[i] < rarr[j]) {
			arr[k] = larr[i]; i++;
		}
		else {
			arr[k] = rarr[j]; j++;
		}
		k++;
	}
	while (i < lsize) {
		arr[k] = larr[i];
		i++;
		k++;
	}

	while (j < rsize) {
		arr[k] = rarr[j];
		j++;
		k++;
	}
	delete[] larr;
	delete[] rarr;
}


void msort(int arr[], int l, int r) {
	int m = (l + r) / 2;
	if (l < r) {
		msort(arr,l, m);
		msort(arr, m + 1,r);
	}
	merge(arr, l, m, r);
}


int main() {
	int n;
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;

	int* arr = new int[n];
	phatsinh(arr, n);

	cout << "Mang truoc khi sap xep: ";
	xuat(arr, n);

	msort(arr, 0, n - 1);
	cout << "Mang sau khi sap xep (merge sort): ";
	xuat(arr, n);
	delete[] arr;
	//
	
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;

	arr = new int[n];
	phatsinh(arr, n);

	cout << "Mang truoc khi sap xep: ";
	xuat(arr, n);

	qsort(arr, 0, n - 1);
	cout << "Mang sau khi sap xep (quick sort): ";
	xuat(arr, n);

	delete[] arr;

	return 0;
}
