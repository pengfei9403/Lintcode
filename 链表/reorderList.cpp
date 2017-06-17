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

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: void
     */
	ListNode *reverse(ListNode *head) {
        // write your code here
        if(!head || !head->next){
        	return head ;
		}
        ListNode* tempNode ;
        ListNode* leftHead ;
        ListNode* nextNode ;
        leftHead = head->next ;
        head->next = NULL ;
        tempNode = head ;
        while(leftHead){
        	nextNode = leftHead->next ;
			leftHead->next = tempNode ;
			tempNode = leftHead ;
			leftHead = nextNode ;
		}
		return tempNode ;
    }
    void reorderList(ListNode *head) {
        // write your code here
		if(!head || !head->next || !head->next->next){
			return ;
		}
		ListNode dommyNode(0) ;
		dommyNode.next = head ;
		ListNode* midNode = head ;
		ListNode* rightHead = head->next ;
		ListNode* leftHead = head->next ;
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
			midNode =  midNode->next ;
			rightHead = rightHead->next ;
		}
		midNode->next = NULL ;
		head = dommyNode.next;
		rightHead = reverse(rightHead) ;
		bool linkRight = true ;
		while(head && rightHead){
			if(linkRight){
				head->next = rightHead ;
				head = head->next ;
				rightHead = rightHead->next ;
				linkRight = false ;
			}else{
				head->next = leftHead ;
				head = head->next ;
				leftHead = leftHead->next ;
				linkRight = true ;
			}
		}
		if(leftHead){
			head->next = leftHead ;
			head = head->next ;
		}
		if(rightHead){
			head->next = rightHead ;
			head = head->next ;
		}
		head->next = NULL ;
		head =  dommyNode.next ;
    }
};


void show(ListNode* head){
	while(head){
		cout << head->val << " " ;
		head = head->next ;
	}
	cout << endl ;
}

int main(){
	int arr[] = {2,-1,0} ;
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
	show(&head) ;
	x.reorderList(&head) ;
	show(&head) ;
}

