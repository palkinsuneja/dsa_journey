class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // base case: node nahi hai to khali vector return karo
        if(root == NULL) return {};
        
        vector<int> result;
        
        // pehle ROOT ki value add karo (Root pehle!)
        result.push_back(root->val);
        
        // phir LEFT subtree traverse karo
        vector<int> left = preorderTraversal(root->left);
        result.insert(result.end(), left.begin(), left.end());
        
        // phir RIGHT subtree traverse karo
        vector<int> right = preorderTraversal(root->right);
        result.insert(result.end(), right.begin(), right.end());
        
        return result;
    }
};

/*
PREORDER = Root → Left → Right

EXAMPLE:
        1
       / \
      2   3
     / \
    4   5

Preorder: 1, 2, 4, 5, 3

USE CASE:
Tree ko copy karna ho ya serialize karna ho
toh preorder use hota hai — root pehle aata hai
isliye reconstruction easy hoti hai! 🎯

Pre  → Root pehle  → 1,2,4,5,3
In   → Root beech  → 4,2,5,1,3
Post → Root baad   → 4,5,2,3,1
*/
