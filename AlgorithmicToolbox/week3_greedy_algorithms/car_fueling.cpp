#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


template <class ForwardIterator, class T> 
ForwardIterator largest_less_than_or_equal_to(ForwardIterator first, 
        ForwardIterator last, const T& value)
{
  ForwardIterator upperb = upper_bound(first, last, value);

  // First element is >, so none are <=
  if (upperb == first)
    return upperb;

  // All elements are <=, so return the largest.
  if(upperb == last)
    return --upperb;

  return upperb - 1;
}

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int refills = 0;
    int dist_traveled = 0;
    for (auto begin = stops.begin(); begin != stops.end(); ++refills) {
        if (dist_traveled + tank >= dist) 
            return refills;
        auto best = largest_less_than_or_equal_to(begin, stops.end(), dist_traveled + tank);
        if (best == begin) 
            return -1; 
        dist_traveled = *best;
        begin = best;
    }
    return refills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
