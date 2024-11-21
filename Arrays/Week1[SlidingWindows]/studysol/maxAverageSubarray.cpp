#include<limits.h>
#include<iostream>
#include<vector>


double findMaxAverage(std::vector<int>&nums , int k ){
    int windowSum = 0;
    int start = 0; 
    double maxavg = INT_MIN;
    double avg;


    for (int end = 0; end < nums.size() ; end++){
        windowSum += nums[end];

        if(end - start +1 == k ){
            avg = (static_cast<double>(windowSum)/k);
            maxavg = std::max(maxavg, avg);

            //  move to next window

            windowSum -= nums[start];
            start ++;
        }
    }
    return maxavg;
}


int main(){
    int k = 4; 
    std::vector<int>nums = {3 , -1 , 5 , 50 , 14 , 1};
    double answer; 
    answer = findMaxAverage(nums , k);
    std::cout << answer ;
}
