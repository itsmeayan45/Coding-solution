#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<int> findCandidates(const std::vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return {};

    int threshold = n / 3;
    std::unordered_map<int, int> countMap;

    // Count occurrences of each candidate
    for (int candidate : arr) {
        countMap[candidate]++;
    }

    // Collect candidates that have more than n/3 votes
    std::vector<int> result;
    for (const auto& entry : countMap) {
        if (entry.second > threshold) {
            result.push_back(entry.first);
        }
    }

    // Sort the result array
    std::sort(result.begin(), result.end());
    
    return result;
}

int main() {
    std::vector<int> arr = {2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6};
    std::vector<int> output = findCandidates(arr);

    std::cout << "[";
    for (size_t i = 0; i < output.size(); ++i) {
        std::cout << output[i];
        if (i < output.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}