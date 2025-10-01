#include <iostream>
using namespace std;

int main() {
    int a[5];
    cout << "Enter 5 integers: ";
    for (int i = 0; i < 5; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 5; ++i) a[i] *= a[i];
    for (int i = 0; i < (5/2); ++i) swap(a[i], a[4-i]);

    for (int i = 0; i < 5; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
} 