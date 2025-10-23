#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cout << "Input the size of the set: ";
    cin >> n;
    int * a = new int[n];
    cout << "Input the set: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int maximum = a[0];
    for (int i = 0; i < n; i++) {
        if (maximum < a[i])
            maximum = a[i];
    }
    int *c = new int[maximum+1]; // c[j] := the time number j occurs in the set
    for (int i = 0; i < n; i++) {
        c[a[i]]++;
    }
    int max_time = c[0];
    for (int i = 0; i <= maximum; i++) {
        if (c[i] > max_time) {
            max_time = c[i];
        }
    }
    for (int i = 0; i <= maximum; i++) {
        if (c[i] == max_time && c[i] >= 2)
            cout << i << ' ';
    }
    cout << endl;

    return 0;
}