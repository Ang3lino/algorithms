#include <iostream>
#include <vector>


using std::vector;
using std::cout;
using std::endl;


long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;
    long long current = 0;
    long long next  = 1;
    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
            sum %= 10;
        }
        long long new_current = next;
        next = next + current;
        current = new_current;
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

int get_fib_sum_last_digit(int64_t n) {
    auto period = get_period(10);
    n = (n + 2) % period.size();
    if (period[n] == 0) return 9;
    return period[n] - 1;
}

int get_fibonacci_partial_sum(int64_t from, int64_t to) {
    int64_t high = get_fib_sum_last_digit(to);
    if (from == 0) 
        return high;
    int64_t low = get_fib_sum_last_digit(from - 1);
    if (low >= high) high += 10;
    return (high - low);
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    // std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
    // std::cout << fib_partial_sum(from, to) << '\n';
}
