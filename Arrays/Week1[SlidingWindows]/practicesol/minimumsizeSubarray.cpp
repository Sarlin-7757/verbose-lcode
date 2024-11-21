#include<iostream>
#include<vector> 
#include<limits.h>


// target = 7 , nums = [2, 3 , 1, 2 , 4 ,3]

// target = 4 , nums = [1, 4 ,4]

int minSubArrayLen(int target, std::vector<int>& nums) {
    int s = nums.size();

    int start = 0; 
    int sum=0; 
    int minVal= 0; 

    for (int end = 0 ; end < s ; end ++){
        sum += nums[end];

        while(sum >=target){
            if (minVal == 0){
                minVal = end-start+1;
            }
            minVal = std::min(minVal , end - start+1);
            sum -= nums[start];
            start++;
        }
    }
    if (minVal == 0){
        return 0;
    }
    return minVal;
   
}