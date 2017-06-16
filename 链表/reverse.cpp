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
     * @return: The new head of reversed linked list.
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
};

void show(ListNode* head){
	while(head){
		cout << head->val << " " ;
		head = head->next ;
	}
	cout << endl ;
}

int main(){
	int arr[] = {1,4,3,2,5,2} ;
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
	show(x.reverse(&head)) ;
	
	return 0 ;
}

