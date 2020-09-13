#include <iostream>

int64_t gcd_naive(int64_t a, int64_t b) {
  int64_t current_gcd = 1;
  for (int64_t d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int64_t __gcd(int64_t a, int64_t b) {
  // a > b
  if (b == 0) return a;
  return __gcd(b, a % b);
}

inline int64_t gcd(int64_t a, int64_t b) {
  return __gcd(std::max(a, b), std::min(a, b));
}

inline int64_t lcm(int64_t a, int64_t b) {
  return a*b / gcd(a, b);
}

int main() {
  int64_t a, b;
  std::cin >> a >> b;
  // std::cout << gcd_naive(a, b) << std::endl;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
