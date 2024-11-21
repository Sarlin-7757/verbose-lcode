
#include<vector>



int maxArea(std::vector<int>&height){
    int n = height.size();

    int i = 0;
    int j = n-1;


    int maxArea = 0; 

    while(i < j){
       int h = std::min(height[i], height[j]);

       int w = (j - i);

       int maxWater = (h * w);

       maxArea = std::max(maxArea , maxWater);

       if (height[i] < height[j]){
           i++ ;
       }
       else{
        j--;
       }
    }
    return maxArea;
}