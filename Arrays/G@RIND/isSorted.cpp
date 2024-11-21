#include <vector>
#include <iostream>
#include <algorithm>

bool isRotatedSorted(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> doubled_arr(arr.begin(), arr.end());
    doubled_arr.insert(doubled_arr.end(), arr.begin(), arr.end());

    for (int i = 0; i < n; ++i) {
        bool sorted = true;
        for (int j = 0; j < n - 1; ++j) {
            if (doubled_arr[i + j] > doubled_arr[i + j + 1]) {
                sorted = false;
                break;
            }
        }
        if (sorted) {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<int> arr = {3, 4, 5, 1, 2};
    if (isRotatedSorted(arr)) {
        std::cout << "The array is a rotated sorted array.\n";
    } else {
        std::cout << "The array is not a rotated sorted array.\n";
    }
    return 0;
}

// 3 - 4 - 5 - 1 - 2 + 3 - 4 - 5 - 1 - 2


