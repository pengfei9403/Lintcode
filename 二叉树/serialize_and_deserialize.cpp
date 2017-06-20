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
public:
    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
	deque<string> split(const string& str){
		deque<string> ans ;
		int left = 0 ;
		int right = 0 ;
		auto begin = str.begin() ;
		while(right != str.size()){
			right = find(left+begin , str.end() , ',') - begin;
			ans.push_back(str.substr(left,right-left)) ;
			left = right + 1 ;
		}
		return ans ;
	}
    string serialize(TreeNode *root) {
        // write your code here
        string ans ;
        if(!root){
        	ans = "#," ;
        	return ans ;
		}
		char temp[10] ;
		ans = to_string(root->val) + "," ;
		ans += serialize(root->left) ;
		ans += serialize(root->right) ;
		return ans ;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
	TreeNode* deserialize(deque<string>& data){
		string temp = data.front() ;
		data.pop_front() ;
		if(temp == "#"){
			return NULL ;
		}
		TreeNode* root = new TreeNode(stoi(temp)) ;
		root->left = deserialize(data) ;
		root->right = deserialize(data) ;
		return root ;
	}
    TreeNode *deserialize(string data) {
        // write your code here
        if(data.empty()){
        	return NULL ;
		}
		deque<string> Split = split(data) ;
		return deserialize(Split) ;
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
	string str = "1#2" ;
	TreeNode* root = makeBinaryTree(str , str.size() , 1) ;
	Solution x ;
	showTree(root) ;
//	str = to_string(5) + "," ;
//	cout << str << endl ;
	showTree(x.deserialize(x.serialize(root))) ;
	return 0 ;
}
