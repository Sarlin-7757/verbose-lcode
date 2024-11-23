#include<iostream>
#include<queue>
#include <unordered_map>
#include<unordered_set>

using std::unordered_map;
using std::vector;
using std::queue;
using std::unordered_set;

void breadthFirstSearch(std::unordered_map<char,vector<char>>&graph , char source){
  queue<char>nodes;  
  unordered_set<char>visited;

  nodes.push(source);
  visited.insert(source);

  while(nodes.size() > 0){
    char current = nodes.front();
    std::cout << current << " ";
    nodes.pop();
    for(char neighbors : graph[current]){
      if(visited.find(neighbors) == visited.end()){
        nodes.push(neighbors);
        visited.insert(neighbors);
      }
    } 
  }
}


int main(){ 

  std::unordered_map<char, std::vector<char>>graph;
  /*std :: unordered_set<char> visited;*/
    
    graph['a'] = {'b', 'c'};
    graph['b'] = {'e'};
    graph['c'] = {'e'};
    graph['d'] = {'f'};
    graph['e'] = {};
    graph['f'] = {};

    breadthFirstSearch(graph, 'a');
}
