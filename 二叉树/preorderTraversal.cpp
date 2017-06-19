#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

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
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
		vector<int> ans ;
		stack<TreeNode*> S ;
		if(!root){
			return ans ;
		}
		TreeNode* tempNode = root ;
		S.push(root) ;
        while(!S.empty()){
        	tempNode = S.top() ;
        	ans.push_back(tempNode->val) ;
        	S.pop() ;
			if(tempNode->right){
				S.push(tempNode->right) ;
			}
			if(tempNode->left){
				S.push(tempNode->left) ;
			}
		}
		return ans ;
    }
};


int main(){

	return 0 ;
}
