//---- C++ COPYRIGHT 2024 -------
//DFS PROGRAM BY SARANSH 
//------ --------- -------- ------ 

#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>

using namespace std;


void depthFirstSearch(unordered_map<char, vector<char>>graph , char source, unordered_set<char>&visited){
  cout << source << " ";
  
  visited.insert(source);

  for(char neighbor : graph[source]){
    if(visited.find(neighbor) == visited.end()){
      depthFirstSearch(graph, neighbor, visited);
    }
  }
}

int main(){ 

    unordered_map<char, vector<char>>graph;
    unordered_set<char> visited;
    
    graph['a'] = {'b', 'c'};
    graph['b'] = {'d'};
    graph['c'] = {'e'};
    graph['d'] = {'f'};
    graph['e'] = {};
    graph['f'] = {};

    depthFirstSearch(graph, 'a', visited);
}
