#include<vector>
#include<algorithm>

std::vector<std::vector<int>>result;

void twoSum(std::vector<int>&nums ,int target, int i , int j){
    while(i < j){
        if(nums[i] + nums[j] > target)
            return j--;
        else if (nums[i] + nums[j] < target)
            return i++;
        else{
            while(i<j && nums[i] == nums[i+1]) i++;
            while(i < j && nums[j] == nums[j-1]) j--;
            
            result.push_back({-target , nums[i] , nums[j]});
        }
    }
}

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    int n = nums.size();

    if (n < 3){
        return {};
    }

    sort(begin(nums) , end(nums));

    int n1 = nums[i];
    int target = -(n1);

    for(int i = 0 ; i < n-2; i++ ){
        if (i > 0 && nums[i] == nums[i-1]){
            continue;
        }

        twoSum(nums , target , i+1 , n-1);
    }
    return result;
}