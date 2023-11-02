//visualstudio
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
///==============Khoi ta===============	
struct Sv
{
	string MSSV;
	string Name;
	bool Sex;
	string Add;
	float Score;
};                        //1 nam 0 nu
struct node {
	Sv info;
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
node* createNode(Sv x) {
	node* nNo = new node;
	if (nNo == NULL) {
		return NULL;
	}
	nNo->info = x;
	nNo->next = NULL;
	return nNo;
}
void xuat(Listnode l) {
	node* pt = l.Head;

	if (pt == NULL) {
		cout << "\nDanh sach rong"; 
	}
	else {
		int i = 0;
		while (pt != NULL) {
			cout << "\n===========================\nMS : " << pt->info.MSSV;
			cout << "\nTen: " << pt->info.Name;
			cout << "\nDia chi:" << pt->info.Add;
			cout << "\nGioi tinh:";
			if (pt->info.Sex == 1) 	cout << "Nam"; else cout << "Nu";


			cout << "\nDiem: " << pt->info.Score;
			i++;
			pt = pt->next;
		}
	}
}//===============THem=================================
void xuatSV(node* pt) {
	cout << "\n\nMS :" << pt->info.MSSV;
	cout << "\nTen:" << pt->info.Name;
	cout << "\nDia chi: " << pt->info.Add;
	cout << "\nGioi tinh: "; if (pt->info.Sex == 1) 	cout << "Nam"; else cout << "Nu";
	;
	cout << "\nDiem: " << pt->info.Score;
}

//====================Them=========================

void nhapSV(Sv& x) {
	cout << "Nhap MSSV: ";
	cin >> x.MSSV;
	cout << "Nhap Ten: ";
	cin >> x.Name;
	cout << "Nhap Gioi tinh (1 nam, 0 nu): ";

		cin >> x.Sex;

	cout << "Nhap Dia chi: ";
	cin >> x.Add;
	cout << "Nhap Diem: ";
	cin >> x.Score;
}
void addHead(Listnode& l, node* N) {
	if (l.Head == NULL) {
		l.Head = l.Tail = N;
	}
	else {
		N->next = l.Head;
		l.Head = N;
	}
}
void addAfterQ(Listnode& l, node* p, node* q ){
	if (p == NULL) {
		cout << "Node sau khong ton tai";
		return;
	}

	q->next = p->next;
	p->next = q;

	if (p == l.Tail) {
		l.Tail = q;
	}
}
void addTail(Listnode& l, node* N) {
	if (l.Tail == NULL) {
		l.Tail = l.Head = N;
	}
	else {
		l.Tail->next = N;
		l.Tail = N;
	}
}
//====================Xoa=============================
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
//+====================QUan li==========================
 node* findMS(Listnode l, string x) {
	node* N = l.Head;
	while (N != NULL && N->info.MSSV != x) {
		N = N->next;
	}
	return N;
}
 void sSortDesc(Listnode& l) {
	 node* i = l.Head;
	 while (i != NULL) {
		 node* max = i;
		 node* next = i->next;

		 while (next != NULL) {
			 if (max->info.Score < next->info.Score) {
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
 int  srNam(Listnode l) {

	 node* pt = l.Head;
	 int i = 0;
	 if (pt == NULL) {
		 cout << "\nDanh sach rong"; return 0;
	 }
	 else {
		 
		 while (pt != NULL) {
			 if (pt->info.Sex == 1) {
				 i++;
			 }
			 pt = pt->next;
		 }
	 }

	 return i;
 }
 bool Score5(float d) {
	 if (d >= 5) {
		 return 1;
	 }       return 0;
 }
 void srD5(Listnode l) {
	 node* pt = l.Head;
	 if (pt == NULL) {
		 cout << "\nDanh sach rong"; return;
	 }
	 else {
		 while (pt != NULL) {
			 if (Score5(pt->info.Score)) {
				 xuatSV(pt);
			 }
			 pt = pt->next;
		 }
	 }
 }
 void updateDiem(Listnode& l, node* n,float diem) {
	 n->info.Score = diem;
 }
 void Par(Listnode& l) {
	 if (l.Head == l.Tail) return;
	 Listnode l1, l2;
	 createList(l1);
	 createList(l2);
	 node* tag = l.Head;
	 l.Head = l.Head->next;
	 tag->next = NULL;
	 node* p = l.Head;
	 Sv Temp;
	 while (p != NULL) {
		 node* next = p->next;
		 if (p->info.Score <= tag->info.Score) {
			 Temp = p->info;
			 addHead(l1, createNode(Temp));
		 }
		 else
		 {
			 Temp = p->info;
			 addHead(l2, createNode(Temp));
		 }
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
 /// =========random======
 void Taoran(Sv& x) {
	 x.MSSV = to_string(  rand() % 100);
	 x.Name = rand() % 100;
	 x.Sex = rand() % 2;
	 x.Add = to_string(rand() % 1000);
	 x.Score = rand() % 100;
 }
 void Random(Listnode& l) {
	 Sv newSV;
	 for (int i = 0; i < 5; i++) {
		 Taoran(newSV);
		 addTail(l, createNode(newSV));
	 }
 }
 ////======================
 int main()
{
 
	Listnode list{ NULL,NULL };
	createList(list);
	Sv newSV;


	int luaChon = 0;
	
	string maso; string ten; bool GT; string diachi; float scor;
	
	
	do {
		cout << "\n\n\n\n============Lua chon:=============";
		cout << "\n0. thoat";
		cout << "\n1. Them mot phan tu vao dau ds";
		cout << "\n2. Them mot phan tu vao cuoi ds";
		cout << "\n3. Them mot phan tu vao phia sau mot node(theo MS)";

		cout << "\n4. Xuat ra man hinh";
		cout << "\n5. Liet ke sinh vien >5";
		cout << "\n6. Dem so sv nam";

		cout << "\n7. Xoa phan tu dau ds";
		cout << "\n8. Xoa mot phan tu vao phia sau mot node (theo MS)";
		cout << "\n9. Xoa toan bo ds";

		cout << "\n10. Xap xep toan bo ds(sel giam dan)";
		cout << "\n11. Xap xep toan bo ds(quick tang dan)";
		cout << "\n12.Cap nhap diem theo MS";
		cout << "\n";
		cout << "\n13.Random 5 sv(TEST)";

		//
		cout << "\n Nhap lua chon: ";

		cin >> luaChon;
		switch (luaChon) {
		case 1:
			system("cls");
	
			nhapSV(newSV);
			addHead(list, createNode(newSV) );
			break;
		case 2:
			system("cls");
		
			nhapSV(newSV);
			addTail(list, createNode(newSV));
			break;
		case 3:
			system("cls");
			
			xuat(list);
			cout << "\n Nhap MS cua sv can them phia sau ";
			cin >> maso;
			if (findMS(list, maso) == NULL) {
				cout << "\nKhong tim thay";
			}
			else {
				nhapSV(newSV);
				addAfterQ(list, findMS(list, maso), createNode(newSV));
			}
			break;
		case 4:
			system("cls");
			cout << "\nDanh sach:";
			xuat(list);
			break;
		case 5:
			system("cls");
			cout << "Liet ke sinh vien >5";
			srD5(list);
			break;
		case 6:
			system("cls");
			cout <<" so sV nam la : " << srNam(list);
			break;
		case 7:
			system("cls");
			reHead(list);
			cout << "Da xoa";
			break;
		case 8:
			system("cls");
			 xuat(list);
			cout << "\nNhap MSSV";

			cin >> maso;
			reAfterQ(list, findMS(list, maso));
			cout << "\nDa xoa ";

			break;
		case 9:
			system("cls");
			reAll(list);
			break;
		case 10:
			system("cls");
			sSortDesc(list);
			xuat(list);
			 
			break;
		case 11:
			
			system("cls");
			Par(list);
			xuat(list);
			break;
		case 12:
			system("cls");
			if (list.Head == NULL) { cout << "Danh sach rong"; }
			else {
				xuat(list);
				cout << "\nNhap Ms";
				cin >> maso;
				xuatSV(findMS(list, maso));

				cout << "\n Nhap diem can thay doi";
				cin >> scor;
				updateDiem(list, findMS(list, maso), scor);
			}
			break;
		case 13:
			system("cls");
			Random(list);
			break;
		default:
			system("cls");
			cout << "\nKhong hop le.";
			break;
		}
	} while (luaChon != 0);
	return 0;
}