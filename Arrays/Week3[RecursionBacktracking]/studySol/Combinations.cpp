
void combinations(int start , int n , int  k , vector<int>&ds , vector<vector<int>>&result){
    if(k==0){
        result.push_back(ds);
        return;
    }


    if(start >n){
        return;
    }


    ds.push_back(start);
    combinations(start+1 , n , k-1 , ds ,result);

    ds.pop_back();
    combinations(start+1, n , k , ds , result);

    /* another method can be 

    just use the for loop instaed of two recursive calls */


    for (int i = start ; i <= n ; i ++){
       
    ds.push_back(i);
    combinations(i+1 , n , k-1 , ds ,result);

    ds.pop_back(); 
    }

}



vector<vector<int>>combine(int n , int k){
    vector<vector<int>>result;
    vector<int>ds;

    combinations(1 , n , k , ds ,result);
    return result;
}