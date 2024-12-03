#include<iostream>
#include <unordered_map>
#include <unordered_set>
#include<vector>
#include<stack>

using std::vector;

void depthFirstSearch(std::unordered_map<int , vector<int>>&adjList , int source, std::unordered_set<int>&visited){
  std::stack<int> st;
  st.push(source);
  visited.insert(source);
  
  while(!st.empty()){
    int current = st.top();
    st.pop();
    
    if(adjList.find(current) == adjList.end())continue; // if current node has no neighbors then skip
    for(int neighbor : adjList[current]){
      if(visited.find(neighbor) == visited.end()){ 
        visited.insert(neighbor);
        st.push(neighbor);
      }
    }

  }
}



int findCircleNum(vector<vector<int>>isConnected){
  int n =  isConnected.size();
  std::unordered_map<int, vector<int>> adjList;
  for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
          if (isConnected[i][j] == 1 && i != j) {
              adjList[i].push_back(j);
          }
      }
  }
  
  std::unordered_set<int>visited;
  int countOfProvince = 0;

  for(int i = 0 ; i < n; ++i){ 
    if(visited.find(i) == visited.end()){
      depthFirstSearch(adjList , i, visited);
      countOfProvince++;
    }
  }
  return countOfProvince; 
}


int main(){
  vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
  };
   int result = findCircleNum(isConnected);
   
  std::cout << result;
}
