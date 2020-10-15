#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution{
public:    
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        stack<TreeNode *> st;
        TreeNode* prev = NULL;
        TreeNode* current = root;
        while (true) {
            if (current) {
                st.push(current);
                current = current->left;
            } 
            else if (!st.empty()) {
                current = st.top();
                st.pop();
                if (prev and current and prev->val >= current->val)
                    return false;
                prev = current;    
                current = current->right;
            } else break;
        }
        return true;
    }
};