#include <iostream>
#include <vector>


using namespace std;


inline uint64_t gaussian_number(uint64_t n) { 
  return n * (n + 1) / 2; 
}

int largest_lte(uint64_t &target, int l, int r) {
  if (l > r) 
    return r;
  int mid = l + (r - l) / 2;
  uint64_t curr = gaussian_number(mid);
  if (curr == target) 
    return mid;
  if (target < curr)  // !!
    return largest_lte(target, l, mid - 1);
  return largest_lte(target, mid + 1, r);
}

void optimal_summands(uint64_t n) {
  int r = n;
  int k = largest_lte(n, 0, r);

  std::cout << k << '\n';
  for (int i = 1; i < k; ++i)
    std::cout << i << ' ';
  if (gaussian_number(k) == n)
    std::cout << k << ' ';
  else {
    std::cout << n - gaussian_number(k - 1) << ' ';
  }

}

int main() {
  uint64_t n;
  std::cin >> n;
  optimal_summands(n);
}
