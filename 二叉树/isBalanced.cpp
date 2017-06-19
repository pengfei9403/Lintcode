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
     * @return: True if this Binary tree is Balanced, or false.
     */
	int isBlanceHelper(TreeNode* root){
		if(!root){
			return 0 ;
		}
		if(!root->left && !root->right){
			return 1 ;
		}
		int left = isBlanceHelper(root->left) ;
		int right = isBlanceHelper(root->right) ;
		if(left == -1 || right == -1){
			return -1 ;
		}
		if(abs(left - right) > 1){
			return -1 ;
		}else{
			return max(left , right) + 1 ;
		}
	}
    bool isBalanced(TreeNode *root) {
        // write your code here
        if(-1 == isBlanceHelper(root)){
        	return false ;
		}else{
			return true ;
		}
    }
};

int main(){

	return 0 ;
}
