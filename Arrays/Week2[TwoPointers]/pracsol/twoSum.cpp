
// using hash tables (one pass method)


// Time complexity -> O(2n)  n -> building hashmap and n for searhing reamaing values 


vector<int> twoSum(vector<int>& nums, int target) {

    int n = nums.size();

    unordered_map<int>hashmap;

    for (int i = 0 ; i < n ; i++){
        int remainingTargetValue = target - nums[i];

        if(hashmap[remainngTargetValue] != hashmap.end()){
            return (hashmap[remainingTargetValue] , i);
        }
        // key to index
        hashmap[nums[i]] = i;
    }

    return {}; 
        
}



// two pointers method

// Time complexity -> O(nlogn)   nlogn sorting and n for travering through the sorted array using two pointers in linear time 


vector<int> twoSum(vector<int>& nums, int target) {
    
    vector<int> sortedNums(nums);
    sort(sortedNums.begin(), sortedNums.end());

    int n = sortedNums.size();
    vector<int> result;

    int i = 0;
    int j = n - 1; 

    while (i < j) {
        if (sortedNums[i] + sortedNums[j] > target) {
            j--;
        } else if (sortedNums[i] + sortedNums[j] < target) {
            i++;
        } else {
            // Find indices of the elements in the original array nums
            for (int k = 0; k < nums.size(); ++k) {
                if (nums[k] == sortedNums[i] || nums[k] == sortedNums[j]) {
                    result.push_back(k);
                }
            }
            return result;
        }
    }
    return {}; 
}

