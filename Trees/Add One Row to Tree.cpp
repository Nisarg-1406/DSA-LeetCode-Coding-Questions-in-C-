    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        // Expanded version 
        if(d == 1){
            TreeNode* newroot = new TreeNode(v);
            newroot->left = root;
            return newroot;
        }
        else if(d == 0) {
            TreeNode* newroot = new TreeNode(v);
            newroot->right = root;
            return newroot;
        }
        if(!root) return NULL;
        else if (d == 2) {
            root->left  = addOneRow(root->left,  v, 1);
            root->right = addOneRow(root->right, v, 0);
            return root;
        }
        else if (d > 2) {
            root->left  = addOneRow(root->left,  v, d - 1);
            root->right = addOneRow(root->right, v, d - 1);
        }
        return root;
        
        // Compact Verison - 
        if (d == 0 || d == 1) {
            TreeNode* newroot = new TreeNode(v);
            (d ? newroot->left : newroot->right) = root;
            return newroot;
        }
        if (root && d >= 2) {
            root->left  = addOneRow(root->left,  v, d > 2 ? d - 1 : 1);
            root->right = addOneRow(root->right, v, d > 2 ? d - 1 : 0);
        }
        return root;
    }
