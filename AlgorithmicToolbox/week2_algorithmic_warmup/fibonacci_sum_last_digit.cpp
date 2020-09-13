#include <iostream>
#include <vector>

using namespace std;

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

vector<int64_t> get_period(int64_t m) {
    vector<int64_t> period({0,1,1});
    for (long long i = 3; ; ++i) {
        period.push_back((period[i-1] + period[i-2]) % m);
        if (period[i-1] == 0 && period[i] == 1) {
            period.pop_back(); 
            period.pop_back();
            return period;
        }
    }
}

int fib_mod(int64_t n, int64_t m) {
    auto period = get_period(m);
    n %= period.size();
    return period[n];  // 
}

int get_fib_sum_last_digit(int64_t n) {
    auto period = get_period(10);
    n = (n + 2) % period.size();
    if (period[n] == 0) return 9;
    return period[n] - 1;
}

int main() {
    int64_t n;
    std::cin >> n;
    int c = get_fib_sum_last_digit(n);
    std::cout << c;
    return 0;
}
