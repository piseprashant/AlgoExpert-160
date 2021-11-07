// https://www.youtube.com/watch?v=lrJaof9s4o0
/*
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

 

Example 1:


Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
Example 2:


Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
 
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool ans = false;
    bool match(TreeNode* root, TreeNode* subRoot) {
        
	// there are 3 case
	// case 1 when both left and right have some values then see if leaf values return true for both left and right
        if (root != nullptr && subRoot != nullptr ) {
           bool a = match(root->left, subRoot->left);	// 1
           bool b = match(root->right, subRoot->right); // 2
            
            if ((root->val == subRoot->val) && a && b) // a (1) - true b (2)= true then root check 4 true
                return true;
            else
                return false;
        }
	// case 2 valid case when we enter leaf nodes and both have nullptr 
        else if (root == nullptr && subRoot == nullptr)
            return true;
        else {
            // case 3 either root has nullptr or subTree has nullptr return false
            return false;
        }
    }
    
    void inOrder(TreeNode* root, TreeNode* subRoot) {
        if (root != nullptr) {
            inOrder(root->left, subRoot);  // left
            
            bool x = match(root, subRoot); // value
            if (x) { ans = x; }
                                            
            inOrder(root->right, subRoot); // right 
        }
    }
    
     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        inOrder(root, subRoot);
        return ans;
    }

};
