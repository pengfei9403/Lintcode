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
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        if(preorder.empty()){
        	return NULL ;
		}
		TreeNode* root = new TreeNode(preorder[0]) ;
		if(1 == preorder.size()){
			return root ;
		}
		int cnt = 0 ;
		while(preorder[0] != inorder[cnt]){
			++cnt ;
		}
		vector<int>::iterator begin = preorder.begin() + 1 ;
		vector<int> leftPreorder(begin , begin+cnt) ;
		begin = inorder.begin() ;
		vector<int> leftInorder(begin , begin+cnt) ;
		root->left = buildTree(leftPreorder , leftInorder) ;
		begin = preorder.begin() + 1 + cnt ;
		vector<int> rightPreorder(begin , preorder.end()) ;
		begin = inorder.begin() + 1 + cnt ;
		vector<int> rightInorder(begin , inorder.end()) ;
		root->right = buildTree(rightPreorder , rightInorder) ;
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
	int arr2[] = {1} ;
	int len1 = sizeof(arr) / sizeof(int) ;
	int len2 = sizeof(arr2) / sizeof(int) ;
	vector<int> preorder(arr , arr+len1) ;
	vector<int> inorder(arr2 , arr2+len2) ;
	Solution x ;
	showTree(x.buildTree(preorder , inorder)) ;
	return 0 ;
}
