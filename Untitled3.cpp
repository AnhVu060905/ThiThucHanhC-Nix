#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct SinhVien {
    string ten;
    float toan, ly, hoa, dtb;
};

float nhapDiem(string mon) {
    float diem;
    do {
        cout << "Nhap diem mon  " << mon << " di bro: ";
        cin >> diem;
        if (diem < 0 || diem > 10) {
            cout << "Nhap diem cung sai. Lam on nhap lai!\n";
        }
    } while (diem < 0 || diem > 10);
    return diem;
}

void nhapSinhVien(SinhVien &sv) {
    cin.ignore(); // 
    cout << "Xin cai ten: ";
    getline(cin, sv.ten);

    sv.toan = nhapDiem("Toan");
    sv.ly   = nhapDiem("Ly");
    sv.hoa  = nhapDiem("Hoa");

    sv.dtb = (sv.toan + sv.ly + sv.hoa) / 3;
}

void nhapDanhSach(SinhVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":\n";
        nhapSinhVien(ds[i]);
    }
}

void inSinhVienGioi(SinhVien ds[], int n) {
    cout << "\nSinh vien co diem trung binh >= 8:\n";
    bool timThay = false;
    for (int i = 0; i < n; i++) {
        if (ds[i].dtb >= 8.0) {
            cout << "- " << ds[i].ten 
                 << " | DTB: " << fixed << setprecision(2) << ds[i].dtb << endl;
            timThay = true;
        }
    }
    if (!timThay) {
        cout << "Khong co sinh vien nao co diem trung binh >= 8.\n";
    }
}

void inTatCaSinhVien(SinhVien ds[], int n) {
    cout << "Diem tb cua tat ca sinh vien";
    for (int i = 0; i < n; i++) {
            cout << "- " << ds[i].ten 
                 << " | DTB: " << fixed << setprecision(2) << ds[i].dtb << endl;
    }
}
int main() {
    const int MAX = 100;
    SinhVien ds[MAX];
    int n = 0;
    int choice;

    do {
        cout << "\n====== MENU ======\n";
        cout << "1. Nhap danh sach sinh vien\n";
        cout << "2. In sinh vien co diem trung binh >= 8\n";
        cout << "3. In diem tb tat ca sinh vien\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

        switch (choice) {
            case 1:
                do {
                    cout << "Nhap so luong sinh vien (1 - " << MAX << "): ";
                    cin >> n;
                    if (cin.fail() || n <= 0 || n > MAX) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "So luong khong hop le. Vui long nhap lai!\n";
                    }
                } while (n <= 0 || n > MAX);
                nhapDanhSach(ds, n);
                break;

            case 2:
                if (n == 0) {
                    cout << "Chua co du lieu sinh vien. Vui long nhap truoc.\n";
                } else {
                    inSinhVienGioi(ds, n);
                }
                break;
                
             case 3:
                if (n == 0) {
                    cout << "Chua co du lieu sinh vien. Vui long nhap truoc.\n";
                } else {
                    inTatCaSinhVien(ds, n);
                }
                break;

            case 0:
                cout << "Tam biet!\n";
                break;

            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }

    } while (choice != 0);

    return 0;
}

