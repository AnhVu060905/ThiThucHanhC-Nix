#include <iostream>
#include <vector>

using namespace std;

// Ham tinh so Fibonacci sd Memoization
long long fibonacci(int n, vector<long long>& memo) {
    if (n <= 0) return 0;  // Trý?ng h?p không h?p l?
    if (n == 1 || n == 2) return 1; // F1 = F2 = 1

    // Kiem tra neu gia tri da dc tinh trc do
    if (memo[n] != -1) return memo[n];

    // Tinh toan va luu ket qua
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

int main() {
    int n;
    cout << "Nhap so nguyen n (1 <= n <= 30): ";
    cin >> n;

    if (n < 1 || n > 30) {
        cout << "Cau oi, to bao la nhap tu 1-30 sao ma cau ly qua v????.\n";
        return 1;
    }

    // Khoi too mang memoization voi gia tri -1 
    vector<long long> memo(n + 1, -1);
    
    cout << "So Fibonacci th? " << n << " là: " << fibonacci(n, memo) << endl;
    cout << "Day Fibonacci tu F(1) F(" << n << "):\n";
    for (int i = 1; i <= n; i++) {
        cout << fibonacci(i, memo) << " ";
    }


    return 0;
}
