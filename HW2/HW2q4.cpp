#include <iostream>

int main() {
    std::cout << "Enter an integer: ";
    long long n;
    if (!(std::cin >> n)) {
        std::cout << "Invalid input.\n";
        return 1;
    }

    long long x = (n < 0) ? -n : n;
    long long sum = 0;
    unsigned long long product = 1;

    if (x == 0) {
        sum = 0;
        product = 0;
    } else {
        while (x > 0) {
            int d = static_cast<int>(x % 10);
            sum += d;
            product *= static_cast<unsigned long long>(d);
            x /= 10;
        }
    }

    std::cout << "Sum is " << sum << " and Product is " << product << '\n';
    return 0;
}