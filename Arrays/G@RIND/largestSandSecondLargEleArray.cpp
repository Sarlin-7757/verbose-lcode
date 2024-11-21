#include<vector>
#include<iostream>
#include<limits.h>

class Solution{
  public:
   int largestElementInTheArray(std::vector<int>&nums){
     int largeEle = INT_MIN;
     for(int i = 0 ; i < nums.size() ; i++){
       if(nums[i] > largeEle){
         largeEle = nums[i];
       }
     }
     return largeEle;
   }
   
  int secondLargestElementInTheArray(std::vector<int>&nums){
    int secondLargeEle = INT_MIN;  
    int largeEle = nums[0];

    for(int i = 1 ; i < nums.size(); i++ ){
      if(nums[i] > largeEle ){
        secondLargeEle = largeEle;
        largeEle = nums[i];
      }
      else if(nums[i] < largeEle && nums[i] > secondLargeEle){
        secondLargeEle = nums[i];
      }
    }
    return secondLargeEle;
  }
};


int main(){
  Solution s;
  std::vector<int>nums = {10 , 20 , 53 , 34};
  std::cout<< s.largestElementInTheArray(nums)<< "\n";
  std::cout<< s.secondLargestElementInTheArray(nums);
  return 0;
}
