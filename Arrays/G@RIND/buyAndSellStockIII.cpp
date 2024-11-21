#include<iostream>
#include<vector>

using std::vector;
using std::cout; 



---------------------- NOT SOLVED YET -------------------------------------
class Solution {
public:
      int maxProfitGained(vector<int>&profits){
        int n = profits.size(); 
        if(n < 2)return 0;
        int start = 0 ; 

        int maxSumOfProfits = 0; 

        for(int i = 1 ; i < n ; i++){
          int sumOfProfits = profits[i] + profits[i-1];
          maxSumOfProfits = std::max(maxSumOfProfits , sumOfProfits);
        } 
        return maxSumOfProfits;
      }
      
      int maxProfit(vector<int>& prices) {
        int buyprice = prices[0];   
        int profit = 0;
        int totalProfit = 0; 
        vector<int>profits;

        for(int i = 1; i < prices.size(); i++){
          if(prices[i] <= buyprice){
            buyprice = prices[i];
          }
          else{
            profit = abs(buyprice - prices[i]);
            profits.push_back(profit);
            buyprice = prices[i];
        
          }
        }

        return maxProfitGained(profits);
     // for(int i = 0 ; i < profits.size(); i++){
     //   cout << profits[i] << " ";
     // }
     // cout << std::endl; 
     
    }
    
};


int main(){
  Solution s;
  
  //vector<int>prices = {3, 3, 5,0 , 0 , 3 ,1 , 4};
  vector<int>prices = {1, 2, 3 , 4 ,5};

  cout << s.maxProfit(prices);
}
