    int deepestLeavesSum(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while(!q.empty()){
            int n = q.size();
            sum = 0; // re-initialize sum, if another level exists
            while(n--){
                TreeNode *node = q.front();q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(node->right == nullptr && node->left == nullptr) sum += node->val;
            }
        }
        return sum;
    }
