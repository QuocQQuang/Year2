#include <iostream>
using namespace std;
struct node {
	int info;
	node* next;
};
struct Listnode {
	node *Head;
	node *Tail;
};
Listnode li;
void createList(Listnode list) {
	list.Head = NULL;
	list.Tail = NULL;
}
node* createNode(int x) {
	node* nNo = new node;
	if (nNo == NULL) {
		exit(1);
	}
	nNo->info = x;
	nNo->next = NULL;
	return nNo;
}
void addHead(Listnode &l, int x) {
	node* N = createNode(x);

	if (l.Head == NULL) {
		l.Head=l.Tail = N;
	 }
	else {
		N->next = l.Head;
		l.Head = N;
	}
}
void addBottom(Listnode& l, node* N1,node *N2 ) {

	N2->next = N1->next;
	N1->next = N2;
}
void addTail(Listnode& l, int x) {
	node* N =createNode(x);
	if (l.Tail == NULL) {;
		l.Tail =l.Head= N;
	}
	else {
		l.Tail->next = N; // -> truy cap thang node cuoi cung qua con tro l.tail
		l.Tail = N;
	}
}
void xuat(Listnode l) { //const
	node *pt = l.Head;

	if (pt == NULL) {
		cout << "\nDanh sach rong";
	}
	else {
		while (pt != NULL) {
			cout << "\n" << pt->info;	pt = pt->next;
		}
		
	}
}
bool isOdd(int so) {
	return so % 2 == 1;
}
void srOdd(Listnode l) {
	node* pt = l.Head;
	if (pt == NULL) {
		cout << "\nDanh sach rong";
	}
	else {

		while (pt != NULL) {
			if (isOdd(pt->info)) {
				cout << "\n" << pt->info;
			}
			pt = pt->next;
		}
	}
}
	void findMin(Listnode l) {
		node* pt = l.Head;
		if (pt == NULL) {
			cout << "\nDanh sach rong";
		}
		int min = pt->info;
		if (pt == NULL) {
			cout << "\nDanh sach rong";
		} while (pt != NULL) {
			if (min > pt->info) {
				min = pt->info;
			}pt = pt->next;
		}
		cout << "Phan tu co gia tri nho nhat la: " << min;
	}
	int main() {
		Listnode list{NULL,NULL};
		int luaChon=0;
		int x;
		do {
			
			cout << "\n\n\n\n============Lua chon:=============";
			cout << "\n1. Them mot phan tu vao dau ds";
			cout << "\n2. Them mot phan tu vao cuoi ds";
			cout << "\n3. Xuat ra man hinh";
			cout << "\n4. Liet ke cac gia tri le";
			cout << "\n5. Tim nho nhat";
			cout << "\nNhap lua chon: ";
			cin >> luaChon;
			switch (luaChon) {
			case 1:		  system("cls");
				cout << "\nNhap x:";
				cin >> x;
				addHead(list, x);
				break;
			case 2:			system("cls");
				cout << "\nNhap x: ";
				cin >> x;
				addTail(list, x);
				break;
			case 3:			system("cls");
				cout << "\nDanh sach:";
				xuat(list);
				break;
			case 4:			  system("cls");
				cout << "Danh sach so le ";
				srOdd(list); break;
			case 5: 	 system("cls");
				findMin(list);	break;
			default:	 system("cls");
				cout << "\nKhong hop le.";	system("cls");
				break;
			}

		} while (luaChon != 0);
		return 0;
}
 