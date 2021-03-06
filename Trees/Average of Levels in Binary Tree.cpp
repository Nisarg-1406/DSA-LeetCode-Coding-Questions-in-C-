    vector<double> averageOfLevels(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        queue<TreeNode* > que;
        que.push(root);
        vector<double> levelres;
        while(!que.empty()){
            int nodeCount = que.size(); 
            double cnt = que.size();
            double res = 0;
            while(nodeCount>0){
                TreeNode* p = que.front();
                res = res + p->val;
                que.pop();
                if(p->left) que.push(p->left);
                if(p->right) que.push(p->right);
                nodeCount = nodeCount - 1;
            }
            levelres.push_back(res/cnt);
        }
        return levelres;
    }
