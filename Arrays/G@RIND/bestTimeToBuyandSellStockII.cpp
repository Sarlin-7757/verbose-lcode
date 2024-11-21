#include <algorithm>
#include<vector>
#include<iostream>

using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int buyprice = prices[0];   
      int profit = 0;
      int totalProfit = 0; 
      int maxProfit = 0;


      for(int i = 1 ; i < prices.size(); i++){
        if(prices[i] < buyprice){
          buyprice = prices[i];
        }
        else{
          profit = abs(buyprice - prices[i]); 
          // maxProfit = std::max(maxProfit , profit);
          totalProfit = totalProfit + profit;
         
          buyprice = prices[i];
        }
      }
      return totalProfit;
    }
};


int main(){
  Solution s;

  vector<int>prices = {7 , 1 ,5 ,3, 6, 4};

  std::cout<< s.maxProfit(prices);

}
