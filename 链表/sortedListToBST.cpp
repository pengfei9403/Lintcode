#include <iostream>

using namespace std ;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

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
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        if(!head){
        	return NULL ;
		}
		TreeNode* root = new TreeNode(0) ;
		if(!head->next){
			root->val = head->val ;
			return root ;
		}
		ListNode dommyNode(0) ;
		dommyNode.next = head ;
		ListNode* leftEnd = &dommyNode ;
		ListNode* midNode = head ;
		ListNode* rightHead = head->next ;
		while(head){
			if(head->next){
				head = head->next ;
			}else{
				break ;
			}
			if(head->next){
				head = head->next ;
			}else{
				break ;
			}
			leftEnd = leftEnd->next ;
			midNode =  midNode->next ;
			rightHead = rightHead->next ;
		}
		root->val = midNode->val ;
		leftEnd->next = NULL ;
		root->left = sortedListToBST(dommyNode.next) ;
		root->right = sortedListToBST(rightHead) ;
		
		return root ;
    }
};

void showList(ListNode* head){
	while(head){
		cout << head->val << " " ;
		head = head->next ;
	}
	cout << endl ;
}

void showTree(TreeNode* root){
	if(!root){
		return ;
	}
	showTree(root->left) ;
	cout << root->val << " " ;
	showTree(root->right) ;
}

int main(){
	int arr[] = {-1,0,2} ;
	int len = sizeof(arr) / sizeof(int) ;
	ListNode head(arr[0]) ;
	ListNode tempNode(0) ;
	tempNode.next = &head ;
	for(int i = 1 ; i < len ; ++i){
		ListNode* next = new ListNode(arr[i]) ;
		tempNode.next->next = next ;
		tempNode.next = next ;

	}
	Solution x ;
	showList(&head) ;
	showTree(x.sortedListToBST(&head)) ;
	return 0 ;
}

