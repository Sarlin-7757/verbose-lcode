#include <iostream>
#include<vector>

// int maxElement(std::vector<int>&windArr){
//     int max = windArr[0];
//     for (int i = 0 ; i < windArr.size(); i++){
//         if(windArr[i]  > max){
//             max = windArr[i];
//         }
//     }
//     return max;
// }

// ________________________NOT OPTIMAL SOLUTION GIVING TIME LIMIT EXCEEDED ERROR IN LEETCODE_________________________ TIME COMPLEXITY -> O(N*k)

int maxElement(std::vector<int>&windArr){
        int max = windArr[0];
        for (int i = 0 ; i < windArr.size(); i++){
            if(windArr[i]  > max){
                max = windArr[i];
            }
        }
        return max;
    }      

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    std::vector<int> maxWindowElements;
    
    int start = 0;
    std::vector<int> windArr; 
    
    for (int end = 0; end < nums.size(); ++end) {
        windArr.push_back(nums[end]);

        if (end - start + 1 == k) {
            int max = maxElement(windArr);
            maxWindowElements.push_back(max);

            // nums.erase(nums.begin());
            windArr.erase(windArr.begin()); 
            start++;
        }
    }
    return maxWindowElements;
}



int main() {

    // std::vector<int>windArr= {1 , 3 ,-1};
    
    // std::vector<int>nums = {1 ,2 , 3 , 4};
    
    // for (int i = 0 ; i < nums.size(); i++){
    //      windArr.push_back(nums[i]);
    // }
    
    // for (int j =0 ; j < windArr.size(); j++){
    //     std::cout << windArr[j];
    // }
    
    std::vector<int>nums = {1, 3, -1 , -3 , 5, 3 , 6 ,7};
    std::vector<int>ans;
    int k = 3;
    ans = maxSlidingWindow(nums , k);
    
    for(int i = 0 ; i < ans.size() ; i++){
        std::cout << ans[i];
    }
    // int ans = maxElement(windArr);
    // std::cout << ans;
}
