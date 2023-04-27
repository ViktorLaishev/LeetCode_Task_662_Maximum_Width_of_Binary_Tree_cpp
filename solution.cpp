class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});
        int maxWidth = 0;
        while (!q.empty()) {
            unsigned long long leftPos = q.front().second, rightPos = leftPos;
            int levelSize = q.size(); 
            for (int i = 0; i < levelSize; i++) {
                auto [node, pos] = q.front();
                q.pop();
                rightPos = pos;
                if (node->left) q.push({node->left, 2*pos});
                if (node->right) q.push({node->right, 2*pos+1});
            }
            maxWidth = max(maxWidth, (int)(rightPos - leftPos + 1));
        }
        return maxWidth;
    }
};
