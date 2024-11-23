#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) {
            return true;
        }

        // Build the adjacency list from the edge list
        vector<vector<int>> adjList(n);
        for (const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        // Perform DFS using a stack
        vector<bool> visited(n, false);
        stack<int> st;
        st.push(source);
        visited[source] = true;

        while (!st.empty()) {
            int current = st.top();
            st.pop();

            // Explore neighbors
            for (int neighbor : adjList[current]) {
                if (neighbor == destination) {
                    return true;  // If destination is found
                }
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    st.push(neighbor);
                }
            }
        }

        return false;      }
};

int main() {
    Solution solution;
    
    // Number of nodes
    int n = 6;

    // Edges of the graph
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};

    int source = 0;
    int destination = 5;

    // Call the validPath function
    bool result = solution.validPath(n, edges, source, destination);

       if (result) {
        cout << "There is a valid path from " << source << " to " << destination << ".\n";
    } else {
        cout << "No valid path exists from " << source << " to " << destination << ".\n";
    }

    return 0;
}

