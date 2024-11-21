// leetcode problem 906 fruit into baskets

#include<iostream>
#include<limits.h>
#include<map>
#include<algorithm>


#include<set>

int fruitIntoBasket(int trees[], int size) {
    std::map<int, bool> treeTypeMap;
    int max = 0;
    int start = 0;

    for (int end = 0; end < size; end++) { 
        int treeType = trees[end]; // Extract the tree type

        if (treeTypeMap.size() < 2 && !treeTypeMap[treeType]) {
            treeTypeMap[treeType] = true;
            max = std::max(max, end - start + 1); 
        }
        else if (treeTypeMap[treeType]) {
            max = std::max(max, end - start + 1);
        }
        else {
            treeTypeMap.clear(); // Clear the map
            treeTypeMap[trees[end - 1]] = true;
            treeTypeMap[treeType] = true;
            start = end - 1;

            if (trees[start] == trees[start - 1]) {
                start--;
            }

            max = std::max(max, end - start + 1);
        }
    }
    return max; 
}

int main() {
    int trees[] = {0, 1, 6, 6,4 , 4 ,6};
    int size = sizeof(trees) / sizeof(trees[0]);
    int answer = fruitIntoBasket(trees, size);

    std::cout << answer;
    return 0;
}

