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
     * @return: head node
     */
	void removeNode(ListNode* node){
		node->next = node->next->next ;
	}
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        ListNode dommyNode(0) ;
        dommyNode.next = head ;
		if(!head){
			return dommyNode.next ;
		}
		while(head->next){
			if(head->val == head->next->val){
				removeNode(head);
			}else{
				head = head->next ;
			}
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
	show(x.deleteDuplicates(&head)) ;
	
	return 0 ;
}

