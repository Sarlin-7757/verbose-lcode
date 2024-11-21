#include <cstring>
#include<vector>
#include<iostream>
#include<climits>

using std::vector;
using std::memset;

class Solution {
public:
  // Recursion and Memoization
  int dp[101]; 
  int solve(vector<int>&nums, int i , int n){
       
    if (i >= n){
     return 0;
    }
    if(dp[i] != -1)return dp[i];

    int steal = nums[i] + solve(nums ,i+2 , n);
    int skip = solve(nums , i+1 , n);

    return dp[i] = std::max(steal , skip);
  }
    
  int rob(vector<int>& nums) {
    int n = nums.size();
    memset(dp , -1 , sizeof(dp));
    return solve(nums , 0 , n);
  }

  // Bottom up approach
  
  int robBott(vector<int>&nums){
    int n = nums.size();

    if(n == 1)
      return nums[0];

    vector<int>dp(n+1 , 0);

    dp[0] = 0;
    dp[1] = nums[0];

    for(int i =2 ; i <= n ; i++){
      int steal = nums[i-1] + dp[i-2];
      int skip = dp[i-1];

      dp[i] = std::max(steal , skip);
    }
    return dp[n];
  }
};


int main(){
  Solution s; 

  vector<int>nums = {1 , 4 , 2, 1}; 
  int x  = s.rob(nums);

  std::cout<< x ;
}
