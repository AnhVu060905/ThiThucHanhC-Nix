#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cout << "Nhap so luong phan tu (n > 0): ";
    while (!(cin >> n) || n <= 0) {
        cin.clear(); cin.ignore(1000, '\n');
        cout << "Nhap sai. Vui long nhap lai n > 0: ";
    }

    int arr[n];
    cout << "Nhap " << n << " so nguyen:\n";
    for (int i = 0; i < n; i++) {
        cout << "Phan tu [" << i << "]: ";
        cin >> arr[i];
    }

    // Dùng map de dem tan xuat  
    map<int, int> dem;
    for (int i = 0; i < n; i++) {
        dem[arr[i]]++;
    }

    cout << "\nCac gia tri phan biet (chi xuat hien 1 lan):\n";
    bool coPhanBiet = false;
    // Sd iterator de duyet map
    for (map<int, int>::iterator it = dem.begin(); it != dem.end(); ++it) {
        if (it->second == 1) {
            cout << it->first << " ";
            coPhanBiet = true;
        }
    }

    if (!coPhanBiet) {
        cout << "Khong co gia tri phan biet nao.\n";
    }

    return 0;
}

