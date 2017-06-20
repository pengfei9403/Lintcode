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
     * @return: True if the binary tree is BST, or false
     */
	bool isValidBSTHelper(TreeNode* root , int min , int max){
		if(!root){
			return true ;
		}
		if(!root->left && !root->right){
			if(min <= root->val && root->val <= max){
				return true ;
			}else{
				return false ;
			}
		}
		bool left , right ;
		left = isValidBSTHelper(root->left , min , root->val) ;
		right = isValidBSTHelper(root->right , root->val , max) ;
		if(left && right && root->left && root->right){
			if(min < root->left->val && root->left->val < root->val && root->val < root->right->val && root->right->val < max){
				return true ;
			}else{
				return false ;
			}
		}
		if(left && right && root->left){
			if(min <= root->left->val && root->left->val < root->val){
				return true ;
			}else{
				return false ;
			}
		}
		if(left && right && root->right){
			if(root->val < root->right->val && root->right->val <= max){
				return true ;
			}else{
				return false ;
			}
		}
		return false ;
	}
    bool isValidBST(TreeNode *root) {
        // write your code here
        if(!root){
        	return true ;
		}
		if(!root->left && !root->right){
			return true ;
		}
        return isValidBSTHelper(root , INT_MIN , INT_MAX) ;
    }
};

TreeNode* makeBinaryTree(string& arr , int n , int pos){
	if(arr[pos-1] == '#'){
		return NULL ;
	}
	TreeNode* root = new TreeNode(arr[pos-1] - '0') ;
	if(2*pos < n){
		root->left = makeBinaryTree(arr , n , 2*pos) ;
	}
	if(2*pos+1 <= n){
		root->right = makeBinaryTree(arr , n , 2*pos+1) ;
	}
	return root ;
}

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
	string str = "123#" ;
	TreeNode* root = makeBinaryTree(str , str.size() , 1) ;
	Solution x ;
	TreeNode node1(1) ;
	TreeNode node2(2) ;
	TreeNode node3(3) ;
	node1.right = &node2 ;
	node2.left = & node3 ;
	showTree(&node1) ;
	showTree(root) ;
	x.isValidBST(&node1) ;
	cout << "INT_MIN :" << INT_MIN << endl ;
	cout << "INT_MAX :" << INT_MAX << endl ;
	return 0 ;
}
