#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int buyprice = prices[0];
      int profit = 0;
      int totalProfit = 0; 

      for(int i = 0 ; i < prices.size(); i++){
        if(prices[i] < buyprice){
          buyprice = prices[i];
        }
        else{
          profit = abs(buyprice - prices[i]);
          totalProfit = std::max(totalProfit , profit);
        }
      }
      return totalProfit;
    }
}; 


int main(){
  Solution s;
  vector<int> prices = {7 , 1 , 5 , 3 ,6, 4};

  std::cout << s.maxProfit(prices);
  
}
