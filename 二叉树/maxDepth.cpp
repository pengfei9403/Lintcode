#include <iotream>
#include <algorithm>


using namespace std ;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // write your code here
        if(!root){
        	return 0 ;
		}
		if(!root->left && !root->right){
			return 1 ;
		}
		return max(maxDepth(root->left) , maxDepth(root->right)) + 1 ;
    }
};

int main(){
	
	return 0 ;
}
