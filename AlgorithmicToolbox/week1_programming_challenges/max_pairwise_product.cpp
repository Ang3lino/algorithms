#include <iostream>
#include <vector>
#include <algorithm>


int64_t MaxPairwiseProduct(std::vector<int64_t>& numbers) {
    int n = numbers.size();
    std::sort(numbers.begin(), numbers.end());
    return numbers[n-1] * numbers[n-2];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int64_t> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
