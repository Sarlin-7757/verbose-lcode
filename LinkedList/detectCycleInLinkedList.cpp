#include <array>
#include <unordered_map>
#include<vector>



 // Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
       ListNode* temp = head;
       ListNode* slow = head;
       ListNode* fast = head; 

       if(temp == nullptr || temp->next == nullptr)return false;
  

       while(fast  != nullptr && fast->next != nullptr){

         slow = slow->next;
         fast = fast->next->next;

         if(slow == fast){
           return true;
         }
       }
      return false; 
    }

    //++++++++++++++++++++++++++++++++++++++SECOND APPROACH+++++++++++++++++++++++

    bool hasCycleDetection(ListNode* head){
      std::unordered_map<ListNode*, bool>visited;

      ListNode* temp = head; 
      if(temp== nullptr || temp->next == nullptr)return false;

      while(temp!= nullptr){
        if(visited[temp]== true){
          return true;
        }
        visited[temp] = true;
        temp= temp->next;
      }
      return false;
    }
};


