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
     * @param x: an integer
     * @return: a ListNode
     */
	void linkNode(ListNode* tempEnd , ListNode* node){
		tempEnd->next->next = node ;
		tempEnd->next = node ;
	}
    ListNode *partition(ListNode *head, int x) {
        // write your code here
//        ListNode dommyNode(0) ;
//        dommyNode.next = head ;
        if(!head || !head->next){
        	return head ;
		}
		ListNode lessHead(0) ;
		ListNode moreHead(0) ;
		ListNode tempLessNode(0) ;
		ListNode tempMoreNode(0) ;
		tempLessNode.next = &lessHead ;
		tempMoreNode.next = &moreHead ;
		while(head){
			if(head->val < x){
				linkNode(&tempLessNode , head) ;
				head = head->next ;
			}else{
				linkNode(&tempMoreNode , head) ;
				head = head->next ;
			}
		}
		tempMoreNode.next->next = NULL ;
		linkNode(&tempLessNode , moreHead.next) ;
		return lessHead.next ;
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
	show(x.partition(&head,3)) ;
	
	return 0 ;
}

