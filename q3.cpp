#include <iostream>
#include <cstdlib> 
#include <ctime> 

using namespace std;

void coinToss() {
    int r = rand() % 2 + 1;
    if (r == 1) {
        cout << "heads" << endl;
    } else {
        cout << "tails" << endl;
    }
}

int main() {
    int n;
    cout << "How many tosses? ";
    cin >> n;

    srand(time(0));

    for (int i = 0; i < n; i++) {
        coinToss();
    }

    return 0;
}