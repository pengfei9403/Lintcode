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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
	void linkNode(ListNode* tempEnd , ListNode* node){
		tempEnd->next->next = node ;
		tempEnd->next = node ;
	}
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode dommyNode(0) ;
        if( !l1 && !l2 ){
        	return NULL ;
		}
		if( !l1 && l2 ){
			return l2 ;
		}
		if( l1 && !l2 ){
			return l1 ;
		}
		if(l1->val < l2->val){
			dommyNode.next = l1 ;
			l1 = l1->next ;
		}else{
			dommyNode.next = l2 ;
			l2 = l2->next ;
		}
        ListNode tempNode(0) ;
        tempNode.next = dommyNode.next ;
		while(l1 && l2){
			if(l1->val < l2->val){
				linkNode(&tempNode , l1) ;
				l1 = l1->next ;
			}else{
				linkNode(&tempNode , l2) ;
				l2 = l2->next ;
			}
		}
		if(l1){
			linkNode(&tempNode , l1) ;
		}
		if(l2){
			linkNode(&tempNode , l2) ;
		}
		return dommyNode.next ;
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
	int arr[] = {17,75,80,87,44,45,75,86,74,20} ;
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

	return 0 ;
}

