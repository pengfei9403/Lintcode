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
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
	TreeNode* linkLeftAndRight(TreeNode* left , TreeNode* right){
		if(!left->right){
			left->right = right ;
			return left ;
		}
		if(!right->left){
			right->left = left ;
			return right ;
		}
		TreeNode* temp = left->right ;
		left->right = right ;
		while(right->left){
			right = right->left ;
		}
		right->left = temp ;
		return left ;
	}
    TreeNode* removeNode(TreeNode* root, int value) {
        // write your code here
        if(!root){
        	return root ;
		}
		if(!root->left && !root->right){
			if(value == root->val){
				return NULL ;
			}else{
				return root ;
			}
		}
		if(value == root->val){
			if(!root->left){
				return root->right ;
			}
			if(!root->right){
				return root->left ;
			}
			root = linkLeftAndRight(root->left , root->right) ;
			return root ;
		}
		TreeNode* parent = root ;
		if(value < root->val){
			root->left = removeNode(root->left , value) ;
		}else{
			root->right = removeNode(root->right , value) ;
		}
		return root ;
    }
};

void showTree(TreeNode *root) {
    // write your code here
	vector<int> ans ;
	stack<TreeNode*> S ;
	TreeNode* tempNode = root ;
	S.push(root) ;
    while(!S.empty()){
    	tempNode = S.top() ;
    	cout << tempNode->val << " " ;
    	S.pop() ;
		if(tempNode->right){
			S.push(tempNode->right) ;
		}
		if(tempNode->left){
			S.push(tempNode->left) ;
		}
	}
	cout << endl ;
}

int main(){
	int arr[] = {1} ;
	int len1 = sizeof(arr) / sizeof(int) ;
	vector<int> preorder(arr , arr+len1) ;
	Solution x ;
	return 0 ;
}
