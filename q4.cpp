#include <iostream>
#include <vector>

int main() {
    std::cout << "Enter an integer: ";
    long long n;
    if (!(std::cin >> n)) return 0;

    const char* name[10] = {
        "zero","one","two","three","four","five","six","seven","eight","nine"
    };

    if (n == 0) {
        std::cout << "zero\n";
        return 0;
    }

    bool neg = n < 0;
    unsigned long long x = neg ? -(unsigned long long)n : (unsigned long long)n;

    std::vector<int> digits;
    while (x > 0) {
        digits.push_back(x % 10);
        x /= 10;
    }

    if (neg) std::cout << "minus ";

    for (int i = (int)digits.size() - 1; i >= 0; --i) {
        std::cout << name[digits[i]];
        if (i) std::cout << ' ';
    }
    std::cout << '\n';
    return 0;
}