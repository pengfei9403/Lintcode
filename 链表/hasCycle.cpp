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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
        if(!head || !head->next){
        	return false ;
		}
        ListNode* slow = head ;
		ListNode* fast = head->next ;
        while(slow != fast && fast && fast->next){
			slow = slow->next ;
			fast = fast->next->next ;
		}
		if(!fast || !fast->next){
			return false ;
		}else{
			return true ;
		}
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
	int arr[] = {1,-1} ;
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
	cout << x.hasCycle(&head) << endl ;
	return 0 ;
}
