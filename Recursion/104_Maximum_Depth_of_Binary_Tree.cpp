class Solution {
public:
    int maxDepth(TreeNode* root) {
        // base case: agar node hi nahi hai to depth 0 hai
        if(root == NULL) return 0;
        
        // left subtree ki depth nikalo recursively
        // ye tab tak jayega jab tak left child NULL na ho jaye
        int left = maxDepth(root->left);
        
        // right subtree ki depth nikalo recursively  
        // same pattern — jab tak right child NULL na ho
        int right = maxDepth(root->right);
        
        // current node ki height = 
        // dono subtrees mein jo bada ho + 1 (current node ke liye)
        return 1 + max(left, right);
    }
};

/*
INTUITION:
Tree ki max depth = sabse lambe path mein kitne nodes hain
                    (root se leaf tak)

PATTERN: Post-order recursion
  → pehle left depth nikalo
  → phir right depth nikalo  
  → phir current node ka answer calculate karo
  (pehle recurse, phir kaam — Post-order!)

EXAMPLE:
        1          depth = 3
       / \
      2   3
     / \
    4   5

left  = maxDepth(2) = 2
right = maxDepth(3) = 1
ans   = 1 + max(2,1) = 3 ✅

TIME:  O(n) — har node ek baar visit hoti hai
SPACE: O(h) — h = tree ki height (call stack)
*/
