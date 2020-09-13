#include <iostream>


using namespace std;


int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

void fib(int64_t n, int &a, int &b, int64_t i_fib_term_prev) {
    for (int64_t i = 0; i < n - i_fib_term_prev; ++i) {
        int c = a + b;  
        c %= 10;
        a = b;
        b = c;
    }
}

int fib_sum_squares(int64_t n) {
    if (n <= 2) return n;
    if (n == 3) return 6;
    int a = 0, b = 1;
    fib(n - 1, a, b, 1);
    int f_n2 = a, f_n1 = b;
    fib(n, a, b,  n - 1);
    int l1 = (b + f_n1), l2 = (f_n1 + f_n2);
    l1 %= 10;
    l2 %= 10;
    return (l1 * l2) % 10;

    // int a = 0, b = 1;
    // fib(n, a, b, 1);
    // return a * b;
}

int main() {
    long long n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_squares_naive(n);
    cout << fib_sum_squares(n);

}
