#include <iostream>
using namespace std;

int main() {
    int n;

    do {
        cout << "Nhap so luong phan tu n (> 0): ";
        cin >> n;

        if (cin.fail() || n <= 0) {
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            cout << "Khong hop le. Nhap lai di bro.\n";
        }
    } while (n <= 0);

    int arr[n];
    cout << "Nhap " << n << " so nguyen:\n";
    for (int i = 0; i < n; i++) {
        cout << "Phan tu thu [" << i << "]: ";
        cin >> arr[i];
    }

    bool coSoChiaHet3 = false;
    int maxChiaHetCho3;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 3 == 0) {
            maxChiaHetCho3 = arr[i];
            coSoChiaHet3 = true;
            break;
        }
    }

    if (coSoChiaHet3) {
        for (int i = 0; i < n; i++) {
            if (arr[i] % 3 == 0 && arr[i] > maxChiaHetCho3) {
                maxChiaHetCho3 = arr[i];
            }
        }
        cout << "So lon nhat chia het cho 3 la: " << maxChiaHetCho3 << endl;
    } else {
        cout << "khong co" << endl;
    }

    return 0;
}

