#include<vector>
#include<iostream>



 //Definition for singly-linked list.

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 
class Solution {
public:

    ListNode* findNthNode(ListNode* temp , int k ){
      int cnt = 1;
      while(temp!= nullptr){
        if(cnt == k)return temp;
        cnt++;
        temp = temp->next; 
      }
    return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
      if(head == nullptr || k == 0)return head;
      ListNode* tail = head; 
      int len = 1; 
      while(tail->next != nullptr){
        len++;
        tail = tail->next;
      }
      if(k%len == 0)return head;

      k = k%len;
      tail->next = head;
      ListNode* newLastNode = findNthNode(head, len-k);
      head = newLastNode->next;
      newLastNode->next = nullptr;
      return head;
    }

    ListNode* generateLinkedListFromInput(std::vector<int>&nums){
      ListNode* head = new ListNode(nums[0]);
      ListNode* mover = head;

      for(int i= 1; i < nums.size(); i++){
        ListNode*temp = new ListNode(nums[i]);
        mover->next = temp;
        mover = temp;
      }
      return head;
    }
};


int main(){
  std::vector<int>nums = {1 , 2 , 3 , 4 , 5};
  Solution s;
  ListNode* head = s.generateLinkedListFromInput(nums);

  ListNode* ans = s.rotateRight(head, 2);
    
  while(ans != nullptr){
    std::cout << ans->val << " ";
    ans = ans->next;
  } 
}
