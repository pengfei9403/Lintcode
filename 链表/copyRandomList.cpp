#include <iostream>

using namespace std ;


struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
 
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
	void copyRandomListNode(RandomListNode* source , RandomListNode* target){
		target->label = source->label ;
		target->next = target->next ;
	}
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        if(!head){
        	return NULL ;
		}
		RandomListNode dommyNode(0) ;
		dommyNode.next = head ;
		while(head){
			RandomListNode* tempNode = new RandomListNode(0) ;
			copyRandomListNode(head , tempNode) ;
			tempNode->next = head->next ;
			head->next = tempNode ;
			head = tempNode->next ;
		}
		head = dommyNode.next ;
		RandomListNode* newHead = head->next ;
		while(head){
			if(head->random){
				newHead->random = head->random->next ;
			}else{
				newHead->random = NULL ;
			}
			head = head->next->next ;
			if(head){
				newHead = newHead->next->next ;
			}
		}
		head = dommyNode.next ;
		newHead = head->next ;
		dommyNode.next = newHead ;
		while(head){
			head->next = head->next->next ;
			head = head->next ;
			if(head){
				newHead->next = newHead->next->next ;
				newHead = newHead->next ;
			}
		}
		return dommyNode.next ;
    }
};

void showRandomList(RandomListNode* head){
	while(head){
		cout << head->label << " " ;
		head = head->next ;
	}
	cout << endl ;
}

int main(){
	int arr[] = {4,2,3,1} ;
	int len = sizeof(arr) / sizeof(int) ;
	RandomListNode head(arr[0]) ;
	RandomListNode tempNode(0) ;
	tempNode.next = &head ;
	for(int i = 1 ; i < len ; ++i){
		RandomListNode* next = new RandomListNode(arr[i]) ;
		tempNode.next->next = next ;
		tempNode.next = next ;

	}
	Solution x ;
	showRandomList(&head) ;
	showRandomList(x.copyRandomList(&head)) ;
}
