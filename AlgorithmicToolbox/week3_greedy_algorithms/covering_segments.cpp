#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <set>


using namespace std;
using ll_pair = pair<int64_t, int64_t>;
using p_indexes_segment = pair<set<int >, ll_pair >;


// assume p.first <= p.first
bool intersect(ll_pair &p, ll_pair &q, ll_pair &result) {
  int64_t a = p.first, b = p.second, c = q.first, d = q.second;
  // if (a > c) 
  //   swap(p, q);
  if (b < c) 
    return false;
  if (b <= d) 
    result = make_pair(c, b);
  else 
    result = make_pair(c, d);
  return true;
}

void print_groups( vector<pair<set<int >, ll_pair > > &groups) {
  for (auto &g: groups) {
    for (auto &i: g.first) 
      cout << i << " ";
    cout << ": ";
    auto &pair = g.second;
    cout << "[ " << pair.first << ", " << pair.second << " ]" << endl;
  }
}

void print_indexes_segment(set<int > &indexes, ll_pair &segment) {
    for (auto &i: indexes) 
      cout << i << " ";
    cout << ": ";
    cout << "[ " << segment.first << ", " << segment.second << " ]" << endl;
}

// custom comparator
auto comparator = [](p_indexes_segment a, p_indexes_segment b) {
  return a.first.size() < b.first.size();  // MaxHeap if a < b
};

priority_queue<p_indexes_segment, vector<p_indexes_segment>, decltype(comparator) > 
group_intersections(vector<ll_pair > &segments) {
  vector<pair<set<int >, ll_pair > > groups; // indexes, intersection pair involved
  const int n = segments.size();
  priority_queue<p_indexes_segment, vector<p_indexes_segment>, decltype(comparator) > 
      max_heap(comparator);
  for (int i = 0; i < n; ++i) {
    set<int> index = {i};
    max_heap.emplace(index, segments[i]);  // an intersection by itself
  }
  for (int i = 0, j, k; i < n - 1; ++i) {
    ll_pair intersection;
    for (k = i + 1; k < n; ++k) {
      j = k;  
      if (!intersect(segments[i], segments[j], intersection))
        break;
      set<int> indexes_involved = {i, j};
      while (++j < n && intersect(intersection, segments[j], intersection))
        indexes_involved.insert(j);
      max_heap.emplace(indexes_involved, intersection);
    }
  }
  return max_heap;
}

ll_pair update_intersection(vector<ll_pair > &segments, set<int > &indexes) {
  int n = indexes.size();
  auto it_i = indexes.begin();
  if (n == 1) 
    return segments[*it_i];
  ll_pair intersection;
  intersect(segments[*it_i], segments[*(++it_i)], intersection);
  while (++it_i != indexes.end()) {
    intersect(intersection, segments[*it_i], intersection);
  }
  return intersection;
}

vector<int> optimal_points(vector<ll_pair> &segments) {
  vector<int> points;
  sort(segments.begin(), segments.end());  // sort by first element from pair by default
  auto groups = group_intersections(segments);
  auto curr_e = groups.top(); groups.pop();
  set<int> indexes_used(curr_e.first);  // indexes already taked into account
  ll_pair curr_segment = curr_e.second;
  points.push_back(curr_segment.first);
  while (!groups.empty() && indexes_used.size() < segments.size()) {
    curr_e = groups.top(); groups.pop();
    set<int > curr_indexes = curr_e.first;
    curr_segment = curr_e.second;
    unsigned n = curr_indexes.size();
    set_difference(curr_indexes.begin(), curr_indexes.end(), 
        indexes_used.begin(), indexes_used.end(), 
        inserter(curr_indexes, curr_indexes.end()));
    if (curr_indexes.empty()) 
      continue;
    else if (curr_indexes.size() != n) { // changes made
      curr_segment = update_intersection(segments, curr_indexes);
      if (curr_indexes.size() < groups.top().first.size()) {  // it isn't the best solution now
        groups.emplace(curr_indexes, curr_segment); 
        continue;
      }
    } 
    points.push_back(curr_segment.first);
    indexes_used.insert(curr_indexes.begin(), curr_indexes.end());
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<ll_pair> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].first >> segments[i].second;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}

  // while (!q.empty()) {
  //   auto angel = q.top();
  //   q.pop();
  //   print_indexes_segment(angel.first, angel.second);
  // }
  // print_groups(groups);