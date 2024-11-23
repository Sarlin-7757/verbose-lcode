#include<iostream>
#include<unordered_set>
#include<vector>

bool containsDuplicate(std::vector<int>&nums){
  std::unordered_set<int>hashset;
  for(int num : nums){
    if(hashset.find(num) != 0){
      return true;
    }else{
      hashset.insert(num);
    }
  }
  return false;
}

int main(){
  std::vector<int>nums = {2 , 1 , 3 } ;
  std::cout << containsDuplicate(nums);
}
