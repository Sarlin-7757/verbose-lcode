/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<stack>

using namespace std;

bool hasValidPath(int n , vector<vector<int>>&edges , int source , int dest){
    if(source == dest)return true;
    
    unordered_map<int , vector<int>>adjlist;
    for(const auto &edge : edges){
        adjlist[edge[0]].push_back(edge[1]);
        adjlist[edge[1]].push_back(edge[0]);
    }
    
    unordered_set<int>visited;
    
    stack<int>st;
    st.push(source);
    visited.insert(source);
    
    while(st.size() > 0){
        int current = st.top();
        st.pop();
        
        for(int neighbor  : adjlist[current]){
            
            if(neighbor == dest){
                return true;
            }
            if(visited.find(neighbor) == visited.end()){
                visited.insert(neighbor);
                st.push(neighbor);
            }
        }
    }
    return false;
}


int main()
{
     // Number of nodes
    int n = 6;

    // Edges of the graph
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};

     int source = 0;
    int dest = 5;

    // Call the validPath function
    bool result = hasValidPath(n, edges, source, dest);

       if (result) {
        cout << "There is a valid path from " << source << " to " << dest << ".\n";
    } else {
        cout << "No valid path exists from " << source << " to " << dest << ".\n";
    }




    return 0;
}
