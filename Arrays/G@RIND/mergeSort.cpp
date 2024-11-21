#include<vector>

using namespace std;

class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//
    
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        // right is smaller
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}



void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return; // Base condition

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);        // Sort the left half
    mergeSort(arr, mid + 1, high);   // Sort the right half
    merge(arr, low, mid, high);      // Merge the sorted halves
}

  vector<int> sortArray(vector<int>& nums) {
     int low = 0;
    int high = nums.size() - 1;

    mergeSort(nums, low, high);
    return nums;
    }
};
