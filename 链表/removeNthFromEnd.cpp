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
} ;
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
	void removeNode(ListNode* node){
		node->next = node->next->next ;
	}
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        ListNode dommyNode(0) ;
        dommyNode.next = head ;
        ListNode* former = head ;
		ListNode* latter = &dommyNode ;
        for(int i = 0 ; i < n ; ++i){
        	former = former->next ;
		}
		while(former){
			former = former->next ;
			latter = latter->next ;
		}
		removeNode(latter) ;
		return dommyNode.next ;
    }
};


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
