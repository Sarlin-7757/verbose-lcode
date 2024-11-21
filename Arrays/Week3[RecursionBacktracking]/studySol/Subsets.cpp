void backtrack(int start, vector<int>&nums , vector<int>&ds , vector<vector<int>>&result){
    if(start >=nums.size()){
        result.push_back(ds):
        return;
    }

    ds.push_back(nums[start]);
    backtrack(start+1 , nums , ds ,result);
    ds.pop_back();
    backtrack(start+1 , nums, ds ,result);
}


vector<vector<int>>subsets(vector<int>&nums){
    vector<vector<int>>&result;
    vector<int>&ds;

    backtrack(0 , nums, ds , result);
    return result;
}



