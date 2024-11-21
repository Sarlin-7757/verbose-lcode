

vector<int>findLeftMax(vector<int>&height , int n ){
    vector<int>leftMax(n);

    leftMax[0] = height[0];

    for (int i = 1 ; i <= n; i++){
        leftMax = max(leftMax[i-1] , height[i]);
    }
    return leftMax;
}

vector<int>findRightMax(vector<int>&height , int n){
    vector<int>rightMax(n);

    rightMax[n-1] = heigth[n-1];

    for (int j = n-2 ; j>=0; j--){
        rightMax = max(rightMax[j+1] , height[j]);
    }
    return rightMax;
}


int trap (vector<int> &height){
    int n = height.size();


    vector<int>leftMax = findLeftMax(height , n);
    vector<int>rightMax = findRightMax(height , n);


    int sum = 0; 

    for (int i = 0 ; i < n ; i ++){

        int h = min(leftMax[i] , rightMax[i]) - height[i];
        int sum += h;
    }
    return sum;
}