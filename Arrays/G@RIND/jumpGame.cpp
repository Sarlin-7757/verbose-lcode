class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() ;
        if (n == 1)return true;
        int reach = 0;    
        for(int i = 0 ; i < n-1 ; i++ ){
            if(i > reach){
                return false;
            }
            reach = max(reach , i+nums[i]);
            if(reach >= n-1){
                return true;
            }
        }
        return false;
    }
};
