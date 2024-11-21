class Solution {
public:
   int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        long long psum[n+1];

        psum[0] = 0;
        for(int i = 0 ; i < n ; i++){
            psum[i+1] = psum[i] + nums[i];
        }

        vector<int> smallerOnLeft = NSEL(nums);
        vector<int> smallerOnRight = NSER(nums);

        long long maxVal = INT_MIN;
        for(int i = 0; i < n; i++){
            int minVal = nums[i];
            int lr = smallerOnLeft[i];
            int rr = smallerOnRight[i];

            long long sum = psum[rr] - psum[lr+1];
            long long minProduct = minVal * sum;
            maxVal = max(minProduct , maxVal);
        } 
        return (int)(maxVal % 1000000007);
    }

    vector<int> NSEL(vector<int>&nums){
        stack<int> st;

        vector<int> res(nums.size());int  maxSumMinProduct(vector<int &nums){

}
            if(st.empty()){
                res[i] = -1;
            }
            else{
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }

    vector<int> NSER(vector<int>&nums){
        stack<int> st;

        vector<int> res(nums.size());

        for(int i = nums.size()-1 ; i>=0 ; i-- ){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(st.empty()){
                res[i] = nums.size();
            }
            else{
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }
};