int n;


void backtrack(vector<int>&nums , int index , vector<int>&ds , vector<vector<int>>&result) {
    if(ds.size() >=2){  
            result.push_back(ds);
    }


    unordered_set<int>st;

    for(int i = index ; i < n ; i++){
        
        if((ds.empty() || nums[i] >= ds.back()) && (st.find(nums[i]) == st.end())){
            ds.push_back(nums[i]);
            backtrack(nums , i+1 , ds , result);
            ds.pop_back();

            st.insert(nums[i]);
        }
    }
}

vector<vector<int>>findSubsequences(vector<int>&nums){
    n = nums.size();
    vector<vector<int>>result;

    vector<int>ds;

    backtrack(nums, 0 , ds , result);
    return result;
}