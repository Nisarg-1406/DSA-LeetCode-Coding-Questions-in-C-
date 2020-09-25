//Using Memoization
    unordered_map<TreeNode*, int> mp;
    int rob(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(mp.count(root)) return mp[root];
        if(root == NULL) return 0;
        int val = 0;
        if(root->left){
            val = val + rob(root->left->left)+ rob(root->left->right);
        }
        if(root->right){
            val = val + rob(root->right->left) + rob(root->right->right);
        }
        mp[root] = max(val + root->val, rob(root->left) + rob(root->right));
        return mp[root];
    }
    
 //Using DP - 
    int rob(TreeNode* root) {
        vector<int> res = robSub(root);
        return max(res[0], res[1]);
    }
    vector<int> robSub(TreeNode* root){
        if (root == NULL) return vector<int>(2,0);
        vector<int> left = robSub(root->left);
        vector<int> right = robSub(root->right);
        vector<int> res(2,0);
        res[0] = max(left[0],left[1]) + max(right[0],right[1]);
        //res[0] = left[1] + right[1];
        res[1] = root->val + left[0] + right[0];
        return res;
    }
