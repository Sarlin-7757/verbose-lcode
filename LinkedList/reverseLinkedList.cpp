#include<iostream>
#include <stack>

using std::stack;

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
   // ListNode* reverseList(ListNode* head) {
   //     if (head == nullptr) return nullptr; // Handle the empty list case
   //     
   //     // Stack to hold nodes
   //     std::stack<ListNode*> stack;
   //     
   //     // Traverse the list and push nodes onto the stack
   //     ListNode* temp = head;
   //     while (temp != nullptr) {
   //         stack.push(temp);
   //         temp = temp->next;
   //     }
   //     
   //     // Pop nodes from stack and update values
   //     temp = head;
   //     while (temp!=nullptr) {
   //         temp = stack.top();
   //         stack.pop();
   //         temp = temp->next;
   //     }
   //     
   //     return head;
   // }
   //
   //

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
};

