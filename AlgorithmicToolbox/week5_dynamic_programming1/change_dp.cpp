#include <bits/stdc++.h>

using namespace std;

int get_change(uint m) {
  uint dp[m + 1];
  uint coins[] = {1, 3, 4};
  for (auto &c: coins) {
    dp[c] = 1;
  }
  dp[0] = 0;
  dp[2] = 2;
  for (uint i = 5; i <= m; ++i) {
    dp[i] = min(min(dp[i - coins[0]], dp[i - coins[1]]), dp[i - coins[2]]) + 1;
  }
  return dp[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
