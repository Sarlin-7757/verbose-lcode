vector<double> averageOfLevels(TreeNode* root) {
    vector<double>ans;

    queue<int>que;
    que.push(root);


    if(root == NULL){
        return ans;
    }

    while(!que.empty()){
        int n = que.size();
        if(n == 0-){
            return ans;
        }

        vector<int>data;
        while(n--){
            TreeNode* curr = que.front();
            que.pop();

            data.push_back(curr.val);
            if(curr->left != NULL) que.push(curr->left);
            if(curr->right != NULL)que.push(curr->right); 
        }
    }
}