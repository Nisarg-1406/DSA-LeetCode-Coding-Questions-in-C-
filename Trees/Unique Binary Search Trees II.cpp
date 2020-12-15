    //Using Recursion forming the left and right array for left and right subtree. 
    vector<TreeNode*> helper(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(nullptr);
            return res;
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> lefts = helper(start, i - 1);
            vector<TreeNode*> rights = helper(i + 1, end);
            for (int j = 0; j < lefts.size(); j++) {
                for (int k = 0; k < rights.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = lefts[j];
                    root->right = rights[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(n == 0) return vector<TreeNode*>(0);
        return helper(1,n);
    }
