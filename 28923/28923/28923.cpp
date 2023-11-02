#include <iostream>
#include <cstdlib> 
using namespace std;
struct node {
	int info;
	node* next;
};

struct Listnode {
	node* Head;
	node* Tail;
};

void createList(Listnode& list) {
	list.Head = NULL;
	list.Tail = NULL;
}
node* createNode(int x) {
	node* nNo = new node;
	if (nNo == NULL) {
		return NULL;
	}
	nNo->info = x;
	nNo->next = NULL;
	return nNo;
}
void addHead(Listnode& l, int x) {
	node* N = createNode(x);
	if (l.Head == NULL) {
		l.Head = l.Tail = N;
	}
	else {
		N->next = l.Head;
		l.Head = N;
	}
}
void addAfter(Listnode& l, node* p, int x) {
	if (p == NULL) {
		cout << "Node sau khong ton tai";
		return;
	}

	node* newNode = createNode(x);
	newNode->next = p->next;
	p->next = newNode;

	if (p == l.Tail) {
		l.Tail = newNode;
	}
}
void addTail(Listnode& l, int x) {
	node* N = createNode(x);
	if (l.Tail == NULL) {
		l.Tail = l.Head = N;
	}
	else {
		l.Tail->next = N;
		l.Tail = N;
	}
}
node* findNode(Listnode l, int x) {
	node* N = l.Head;
	while (N != NULL && N->info != x) {
		N = N->next;
	}
	return N;
}
void reHead(Listnode& l) {
	if (l.Head == NULL) {
		cout << "\n Danh Sach rong";
	}
	else {
		node* N = l.Head;
		l.Head = l.Head->next;
		N->next = NULL;
		delete N;
	}
}
void reTail(Listnode& l) {
	if (l.Tail == NULL) {
		cout << "\n Danh Sach rong";
	}
	else {
		node* N = l.Head;
		if (l.Head == l.Tail) {
			l.Head = l.Tail = NULL;
		}
		else {
			while (N->next != l.Tail) {
				N = N->next;
			}
			N->next = NULL;
			delete l.Tail;
			l.Tail = N;
		}
	}
}
void reAll(Listnode& l) {
	node* N = l.Head;
	if (N == NULL) {
		cout << "Danh sach da rong";
	}
	else
	{
		while (N != NULL)
		{
			node* p = N;
			N = N->next;
			delete p;
		}
	}
	l.Head = NULL;
	l.Tail = NULL;
}
void reAfterQ(Listnode& l, node* Q) {
	if (Q == NULL || Q->next == NULL) {
		cout << "Khong co node de xoa";
	}
	else {

		node* d = Q->next;
		Q->next = d->next;
		delete d;

		if (Q->next == NULL) {
			l.Tail = Q;
		}
	}
}
void xuat(Listnode l) {
	node* pt = l.Head;

	if (pt == NULL) {
		cout << "\nDanh sach rong"; exit(1);
	}
	else {
		int i = 0;
		while (pt != NULL) {
			cout << "\n" << pt->info;
			i++;
			pt = pt->next;

		}

	}
}
void sSort(Listnode& l) {
	node* i = l.Head;
	while (i != NULL) {
		node* min = i;
		node* next = i->next;

		while (next != NULL) {
			if (min->info > next->info) {
				min = next;
			}
			next = next->next;
		}

		if (min != i) {
			swap(min->info, i->info);
		}

		i = i->next;
	}
}
bool isOdd(int so) {
	return so % 2 == 1;
}
void srOdd(Listnode l) {
	node* pt = l.Head;
	if (pt == NULL) {
		cout << "\nDanh sach rong"; return;
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
void srEven(Listnode l) {
	node* pt = l.Head;
	if (pt == NULL) {
		cout << "\nDanh sach rong"; return;
	}
	else {
		while (pt != NULL) {
			if (isOdd(pt->info) == 0) {
				cout << "\n" << pt->info;
			}
			pt = pt->next;
		}
	}
}
void findMin(Listnode l) {
	node* pt = l.Head;
	if (pt == NULL) {
		cout << "\nDanh sach rong"; return;
	}
	int min = pt->info;
	while (pt != NULL) {
		if (min > pt->info) {
			min = pt->info;
		}
		pt = pt->next;
	}
	cout << "Phan tu co gia tri nho nhat la: " << min;
}
void sSortDesc(Listnode& l) {
	node* i = l.Head;
	while (i != NULL) {
		node* max = i;
		node* next = i->next;

		while (next != NULL) {
			if (max->info < next->info) {
				max = next;
			}
			next = next->next;
		}

		if (max != i) {
			swap(max->info, i->info);
		}

		i = i->next;
	}
}

/// //////////////////////////////////
//void QuickSort(Listnode& l) {
//	Listnode l1, l2;
//	node* tag, * p;
//	if (l.Head == NULL || l.Head == l.Tail) return;
//	createList(l1);
//	createList(l2);
//	tag = l.Head;
//	l.Head = l.Head->next;
//	tag->next = NULL;
//
//	while (l.Head !=NULL) {
//		p = l.Head;
//
//		l.Head = l.Head->next;
//
//		p->next = NULL;
//		if (p->info <= tag->info)
//		
//			addHead(l1, p->info);
//		
//		else
//		
//			addHead(l2, p->info);
//			 //xuat(l1);
//	}	 //x);
//		QuickSort(l1);
//		QuickSort(l2);
//
//		if (l1.Head != NULL) {
//			l.Head = l1.Head;
//			l1.Tail->next = tag;
//		}
//		else {
//			l.Head = tag;
//		}
//		tag->next = l2.Head;
//
//		if (l2.Head != NULL) {
//			l.Tail = l2.Tail;
//		}
//		else {
//			l.Tail = tag;
//		}
//	
//
//}

void Par(Listnode& l) {
	if (l.Head==l.Tail) return;
		Listnode l1, l2;
		createList(l1);
		createList(l2);
		node* tag = l.Head;
		l.Head = l.Head->next;
		tag->next = NULL;
		node* p = l.Head;

		while (p != NULL) {
			node* next = p->next;
			if (p->info <= tag->info) {
				addHead(l1, p->info);
			}
			else addHead(l2, p->info);
			p = next;
		}

		Par(l1);
		Par(l2);

		if (l1.Head != NULL) {
			l.Head = l1.Head;
			l1.Tail->next = tag;
		}
		else {
			l.Head = tag;
		}
		tag->next = l2.Head;

		if (l2.Head != NULL) {
			l.Tail = l2.Tail;
		}
		else {
			l.Tail = tag;
		}
	}

void MergeSo(Listnode& l) {







}
void findMax(Listnode l) {
	node* pt = l.Head;
	if (pt == NULL) {
		cout << "\nDanh sach rong"; return;
	}
	int max = pt->info;
	while (pt != NULL) {
		if (max < pt->info) {
			max = pt->info;
		}
		pt = pt->next;
	}
	cout << "Phan tu co gia tri lon nhat la: " << max;
}
void reKey(Listnode& l, int x) {
	while (l.Head != NULL && l.Head->info == x) {
		node* temp = l.Head;
		l.Head = l.Head->next;
		delete temp;
	}

	if (l.Head == NULL) {
		l.Tail = NULL;
		return;
	}

	node* p = l.Head;
	while (p->next != NULL) {
		if (p->next->info == x) {
			node* temp = p->next;
			p->next = p->next->next;
			delete temp;
		}
		else {
			p = p->next;
		}
	}

	if (l.Tail->info == x) {
		delete l.Tail;
		l.Tail = p;
		l.Tail->next = NULL;
	}
}
int main() {
	Listnode list{ NULL,NULL };
	createList(list);
	for (int i = 0; i < 5; i++) {
		int randomNumber = rand() % 100;
		addTail(list, randomNumber);
	}
	int luaChon = 0;
	int x;
	int p;
	int a;
	do {
		cout << "\n\n\n\n============Lua chon:=============";
		cout << "\n1. Them mot phan tu vao dau ds";
		cout << "\n2. Them mot phan tu vao cuoi ds";
		cout << "\n3. Them mot phan tu vao phia sau mot node";
		cout << "\n4. Xuat ra man hinh";
		cout << "\n5. Liet ke cac gia tri chan";
		cout << "\n6. Liet ke cac gia tri le";
		cout << "\n7. Tim lon nhat";
		cout << "\n8. Tim nho nhat";
		cout << "\n9. Tim phan tu co khoa x";
		cout << "\n10. Xoa phan tu dau ds";
		cout << "\n11. Xoa phan tu co khoa x";
		cout << "\n12. Xoa mot phan tu vao phia sau mot node";
		cout << "\n13. Xoa toan bo ds";
		cout << "\n14. Xap xep toan bo ds(sel giam dan)";
		cout << "\n15. Xap xep toan bo ds(quick tang dan)";

		cout << "\n Nhap lua chon: ";

		cin >> luaChon;
		switch (luaChon) {
		case 1:
			system("cls");
			cout << "\nNhap x:";
			cin >> x;
			addHead(list, x);
			break;
		case 2:
			system("cls");
			cout << "\nNhap x: ";
			cin >> x;
			addTail(list, x);
			break;
		case 3:
			system("cls");
			xuat(list);
			cout << "\nNhap Gia tri cua node can them phia sau";
			cin >> p;

			if (findNode(list, p) == NULL) {
				cout << "\nKhong tim thay";
			}
			else {
				cout << "\n Nhap so can them";
				cin >> a;
				addAfter(list, findNode(list, p), a);
			}
			break;
		case 4:
			system("cls");
			cout << "\nDanh sach:";
			xuat(list);
			break;
		case 5:
			system("cls");
			cout << "Danh sach so chan  ";
			srEven(list);
			break;
		case 6:
			system("cls");
			cout << "Danh sach so le ";
			srOdd(list);
			break;
		case 7:
			system("cls");
			findMax(list);
			break;
		case 8:
			system("cls");
			findMin(list);
			break;
		case 9:
			system("cls");
			xuat(list);
			cout << "\nNhap Gia tri can tim";
			cin >> p;
			if (findNode(list, p) == NULL) {
				cout << "\nKhong tim thay";
			}
			else {
				cout << "\n Tim thay ";
			}
			break;
		case 10:
			system("cls");
			xuat(list);
			cout << "\nNhap Gia tri can xoa";
			cin >> p;

			if (findNode(list, p) == NULL) {
				cout << "\nKhong tim thay";
			}
			else {
				cout << "\n Nhap so can them";
				cin >> a;
				reAfterQ(list, findNode(list, p));
			}
			break;
		case 11:
			system("cls");
			xuat(list);
			cout << "\nNhap Gia tri can xoa dau danh sach";
			cin >> p;

			if (findNode(list, p) == NULL) {
				cout << "\nKhong tim thay";
			}
			else {
				reKey(list, p);
			}
			break;
		case 12:
			system("cls");
			xuat(list);
			cout << "\nNhap Gia tri can xoa phia sau q";

			cin >> p;

			if (findNode(list, p) == NULL) {
				cout << "\nKhong tim thay";
			}
			else {
				reAfterQ(list, findNode(list, p));
			}
			break;
		case 13:
			system("cls");
			reAll(list);
			break;
		case 14:   			system("cls");

			sSortDesc(list);
			cout << " Da xap xep (S-de)";

			break;
		case 15:   			system("cls");

			Par(list);
			cout << " Da xap xep (Q-in)";

			break;
		default:
			system("cls");
			cout << "\nKhong hop le.";
			break;
		}

	} while (luaChon != 0);
	return 0;
}

