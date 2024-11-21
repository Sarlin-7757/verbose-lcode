#include<vector>


//This doesn't work for the large inputs as the Time Complexity of the logic is O(n*2)

    int reversePairs(std::vector<int>& nums) {
         int count = 0;
         for(int i = 0 ; i < nums.size(); i++){
             for(int j = i+1 ; j< nums.size(); j++){
                 if(nums[i]> (2*(nums[j]))){
                     count++;
                 }
             }
        }
        return count;
    }

//______________________________________________________________________


class Solution {
public:
    int merge(std::vector<int> &arr, int low, int mid, int high) {
      std::vector<int> temp; // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr

        // Count and merge the two halves in sorted order
        int count = 0;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // If elements on the left half are still left
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // If elements on the right half are still left
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // Transferring all elements from temporary to arr
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
        return count;
    }

    int countPairs(std::vector<int>& nums, int low, int mid, int high) {
        int right = mid + 1;
        int count = 0;
        for (int i = low; i <= mid; i++) { // loop condition fix
            while (right <= high && nums[i] > 2LL * nums[right]) {
                right++;
            }
            count += (right - (mid + 1));
        }
        return count;
    }

    int mergeSort(std::vector<int> &nums, int low, int high) {
        int count = 0;
        if (low >= high) return count;
        int mid = (low + high) / 2;
        count += mergeSort(nums, low, mid);      // left half
        count += mergeSort(nums, mid + 1, high); // right half
        count += countPairs(nums, low, mid, high); // count reverse pairs
        count += merge(nums, low, mid, high);    // merging sorted halves
        return count;
    }

    int reversePairs(std::vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};




