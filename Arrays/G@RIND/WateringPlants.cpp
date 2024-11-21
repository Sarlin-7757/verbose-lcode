#include<iostream>
#include<vector>

class Solution {
public:
    int wateringPlants(std::vector<int>& plants, int capacity) {
        int steps = 0;
        int gc = capacity;
        for(int i= 0; i < plants.size() ; i++){
            if(capacity < plants[i]){
                steps = steps +  (2*(i )+ 1);
                capacity = gc;
                capacity = capacity - plants[i];
            }else{
                capacity = capacity - plants[i];
                steps++;
            }
        }
        return steps;
    }
};
