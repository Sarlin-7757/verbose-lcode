#include<algorithm>


int lowerBound(vector<int>nums , int target){
    int n = nums.size();
    int low = 0 , high = n-1;
    int ans = n;
    while(low <= high){
        int mid = (low + high)/2;

        if(nums[mid] >= target){
            ans = mid;
            high = mid-1;
        }

        else{
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(vector<int>nums , int target){
    int n = nums.size();
    int low = n , high = n-1;
    int ans = n;
    while(low <= high){
        int mid = (low + high)/2;

        if(nums[mid] >target){
            ans = mid;
            high = mid-1;
        }

        else{
            low = mid + 1;
        }
    }
    return ans;
}


lb = lower_bound(arr.begin() ,arr.end() , n) - arr.begin();
ub = upper_bound(arr.begin() , arr.end() , n) - arr.begin();