#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool KiemTang(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

bool KiemGiam(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void phatsinh(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

int binarySearchi(int arr[], int size, int target, int& ss) {
    int l = 0;
    int r = size - 1;

    while (l <= r) {
        int m = l + (r - l) / 2;
        ss++;
        if (arr[m] == target) {
            cout << "Tim thay gia tri " << target << " tai vi tri " << m << endl;
            return m;
        }
        if (arr[m] > target) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    cout << "Khong tim thay gia tri " << target << endl;
    return -1;
}
int binarySearchd(int arr[], int size, int target, int& ss) {
    int l = 0;
    int r = size - 1;

    while (l <= r) {
        int m = l + (r - l) / 2;
        ss++;
        if (arr[m] == target) {
            cout << "Tim thay gia tri " << target << " tai vi tri " << m << endl;
            return m;
        }
        if (arr[m] < target) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    cout << "Khong tim thay gia tri " << target << endl;
    return -1;
}

int TimTuyenTinh(int a[], int N, int X, int& ss) {
    for (int i = 0; i < N; i++) {
        ss++;
        if (a[i] == X) {
            cout << "Tim thay gia tri " << X << " tai vi tri " << i << endl;
            return i;
        }
    }
    cout << "Khong tim thay gia tri " << X << endl;
    return -1;
}


void xuat(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int ssTT = 0, ssNP = 0;
    int n;
    cin >> n;
    int* arr = new int[n];
    phatsinh(arr, n);
    xuat(arr, n);
    int o;
    cin >> o;
  

    if (KiemTang(arr, n)) {
        cout << "Mang da sap xep tang dan." << endl;
        binarySearchi(arr, n, o, ssNP);
        cout << "So lan so sanh nhi phan: " << ssNP << endl;
    }
    else if (KiemGiam(arr, n)) {
        cout << "Mang da sap xep giam dan." << endl;
        binarySearchd(arr, n, o, ssNP);
        cout << "So lan so sanh nhi phan: " << ssNP << endl;
    }
    else {
        cout << "Mang khong sap xep." << endl;  TimTuyenTinh(arr, n, o, ssTT);
        cout << "So lan so sanh tuyen tinh: " << ssTT << endl;
    }

    delete[] arr;

    return 0;
}
