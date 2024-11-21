int numSubarrayProductLessThanK(vector<int>& nums, int k) {

    int n = nums.size();

    int start = 0;

    int count =0;

    int productVal = 1;

    for (int end = 0 ; end < n ; end++){
        productVal *= nums[end];

        while(product >= k){
            productVal /= nums[start];
            start++;
        }
        count += end -start +1;
    }

    return count;


}