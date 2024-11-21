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

    ListNode* getKthNodeFromList(ListNode*temp , int k) {
      k-=1;
      while(temp!= nullptr && k > 0){
        k--;
        temp = temp->next;
      }
      return temp;
    }

  ListNode* reverseList(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* curr = head; 
    ListNode* next = nullptr;

    while(curr != nullptr){
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }


    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode* temp = head;
      ListNode* prevLast = nullptr;

      while(temp != nullptr){
        ListNode* kthNode = getKthNodeFromList(temp, k);
        if(kthNode == nullptr){
          if(prevLast)prevLast->next= temp;
          break;
        }
        ListNode* nextNode = kthNode->next;
        kthNode->next = nullptr;
        reverseList(temp);
        if(temp == head){
          head = kthNode;
        }
        else{
          prevLast ->next= kthNode;
        }
        prevLast = temp;
        temp = nextNode;
      }
      return head;     
    }
};
