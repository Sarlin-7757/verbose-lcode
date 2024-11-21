//  two pointer approach  O(n)

 vector<int> sortedSquares(vector<int>& nums){
    int n = nums.size();

    
    int i = 0 ;
    int j = n-1;

    int k = n-1; //result me dalne ke liye 

    vector<int>sqauredArr(nums);

    for(k = n-1; k>=0 ; k--){

        int x = (nums[i]*nums[i]);
        int y = (nums[j] * nums[j]);

        if(x > y){
            sqauredArr[k]= x;
            i++;
        }
        else{
            sqauredArr[k] = y;
            j--;
        }
    }
    return sqauredArr;
}



// O(nlogn)

vector<int> sortedSquares(vector<int>& nums) {
   int n = nums.size();

   
    vector<int> newarr;

   for(int i = 0 ; i < n ; i++){
        
        int p = nums[i] * nums[j];
        newarr.push_back(p);
   }

   return sort(newarr.begin() , newarr.end());

}


// O(nlogn )

// 2. same solution with less steps  SAME TIME COMPLEXITY THOUGH

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();

    vector<int> squaredArr(n);
    for (int i = 0; i < n; i++) {
        squaredArr[i] = nums[i] * nums[i];
    }

    sort(squaredArr.begin(), squaredArr.end());

    return squaredArr;
}



