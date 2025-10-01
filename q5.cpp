#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>

int main() {
    const int N = 20;
    char correct[N]{}, student[N]{};

    std::ifstream fc("CorrectAnswers.txt");
    std::ifstream fs("StudentAnswers.txt");
    if (!fc || !fs) {
        std::cout << "File open error\n";
        return 1;
    }

    auto readOne = [](std::ifstream& f, char arr[], int n) -> bool {
        std::string line;
        for (int i = 0; i < n; ++i) {
            if (!std::getline(f, line)) return false;
            char ans = 0;
            for (char ch : line) {
                if (!std::isspace((unsigned char)ch)) {
                    ans = (char)std::toupper((unsigned char)ch);
                    break;
                }
            }
            if (ans != 'A' && ans != 'B' && ans != 'C' && ans != 'D') return false;
            arr[i] = ans;
        }
        return true;
    };

    if (!readOne(fc, correct, N) || !readOne(fs, student, N)) {
        std::cout << "Bad input format. Must have 20 lines\n";
        return 1;
    }

    int ok = 0;
    for (int i = 0; i < N; ++i) if (student[i] == correct[i]) ++ok;

    double pct = ok * 100.0 / N;
    std::cout << "Total correct: " << ok << " out of " << N << "\n";
    std::cout << "Percentage: " << std::fixed << std::setprecision(1) << pct << "%\n";
    if (pct >= 75.0) std::cout << "Result: Passed\n";
    else             std::cout << "Result: Failed\n";
    return 0;
}