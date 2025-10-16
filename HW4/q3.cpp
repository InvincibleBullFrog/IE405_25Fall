#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

int main() {
    std::srand(std::time(NULL));
    int lc[5];
    for (int i = 0; i < 5; i++) {
       lc[i] = std::rand() % 10;
    }
    int uc[5];
    std::cout << "Please Input Your Five Digit: ";
    for (int i = 0; i < 5; i++) {
        std::cin >> uc[i];
    }
    int c = 0;
    for (int i = 0; i < 5; i++) {
        if (std::abs(lc[i]-uc[i]) <= 1) {
            c++;
        }
    }
    for (int i = 0; i < 5; i++) {
            std::cout << lc[i];
    } std::cout << std::endl;
    if (c == 5) {
        std::cout << "Congrats! You Won! " << "\n";
    }
    else {
        std::cout << "Sorry, maybe you will win next time. \n";
    }
}