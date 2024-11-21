#include<iostream>
#include<vector>

using namespace std;

void printArray(vector<int>arr , int n){
  for(int i = 0 ; i < n ; i++){
    cout<< arr[i]<<" ";
  }
}

void reverseFunction(vector<int>arr, int n){
  int first = 0; int last = n-1;
  while(first < last){
    swap(arr[first], arr[last]);
    first++; last++;
  } 
  printArray(arr, n);
}

/* the main function is this only , the above functions are just for implementation and 
later purpose */

void rotate(vector<vector<int>>& matrix) {

  int n = matrix.size();

  for(int i = 0 ; i < n-1 ; i++){
    for(int j = i+1; j<n; j++){
      swap(matrix[i][j] , matrix[j][i]);
    }
  }
  



  for(int i = 0 ; i < n ; i++){
    reverse(matrix[i].begin() , matrix[i].end());
  }
}
