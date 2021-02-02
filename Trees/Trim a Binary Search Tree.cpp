    // Iterative and Recursive Solution - 2 Approaches
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        // Recursive Solution    
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (!root) return root;
        if (root->val >= low && root->val <= high){
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;
        }
        if (root->val < low) return trimBST(root->right, low, high);
        return trimBST(root->left, low, high);
        
        // Iterative Solution
        while (root->val < low || root->val > high) {
            if(root->val < low) root = root->right; 
            else root = root->left; 
        }
        TreeNode *Ltemp = root;
        TreeNode *Rtemp = root;
        while (Ltemp->left) {
            if((Ltemp->left->val) < low) Ltemp->left = Ltemp->left->right; 
            else Ltemp = Ltemp->left; 
        }
        while (Rtemp->right) {
            if((Rtemp->right->val) > high) Rtemp->right = Rtemp->right->left; 
            else Rtemp = Rtemp->right; 
        }
        return root;
    }
