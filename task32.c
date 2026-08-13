// gcc -std=c17 -Wall -Wextra -o task32 task32.c && ./task32

#include <iostream>
#include <vector>
#include <algorithm>

void printSum(const std::vector<int>& data) {
    int sum = 0;
    for (int v : data) sum += v;
    std::cout << "Сумма: " << sum << '\n';
}

int main() {
    std::vector<int> numbers = {5, 3, 8, 1, 9, 2};

    printSum(numbers);

    std::sort(numbers.begin(), numbers.end(),
              [](int a, int b) { return a > b; });

    std::cout << "По убыванию: ";
    for (int v : numbers) std::cout << v << ' ';
    std::cout << '\n';

    int threshold = 4;
    int count = std::count_if(numbers.begin(), numbers.end(),
                               [threshold](int v) { return v > threshold; });
    std::cout << "Элементов больше " << threshold << ": " << count << '\n';

    return 0;
}
