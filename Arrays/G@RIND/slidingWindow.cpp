// leetcode problem 263: Maximum Average Subarray


#include<iostream>
#include<limits.h>
#include<algorithm>


float func(int nums[], int size , int k){
    int windowSum = 0;
    int start = 0; 
    float max = INT_MIN;

    for (int end  = 0 ; end < size ; end++){
        windowSum += nums[end];

        if ((end - start + 1) == k ){
            // calculate average
            max = std::max(max , float(windowSum)/float(k));
            windowSum -= nums[start];
            start +=1;
        }
    }
    return max;

}

int main(){

    int k = 4; 
    int nums[] = {-1 , 12 , 0 , 33 ,4};

    int size = sizeof(nums)/sizeof(nums[0]);

    printf("maximum average subarray value is  %f",funcSlidingWindow(nums ,size ,k));
}
