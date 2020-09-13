#include <iostream>

int get_fibonacci_last_digit_naive(int64_t n) {
    if (n <= 1)
        return n;
    int previous = 0;
    int current  = 1;
    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        current %= 10;
    }
    return current;
}

int main() {
    int64_t n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    return 0;
}
