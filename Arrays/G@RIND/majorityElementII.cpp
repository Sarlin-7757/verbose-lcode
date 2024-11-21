//include<iostream>
#include<vector> 
#include<unordered_map>
using namespace std;


 vector<int> majorityElement(vector<int>& nums) {
   std::unordered_map<int , int> mpp;
   int n = nums.size();
   std::vector<int>ans;
  

   // We have inititalized the mpa with the nums value
    for(int i = 0; i < nums.size() ; i++ ){
      mpp[nums[i]]=0;
    }
    
    for(int i = 0 ; i < nums.size(); i++){
      mpp[nums[i]]++;

      if(nums[i] > n/3){
        ans.push_back(nums[i]);
        return ans;
      } 
    }
    return nums;
 }

