#include <cstring>
#include<iostream> 
#include<vector>

//Memoization -> Top Down Approach

int fibTop_down(int n){
  if(n<=1)return n;
  std::vector<int>dp(n+1, -1);

  if(dp[n] != -1)return dp[n];
  return dp[n] = fibTop_down(n-1)+ fibTop_down(n-2);
}


//Tablulation -> Bottom UP Approach
// bottom up approach

// for the local solution this solutin may work
// but for the leetcode solution we need to handle 
// the condition for the 0th index because this 
// solution is giving the addresssanittizer error 
// that means accesing the unknown location. 


int fib(int n){
  if(n <=1)return n; 

  std::vector<int>dp(n+1);
  dp[0]= 0;
  dp[1] = 1;

  for(int i = 2 ; i <= n ; i++){
    dp[i] = dp[i-1] + dp[i-2];
  }
  return dp[n];
}
int main(){
    int ans = fib(10000);
    std:: cout<< ans << "\n"; 
}


// For the space complexity to be O(1) 
// we should not use extra vector space 
int fibConstantTime(int n){
  if(n <=1)return n; 

  int prev2= 0;
  int prev1 = 1;

  for(int i = 2 ; i <= n ; i++){
    int  curr = prev1 + prev2;
    prev2 = prev1;
    prev1 = curr;
  }
  return prev1;
}


