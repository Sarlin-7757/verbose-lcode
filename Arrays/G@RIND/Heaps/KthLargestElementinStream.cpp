#include <functional>
#include <queue>
#include<vector>
using std::vector;

class KthLargest {
public:
    int K;  
    std::priority_queue<int, vector<int> , std::greater<int>> pq;


    KthLargest(int k, vector<int>& nums) {
      K=k;
          for(int &num : nums){
        pq.push(num);
      
        if(pq.size() > k)
          pq.pop();
     }
   }
    
    int add(int val) {
       pq.push(val);

       if(pq.size() > K){
         pq.pop();
       }
       return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
