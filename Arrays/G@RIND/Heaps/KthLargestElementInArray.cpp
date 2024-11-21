#include<iostream>
#include<vector>
#include<queue>


using std::cout; 
using std::vector;
using std::greater;



class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      std::priority_queue<int , vector<int> , greater<int>>pq;
        for(int i = 0 ; i < nums.size(); i++){
          pq.push(nums[i]);
          if(pq.size()>k){
            pq.pop();
          }
        }
        return pq.top();
    }
};


int main(){
  Solution s;

  vector<int> nums = {3 ,2};
  std:cout << s.findKthLargest(nums, 2);
}
