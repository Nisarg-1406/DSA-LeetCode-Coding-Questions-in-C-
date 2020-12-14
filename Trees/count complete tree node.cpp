    //Optimized solution to calculate the number of nodes in left and right subtree
    
    int countNodes (TreeNode* root) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(0);
        if (root == nullptr) return 0;
        int left_levels = 1;
        TreeNode* l = root -> left;
        while (l) {
            l = l -> left;
            left_levels = left_levels + 1;
        }
        int right_levels = 1;
        TreeNode* r = root -> right;
        while (r) {
            r = r -> right;
            right_levels = right_levels + 1;
        }
        if (left_levels == right_levels) return pow (2, left_levels) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
