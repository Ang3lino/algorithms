#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

vector<int> get_period(int64_t n, int64_t m) {
    vector<int> period({0,1,1});
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
    auto period = get_period(n, m);
    n %= period.size();
    return period[n];  // 
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    // for (int i = 0; i < n; ++i)
    //     cout << fib_mod(i, m) << endl;
    cout << fib_mod(n, m);
    return 0;
}
