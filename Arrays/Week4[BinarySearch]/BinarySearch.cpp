
#include<vector>


int BinarySearch(std::vector<int>&nums , int target){
    int n = nums.size();
    int low=0; 
    int high = n-1;

    while(low <=high){
        int mid = (low +high)/2;

        if (nums[mids] == target)return mid;
        else if(target > nums[mid]) low = mid +1;
        else high = mid -1;
    }

    return -1;
}


// Recursive Implementation


 int recSearch(vector<int>&nums , int low , int high , int target){
        if(low > high){
            return -1;
        }

        int mid = (low + high)/2;
        if(nums[mid]== target) return mid;

        else if (target > nums[mid]) return recSearch(nums , mid+1 , high , target);
        return recSearch(nums , low , mid -1 , target);
    }


    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int high = n-1;
        int low = 0;

        return recSearch(nums , low , high , target);
    }