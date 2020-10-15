#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stdint.h>
#include <regex>
#include <sstream>
#include <locale>
#include <unordered_set>
#include <stack>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int maxLevel = 0;
    
    void maxDepthUtil(TreeNode* node, int level) {
        if (level > maxLevel) maxLevel = level;
        if (node == NULL) {
            return;
        }
        maxDepthUtil(node->left, level+1);
        maxDepthUtil(node->right, level+1);
    }
    
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        maxDepthUtil(root, 0);
        return maxLevel;
    }
};


class Solution1 {
public:
    int max(int i, int j) { return i > j ? i : j; }
    int maxDepthHelper(TreeNode* root, int height) {
        if (root == NULL) return height;
        else{
            return max(maxDepthHelper(root->left, height+1), maxDepthHelper(root->right, height+1));
        }
    }
    int maxDepth(TreeNode* root) {
        return maxDepthHelper(root, 0);
    }
};
//
//  2_max_depth_of_binary_tree.cpp
//  leetcode_apple
//
//  Created by Akshay Anand on 07/05/20.
//  Copyright © 2020 Akshay Anand. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stdint.h>
#include <regex>
#include <sstream>
#include <locale>
#include <unordered_set>
#include <stack>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int maxLevel = 0;
    
    void maxDepthUtil(TreeNode* node, int level) {
        if (level > maxLevel) maxLevel = level;
        if (node == NULL) {
            return;
        }
        maxDepthUtil(node->left, level+1);
        maxDepthUtil(node->right, level+1);
    }
    
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        maxDepthUtil(root, 0);
        return maxLevel;
    }
};


class Solution1 {
public:
    int max(int i, int j) { return i > j ? i : j; }
    int maxDepthHelper(TreeNode* root, int height) {
        if (root == NULL) return height;
        else{
            return max(maxDepthHelper(root->left, height+1), maxDepthHelper(root->right, height+1));
        }
    }
    int maxDepth(TreeNode* root) {
        return maxDepthHelper(root, 0);
    }
};