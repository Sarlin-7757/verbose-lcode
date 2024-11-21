#include<vector>
#include<unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int , int> map;
        for(int i = 0 ; i < nums.size(); i++){
            map[nums[i]]++;
        }
        int ans;
        for(auto &[key , value]: map){
            if(value >= 2){
                ans = key;
            }
        }
        return ans;
    }
};
