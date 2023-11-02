// 261023.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int dt) {
        this->data = dt;
        this->next = NULL;
    }
};

class Stack {
  public:
    Node* top;


    Stack() {
        top = NULL;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        else {
            cout << ""  ;
        }
    }

    int peek() {
        if (top != NULL) {
            return top->data;
        }
        else {
            cout << ""  ;
            return -1; 
        }
    }

    bool isEmpty() {
        return top == NULL;
    }
};
void quickSort(int arr[], int left, int right) {
    Stack stack;
    stack.push(left);
    stack.push(right);

    while (!stack.isEmpty()) {
        right = stack.peek();
        stack.pop();
        left = stack.peek();
        stack.pop();

        int pivotIndex = left + (right - left) / 2;
        int pivotValue = arr[pivotIndex];

        int i = left;
        int j = right;

        while (i <= j) {
            while (arr[i] < pivotValue)
                i++;
            while (arr[j] > pivotValue)
                j--;

            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        if (left < j) {
            stack.push(left);
            stack.push(j);
        }
        if (i < right) {
            stack.push(i);
            stack.push(right);
        }
    }
}
void moveDisks(Stack& src, Stack& dest, int n) {
    Stack temp; 

    for (int i = 0; i < n; i++) {
        int disk = src.peek();
        src.pop();
        temp.push(disk);
    }

    for (int i = 0; i < n; i++) {
        int disk = temp.peek();
        temp.pop();
        dest.push(disk);
    }
}
void towerOfHanoi(int n, Stack &A, Stack &B, Stack &C) {
  for(int i=n; i>=1; i--) {
    if(i%3 == 1) {
      cout << "Move disk " << i << " from A to C" << endl;
      moveDisks(A, C, i);
    }
    else if(i%3 == 2) {
      cout << "Move disk " << i << " from A to B" << endl;  
      moveDisks(A, B, i);
    }  
    else {
      cout << "Move disk " << i << " from B to C" << endl;
      moveDisks(B, C, i);
    }
  }
}
int main() {

    Stack stackA, stackB, stackC; 

    int arr[] = { 10, 7, 8, 9, 1, 5 }; 
    int n = sizeof(arr) / sizeof(arr[0]);

    int luachon;

    do {
        cout << "1. Quick Sort\n";
        cout << "2. thap Hanoi\n";
        cout << "0. Thoat\n";
        cin >> luachon;

        switch (luachon) {

        case 1:
            quickSort(arr, 0, n - 1);
            cout << "Mang sau khi sap xep:\n";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;

        case 2:
            int numDisks;
            cout << "Nhap so dia: ";
            cin >> numDisks;

            towerOfHanoi(numDisks, stackA, stackB, stackC);
            break;

        case 0:
            break;

        default:
            cout << "Lua chon khong hop le\n";
        }

    } while (luachon != 0);

    return 0;
}

