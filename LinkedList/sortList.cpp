struct ListNode{
  int val;
  ListNode *next;
  ListNode(int val): val(val) , next(nullptr)  {}
  ListNode(): val(0), next(nullptr){}
  ListNode( int x , ListNode* next): val(x) , next(next){}
};




class Solution {
public:

      ListNode* middleNode(ListNode* head) {
      ListNode*slow = head;
      ListNode* fast = head->next;

      while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
      }
        
     return slow;   
    }


    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode* t1 = list1;
      ListNode* t2 = list2;
      ListNode* dummyNode = new ListNode(-1);
      ListNode* temp  = dummyNode;


      if(t1 == nullptr)return t2;
      if(t2 == nullptr)return t1;

      while(t1 != nullptr && t2 != nullptr){
        if(t1->val < t2->val){
          temp->next = t1;
          temp = t1;
          t1 = t1->next;
        }
        else{
          temp->next = t2 ;
          temp = t2; 
          t2 = t2->next;
        }
        if(t1){temp->next = t1;}
        else {temp->next = t2;}
      }
      ListNode* mergedList =  dummyNode->next;        
      delete(dummyNode);
      return mergedList;
    }




    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)return head;

        ListNode* middle =  middleNode(head);
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left= head;


        left = sortList(left);
        right = sortList(right);

        return mergeTwoLists(left, right);
        
    }
};
