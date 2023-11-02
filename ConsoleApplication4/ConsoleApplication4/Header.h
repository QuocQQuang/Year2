#pragma once
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
