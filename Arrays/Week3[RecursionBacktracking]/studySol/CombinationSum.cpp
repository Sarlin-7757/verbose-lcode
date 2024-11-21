
void trackCombination(int index , vector<int>&candidates , int target , vector<int>&ds , vector<vector<int>>&result){
    if(index == candidates.size()){
        if(target == 0){
            result.push_back(ds);
        }
    }
    if(candidates[index] <=target){
        ds.push_back(candidates[index]);
        trackCombination(index , candidates , target - candidates[i] , ds , result);
        ds.pop_back();
    }
    trackCombination(index+1 , candidates , target , ds , result);
}



vector<vector<int>>combinationSum(vector<int>&candidates, int target){
    vector<vector<int>>result;
    vector<int>ds;

    trackCombination(0 , candidates , target , ds , result);
    return result;
}