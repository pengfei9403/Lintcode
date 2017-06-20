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
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
	void searchHelper(TreeNode* root , int k1 , int k2 , vector<int>& ans){
		if(!root){
			return ;
		}
		if(k1 <= root->val && root->val <= k2){
			ans.push_back(root->val) ;
		}
		searchHelper(root->left , k1 , k2 , ans) ;
		searchHelper(root->right , k1 , k2 , ans) ;
	}
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
		vector<int> ans ;
        if(!root){
        	return ans ;
		}
		searchHelper(root , k1 , k2 , ans) ;
		sort(ans.begin() , ans.end()) ;
		return ans ;
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
