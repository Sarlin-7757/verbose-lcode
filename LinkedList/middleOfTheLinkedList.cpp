#include<iostream>
#include<vector>


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
  /* original function returns node so return-type will be ListNode* 
    here just to get the val of the node we have changed the return 
    type of the function.

  */
    int middleNode(ListNode* head) {
      ListNode*slow = head;
      ListNode* fast = head;

      while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
      }
        
     return slow->val;   
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

  std::vector<int>nums = {1 ,2 , 3 , 4 ,5};
  Solution s; 

  ListNode* head = s.generateLinkedListFromInput(nums);
  std::cout << s.middleNode(head);
}
