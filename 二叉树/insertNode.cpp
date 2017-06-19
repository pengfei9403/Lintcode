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
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        if(!root){
        	root = node ;
        	return root ;
		}
		if(root->val > node->val){
			if(!root->left){
				root->left = node ;
			}else{
				insertNode(root->left , node) ;
			}
		}else{
			if(!root->right){
				root->right = node ;
			}else{
				insertNode(root->right , node) ;
			}
		}
		return root ;
    }
};

class Solution2 {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        if(!root){
        	root = node ;
        	return root ;
		}
        TreeNode* pos = root ;
        while(pos){
        	if(pos->val > node->val){
        		if(!pos->left){
        			pos->left = node ;
        			break ;
				}else{
					pos = pos->left ;
				}
			}else{
				if(!pos->right){
					pos->right = node ;
					break ;
				}else{
					pos = pos->right ;
				}
			}
		}
		return root ;
	}
};

int main(){
	
	return 0 ;
}
