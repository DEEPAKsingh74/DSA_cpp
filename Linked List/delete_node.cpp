/*

237. Delete Node in a Linked List

3 DESCRIPTION: 
	5. You are given the node to be deleted node. You will not be given access to the first node of head.


3 APPROACH:
	5. Copy the value of the next node to the current node and delete the final node.
	5. Keep track of the previous node so that at last we can point the previous node to NULL.


 */


#include <iostream>

using namespace std;

struct ListNode {
     int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = NULL;

        while(node != NULL && node->next != NULL){
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }

        prev->next = NULL;
        delete node;
    }
};

int main(){
	
	
	return 0;
}