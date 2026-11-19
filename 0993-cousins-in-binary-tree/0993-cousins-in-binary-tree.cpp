class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});

        while (!q.empty()) {
            int n = q.size();
            bool foundX = false, foundY = false;

            for (int i = 0; i < n; i++) {
                auto [node, parent] = q.front();
                q.pop();

                if (node->val == x) foundX = true;
                if (node->val == y) foundY = true;

                if (node->left) {
                    if (node->left->val == x && node->right &&
                        node->right->val == y)
                        return false;

                    q.push({node->left, node});
                }

                if (node->right) {
                    if (node->right->val == x && node->left &&
                        node->left->val == y)
                        return false;

                    q.push({node->right, node});
                }
            }

            if (foundX || foundY)
                return foundX && foundY;
        }

        return false;
    }
};