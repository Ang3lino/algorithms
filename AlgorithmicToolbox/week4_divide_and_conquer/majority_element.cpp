// #include <algorithm>
// #include <iostream>
// #include <vector>
// #include <stack>
// #include <set>

#include <bits/stdc++.h>


using namespace std;


pair<uint, set<int > > __gme(vector<int > &src, uint left, uint right) {
  if (left > right)
    return make_pair(0, set<int >());
  if (left == right)
    return make_pair(1, set<int > {src[left]});
  uint mid = left + ((right - left) / 2);
  auto left_pair = __gme(src, left, mid), right_pair = __gme(src, mid + 1, right);
  auto l_count = left_pair.first, r_count = right_pair.first;
  set<int > c ;
  auto a = left_pair.second, b = right_pair.second;
  set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
  if (c.size()) 
    return make_pair(l_count + r_count, c);
  if (l_count == r_count) {
    set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
    return make_pair(l_count, c);
  }
  if (l_count > r_count)
    return left_pair;
  return right_pair;
}

int get_majority_element(vector<int> &a) {
  uint n = a.size();
  auto result = __gme(a, 0, n - 1);
  uint count = result.first;
  // cout << count << endl;
  return count > n / 2;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << get_majority_element(a) << '\n';
}


// void merge(vector<int > &a, uint l, uint m, uint r) {
//   stack<int > left, right;
//   for (int i = l; i <= m; ++i) left.push(a[i]);
//   for (int i = m + 1; i <= r; ++i) right.push(a[i]);
//   uint k = 0;
//   while (!left.empty() && !right.empty()) {
//     if (left.top() <= right.top()) {
//       a[k++] = left.top(); left.pop();
//     } else {
//       a[k++] = right.top(); right.pop();
//     }
//   }
//   while (!left.empty()) {
//       a[k++] = left.top(); left.pop();
//   }
//   while (!right.empty()) {
//       a[k++] = right.top(); right.pop();
//   }
// }

// void msort(vector<int > &a, uint left, uint right) {
//   if (left > right)
//     return;
//   uint mid = left + ((right - left) >> 1);
//   msort(a, left, mid);
//   msort(a, mid + 1, right);
//   merge(a, left, mid, right);
// }

