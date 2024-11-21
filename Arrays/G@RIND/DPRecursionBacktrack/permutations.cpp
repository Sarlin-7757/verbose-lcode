#include<vector>
#include <unordered_map>
using std::vector;


class Solution {
public:

    void findPermutations(vector<int>&nums, vector<int>&ds , vector<vector<int>>&ans , std::unordered_map<int, int >&map){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i = 0 ; i < nums.size(); i++){
            if(!map[i]){
                ds.push_back(nums[i]);
                map[i] = 1;
                findPermutations(nums , ds, ans, map);
                map[i] = 0;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
      std::unordered_map<int, int>map;
        vector<vector<int>>ans; 
        vector<int>ds; 

        for(int &num : nums){
            map[num] = 0;
        }
        findPermutations(nums , ds , ans , map);
        return ans;
    }
};
