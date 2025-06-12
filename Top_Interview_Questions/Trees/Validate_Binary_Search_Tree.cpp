#include <limits.h>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validate(TreeNode* root, long minValue, long maxValue) {
        if (root->val > minValue && root->val < maxValue) {
            bool leftPassed = root->left ? validate(root->left, minValue, root->val) : true;
            bool rightPassed = root->right ? validate(root->right, root->val, maxValue) : true;
            return leftPassed && rightPassed;
        } else {
            return false;
        }
    }
};