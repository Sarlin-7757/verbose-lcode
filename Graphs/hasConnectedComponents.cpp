#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<vector>
using std::vector;
using std::stack;
using std::unordered_map;
using std::unordered_set;



class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
      unordered_map<int , vector<int>>adjlist;
      for(const auto &edge : edges){
        adjlist[edge[0]].push_back(edge[1]);
        adjlist[edge[1]].push_back(edge[0]);
      }

      int countOfComponents = 0;
       
      unordered_set<int>visited;
      stack<int>st;
      
      
      for(int i = 0 ; i < n; i++){
        if(visited.find(i) == visited.end()){
          st.push(i);
          visited.insert(i);
          
          bool isComplete = true;
          unordered_set<int>componentNodes;

          while(!st.empty()){
            int current = st.top();
            st.pop();
            componentNodes.insert(current);

            for(int neighbor : adjlist[current]){
              if(visited.find(neighbor) == visited.end()){
                visited.insert(neighbor);
                st.push(neighbor); 
              }
            }
          }
          int size = componentNodes.size();
          for(int node : componentNodes){
            if(adjlist[node].size() != size-1){
              isComplete = false;
              break;
            }
          }

          if(isComplete){
            ++countOfComponents;
          }
        }
      }
       return countOfComponents;
    }
};


int main (){
  Solution s;
  
  int n = 6;
  vector<vector<int>>edges = [[0,1],[0,2],[1,2],[3,4],[3,5]] ;
  s.countCompleteComponents(n ,edges);
}
