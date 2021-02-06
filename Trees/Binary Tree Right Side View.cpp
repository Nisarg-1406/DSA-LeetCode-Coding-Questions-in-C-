    // 2 Approaches - Using Queue and Recursion 
    // Using Queue - 
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode* > que;
        vector<int> res;
        if(!root)return res;
        que.push(root);
        while(!que.empty()){
            int len = que.size();
            res.push_back(que.front()->val);
            for(int i=1;i<=len;i++){
                TreeNode* temp = que.front(); 
                que.pop();
                if(temp->right != NULL) que.push(temp->right);
                if(temp->left != NULL) que.push(temp->left);
            }
        }
        return res;
    }
        
    // Using Recursion
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        rightViewBinaryTree(root, 1, res);
        return res;
    }
    void rightViewBinaryTree(TreeNode *root, int level, vector<int> &res){
        if(root==NULL) return;
        if(res.size()<level) res.push_back(root->val);
        //rightViewBinaryTree(root->left,level+1,res);
        rightViewBinaryTree(root->right,level+1,res);
        rightViewBinaryTree(root->left,level+1,res);
    }
