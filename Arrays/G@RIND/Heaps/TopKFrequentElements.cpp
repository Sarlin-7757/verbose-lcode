#include <algorithm>
#include <functional>
#include <queue>
#include <unordered_map>
#include <utility>
#include<vector>

using std::pair;
using std::vector;

vector<int> topKFrequent(vector<int>& nums, int k) {

  std::unordered_map<int, int>map;
   for(int i = 0 ; i < nums.size() ; i++){
      map[nums[i]]++;
    }
    vector<pair<int, int>>ans;

    for(const auto& [key , value]: map){
      ans.push_back({value , key});
    }

    std::sort(ans.rbegin() , ans.rend());
    vector<int> result;

    for(int i = 0 ; i < k ; i++){
      result.push_back(ans[i].second);
    }
    return result;
}

    // First Approach  using Heap
    typedef pair<int , int> p ;
    vector<int>topKFrequentII(vector<int>&nums , int k ){
  
      // 1. map
      std::unordered_map<int , int> map;

      for(auto &num : nums){
        map[num]++;
      }
       
      //2. define a min-heap
      std::priority_queue<p , vector<p> , std::greater<p>> pq;// min-heap
      
      //3.  push element in min-heap 
      // maintain size of k only

      for(auto& [key , value] : map){
         pq.push({value , key});

         if(pq.size() > k){
           pq.pop();
         }
      }
      //4. push to result 
      vector<int>result;
      while(!pq.empty()){     
        result.push_back(pq.top().second);
        pq.pop();
      }
      return result;
    }

// Approach III using bucket sort


vector<int>topKFrequentIII(vector<int> &nums , int k ){
  int n = nums.size();
  std::unordered_map<int, int>map;
  for(auto &num : nums){
    map[num]++;
  }

  vector<vector<int>>bucket(n+1);
  //index = freq
  //value = elements
  //bucket[i] = element having i frequency

  for(auto& [element , freq]: map){
    bucket[freq].push_back(element);
  }

  // pick element from right to left from bucket to find max frequency element
  // as the freq is stored in arrays so right side will have the maximum frequency.
  vector<int>result; 
  for(int i= n ; i>=0; i--){
    if(bucket[i].size()== 0)
      continue;
    while(bucket[i].size() > 0 && k > 0){
      result.push_back(bucket[i].back());
      bucket[i].pop_back();
      k--;
    }
  }
  return result;
}



