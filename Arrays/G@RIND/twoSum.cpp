#include<iostream>
#include <unordered_map>
#include<vector>


std::vector<int>TwoSum(std::vector<int>nums, int target){
  int n = nums.size();

  std::unordered_map<int, int>hashmap;

  for(int i = 0 ; i < n; i++){
    int remainingTargetValue = target - nums[i];

    if(hashmap.find(remainingTargetValue) != hashmap.end()){
      return {hashmap[remainingTargetValue], i};
    }
    hashmap[nums[i]] = i;
  }
  return {};
}



int main(){
  std::vector<int>nums = {2 , 7 , 11 , 15};
  int target = 9;
  
  std::vector<int>output =  TwoSum(nums, target);
 
  std::cout<< output[0] << output[1];

  return 0;
}
