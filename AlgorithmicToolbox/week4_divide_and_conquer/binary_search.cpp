#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>


using namespace std;


uint __binary_search(const vector<int> &a, int e, uint l, uint r) {
  if (l > r)  
    return r;
  const uint mid = l + ((r - l) / 2);
  if (a[mid] == e) 
    return mid;
  if (e < a[mid])
    return __binary_search(a, e, l, mid - 1);
  return __binary_search(a, e, mid + 1, r);
}

int binary_search(vector<int> &a, int x) {
  uint left = 0, right = a.size(); 
  // sort(a.begin(), a.end());  
  uint index = __binary_search(a, x, left, right - 1);
  if (index < 0)  // x < a_i for all a_i
    return -1;
  if (a[index] != x)
    return -1; // index == |a| - 1, a_i < x for all a_i
  return index;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
