#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std; 


    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mmap;
        int n = nums.size();

        for(int i = 0 ; i < n; i++){
            mmap[nums[i]] = 0;
        }

        if(n < k)return 0;

        long long maxWindowSum = 0;
        long long maxSubarrayResult = LLONG_MIN;
        int start = 0;
        for(int end = 0 ; end < n ; end++){
            mmap[nums[end]]++;
            maxWindowSum += nums[end];

            while(end -start + 1 > k || mmap[nums[end]] > 1){
                mmap[nums[start]]--;
                maxWindowSum -= nums[start];
                start++;
            }

            if(end- start + 1 == k){
                maxSubarrayResult = std::max(maxSubarrayResult , maxWindowSum);
            }
                
        }
        
        return maxSubarrayResult == LLONG_MIN ? 0 : maxSubarrayResult;
    }
