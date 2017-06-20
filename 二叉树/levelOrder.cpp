#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <deque>

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
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int> > ans ;
        vector<int> level ;
        if(!root){
        	return ans ;
		}
		if(!root->left && !root->right){
			level.push_back(root->val) ;
			ans.push_back(level) ;
			return ans ;
		} ;
		int former = 1 ;
		int latter = 0 ;
		TreeNode* tempNode ;
		deque<TreeNode*> levelNode ;
		levelNode.push_back(root) ;
		while(!levelNode.empty()){
			tempNode = levelNode.front() ;
			levelNode.pop_front() ;
			level.push_back(tempNode->val) ;
			if(former){
				--former ;
				if(tempNode->left){
					levelNode.push_back(tempNode->left) ;
					++latter ;
				}
				if(tempNode->right){
					levelNode.push_back(tempNode->right) ;
					++latter ;
				}
			}
			if(0 == former){
				ans.push_back(level) ;
				level.clear() ;
				former = latter ;
				latter = 0 ;
			}
		}
		return ans ;
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

void showAns(vector<vector<int> > ans){
	for(int i = 0 ; i < ans.size() ; ++i){
		for(int j = 0 ; j < ans[i].size() ; ++j){
			cout << ans[i][j] << " " ;
		}
		cout << endl ;
	}
	cout << endl ;
}

int main(){
	string str = "1#2" ;
	TreeNode* root = makeBinaryTree(str , str.size() , 1) ;
	Solution x ;
	showTree(root) ;
	return 0 ;
}
