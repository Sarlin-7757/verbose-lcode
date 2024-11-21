#include <cwchar>
#include<vector>

using std::vector;


class Solution {
public:
    void findSubsets(int index , vector<int>&nums , vector<vector<int>>&ans, vector<int>&ds){

        if(index == nums.size()){
            ans.push_back(ds);
            return;
        }
        
        ds.push_back(nums[index]);
        findSubsets(index+1 , nums, ans , ds);
        ds.pop_back();
        findSubsets(index+1 , nums , ans ,ds);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;

        findSubsets(0,nums , ans , ds);
        return ans;
    }
};
