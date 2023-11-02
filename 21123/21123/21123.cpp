								  // 21123.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node() {
        left = NULL;
        right = NULL;
    }
    node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
typedef node * Nptr;

class Tree {
public:
    Nptr Root;
    node* createN (int x) {
        return new node(x);
    }
        void freeNode(Nptr &a) {
        if (a == NULL) return ;
        if (a->left == NULL && a->right == NULL) return;
        Nptr t = a;
        delete t;
        a = NULL;
    }
    bool isEmpty(Nptr a) {
        if (a->left == NULL && a->right == NULL) 
            return 0;
        return 1;
   }
    bool inL(Nptr a, int x) {
        if (a == NULL) return 0;
        if (a->left != NULL) return 0;
        Nptr i = createN(x);
        a->left = i;
        return 1;
    }
    bool inR(Nptr a, int x) {
        if (a == NULL) return 0;
        if (a->left != NULL) return 0;
        Nptr i = createN(x);
        a->right = i;
        return 1;
    }
    bool deleafL(Nptr &a) {
        if (a == NULL)return 0;
        if (a->left == NULL && a->right == NULL)
            return 0;
        
        Nptr x = a->left;
        delete x;
        x = NULL;
        return 1;
    }
    bool deleafR(Nptr &a) {
        if (a == NULL)return 0;
        if (a->left == NULL && a->right == NULL)
            return 0;

        Nptr x = a->right;
        delete x;
        x = NULL;
        return 1;
    }
    void preO(Nptr a) {

        if (a != NULL) {
           

            cout << " " << a->data;
            preO(a->left);
            preO(a->right);
                              }
    }
    void InO(Nptr a) {

        if (a != NULL) {

            preO(a->left);
            cout << " " << a->data;

            preO(a->right);
        }
    }
    void PostO(Nptr a)
        {

            if (a != NULL) {

                preO(a->left);
                preO(a->right);
                cout << " " << a->data;
            }
        }
     Nptr Search(Nptr a, int x)
        {

            Nptr p;
            if (a == NULL) return NULL;
            if (a->data == x) return a;
            p = Search(a->left, x);
            if (p == NULL)

                p = Search(a->right, x);

            return p;
        }
     void ClearTree(Nptr a)
     {

         if (a != NULL)
         {

             ClearTree(a->left);
             ClearTree(a->right);
             freeNode(a);
         }

     }




};
int main() {
    Tree tree; 

    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Them nut la ben trai\n";
        cout << "2. Them nut la ben phai\n";
        cout << "3. Loai bo nut la ben trai\n";
        cout << "4. Loai bo nut la ben phai\n";
        cout << "5. Hien thi cay theo tien thu tu\n";
        cout << "6. Hien thi cay theo giua thu tu\n";
        cout << "7. Hien thi cay theo sau thu tu\n";
        cout << "8. Tim nut theo gia tri\n";
        cout << "9. Xoa toan bo cay\n";
        cout << "0. Thoat\n";
        cout << "Chon mot tuy chon: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "Nhap gia tri cua nut:";
            cin >> value;
           tree.inL(tree.Root, value);
            break;
        }
        case 2: {
            int value;
            cout << "Nhap gia tri cua nut: ";
            cin >> value;
            tree.inR(tree.Root, value);
            break;
        }
        case 3: {

            tree.deleafL(tree.Root);
            break;
        }
        case 4: {
            tree.deleafR(tree.Root);
            break;
        }
        case 5: {
          
            tree.preO(tree.Root);
            cout << endl;
            break;
        }
        case 6: {
            tree.InO(tree.Root);
            cout << endl;
            break;
        }
        case 7: {
          
            tree.PostO(tree.Root);
            cout << endl;
            break;
        }
        case 8: {
            int value;
            cout << "Nhập giá trị cần tìm: ";
            cin >> value;
            Nptr result = tree.Search(tree.Root, value);
            if (result != NULL) {
                cout << "Nút có giá trị " << value << " tồn tại trong cây." << endl;
            }
            else {
                cout << "Nút có giá trị " << value << " không tồn tại trong cây." << endl;
            }
            break;
        }
        case 9: {

            tree.ClearTree(tree.Root);
            break;
        }
        case 0: {
            break;
        }
        default: {
            cout << "Tùy chọn không hợp lệ. Vui lòng chọn lại." << endl;
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
