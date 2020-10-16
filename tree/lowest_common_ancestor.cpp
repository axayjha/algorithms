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

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if (root == NULL) {
           return NULL;
       } 
       if (root->val == p->val || root->val == q->val) {
           return root;
       }
       TreeNode* left = lowestCommonAncestor(root->left, p, q);
       TreeNode* right = lowestCommonAncestor(root->right, p, q); 

       if (left and right) {
           return root;
       } else if (left) {
           return left;
       } else {
           return right;
       }

    }
};