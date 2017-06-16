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
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if(!head || !head->next || !k){
        	return head ;
		}
        ListNode dommyNode(0) ;
        dommyNode.next = head ;
        ListNode* former = head ;
        ListNode* latter = head ;
        for(int i = 0 ; i < k ; ++i){
        	if(!former->next){
				former = &dommyNode ;
			}
        	former = former->next ;
		}
		if(!former){
			return head ;
		}
		while(former->next){
			former = former->next ;
			latter = latter->next ;
		}
		former->next = dommyNode.next ;
		dommyNode.next = latter->next ;
		latter->next = NULL ;
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
	show(x.rotateRight(&head,19)) ;
	
	return 0 ;
}

