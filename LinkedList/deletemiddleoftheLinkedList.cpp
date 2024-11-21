
// Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:

    ListNode* middleLinkedList(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head; 

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next; 
            fast  = fast->next->next;
        }
        return slow; 
    }

    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr)return nullptr;
        ListNode * middleEle = middleLinkedList(head);
        ListNode* temp = head;
        // ListNode* prev = nullptr;
        while(temp != nullptr){
           if(temp->next == middleEle){ 
            temp->next = middleEle->next;
            middleEle->next = nullptr;
           }
           temp = temp->next;
        }
        return head;
    }
};
