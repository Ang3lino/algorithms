#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>


using namespace std;


double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  priority_queue<pair<double, int>> value_per_weight;
  for (uint i = 0; i < weights.size(); ++i) {
    value_per_weight.push(make_pair((double) values[i] / weights[i], i));  // CAST double <- (double) int / int
  } 
  while (!value_per_weight.empty()) {
    auto vpw_i_pair = value_per_weight.top();   
    value_per_weight.pop();
    double vpw = vpw_i_pair.first;
    int i = vpw_i_pair.second;
    int max_weight_possible = min(capacity, weights[i]);
    capacity -= max_weight_possible;
    value += (max_weight_possible * vpw);
    if (capacity <= 0) break;
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  // std::cout.precision(4);
  std::cout << std::fixed;
  std::cout << std::setprecision(4);
  std::cout << optimal_value << std::endl;
  return 0;
}
