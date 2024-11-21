#include<iostream>
#include<vector>


class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
      int n = nums.size();

      int count = 0;

      for(int i = 1 ; i < n ; i++){
        if(nums[i] != nums[count]){
          count++;
          nums[count]= nums[i];
        }
      }

       return count+1;

    }
};


int main(){
 std::vector<int>nums =   {0, 0 , 1, 1, 1 , 2 ,2 , 3 ,3 , 4};
//  std::vector<int>nums =   {1 , 1, 2};
//  std::unordered_map<int,int>newmap;
//
//  for(int i = 0 ; i < nums.size(); i++){
//    newmap[nums[i]]++;
//  }
//  
//
//  for(auto [key , value] : newmap){
//    std::cout << key  << "-> " << value << "\n";
//  }
//

  Solution s;
  std::cout << s.removeDuplicates(nums);


}



//0 -> 2
//1 -> 3
//2 -> 2
//3 -> 2
//4 -> 1
