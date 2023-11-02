#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SinhVien {
private:
    int MS;
    string HoTen;
    float DiemCSDL;
    float DiemCTDL;
    float DTB;

public:
    SinhVien(int ms = 0, string ten = "", float csdl = 0.0, float ctdl = 0.0) {
        MS = ms;
        HoTen = ten;
        DiemCSDL = csdl;
        DiemCTDL = ctdl;
        DTB = (DiemCSDL + DiemCTDL) / 2;
    }

    void NhapThongTin() {
        cout << "Nhap Ma So (3 chu so): ";
        cin >> MS;
        if (MS < 100 || MS > 999) {
            cout << "Ma So phai co 3 chu so!" << endl;
            return;
        }
        cin.ignore();

        cout << "Nhap Ho Ten: ";
        getline(cin, HoTen);

        cout << "Nhap Diem CSDL: ";
        cin >> DiemCSDL;

        cout << "Nhap Diem CTDL: ";
        cin >> DiemCTDL;

        DTB = (DiemCSDL + DiemCTDL) / 2;
    }

    void XuatThongTin() {
        cout << "Ma So: " << MS << endl;
        cout << "Ho Ten: " << HoTen << endl;
        cout << "Diem CSDL: " << DiemCSDL << endl;
        cout << "Diem CTDL: " << DiemCTDL << endl;
        cout << "Diem Trung Binh: " << DTB << endl;
    }

    int LayMS() const {
        return MS;
    }

    float LayDTB() const {
        return DTB;
    }

    bool TimTheoDiemDL(float diem) const {
        return DTB < diem;
    }
};

class QuanLySinhVien {
private:
    vector<SinhVien> danhSachSinhVien;

public:
    void ThemSinhVien() {
        SinhVien sv;
        sv.NhapThongTin();
        danhSachSinhVien.push_back(sv);
    }

    void XuatDanhSachSinhVien() {
        cout << "\nDanh sach sinh vien:" << endl;
        for (int i = 0; i < danhSachSinhVien.size(); i++) {
            danhSachSinhVien[i].XuatThongTin();
            cout << endl;
        }
    }

    void TimSinhVienTheoDiemDL(float diem) {
        cout << "\nSinh vien co DTB < " << diem << ":" << endl;
        for (int i = 0; i < danhSachSinhVien.size(); i++) {
            if (danhSachSinhVien[i].TimTheoDiemDL(diem)) {
                danhSachSinhVien[i].XuatThongTin();
                cout << endl;
            }
        }
    }


    void SapXepTheoMS() {
        int n = danhSachSinhVien.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (danhSachSinhVien[i].LayMS() > danhSachSinhVien[j].LayMS()) {
                    swap(danhSachSinhVien[i], danhSachSinhVien[j]);
                }
            }
        }
    }

};

int main() {
    QuanLySinhVien quanLySV;
    int luaChon;
    float diem;

    do {
        cout << "\nLua chon:";
        cout << "\n1. Them sinh vien";
        cout << "\n2. Xuat danh sach sinh vien";
        cout << "\n3. Sap xep theo MS";
        cout << "\n4. Tim sinh vien theo Diem DL";
        cout << "\n5. Thoat";
        cout << "\nNhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1:
            quanLySV.ThemSinhVien();
            break;
        case 2:
            quanLySV.XuatDanhSachSinhVien();
            break;
        case 3:
            quanLySV.SapXepTheoMS();
            cout << "\nDa sap xep theo MS.";
            break;
        case 4:
            cout << "\nNhap Diem DL can tim: ";
            cin >> diem;
            quanLySV.TimSinhVienTheoDiemDL(diem);
            break;
        case 5:
            cout << "\nTam biet!";
            break;
        default:
            cout << "\nLua chon khong hop le.";
            break;
        }

    } while (luaChon != 5);

    return 0;
}
