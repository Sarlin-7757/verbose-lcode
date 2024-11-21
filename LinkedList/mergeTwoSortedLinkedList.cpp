#include<iostream>
#include<vector>



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
  std::vector<int>nums1 = {1 ,2 , 3 , 4};
  std::vector<int>nums2 = {1 , 4 , 5 , 6 ,7};

  Solution s;

  ListNode* list1 = s.generateLinkedListFromInput(nums1);
  ListNode* list2 = s.generateLinkedListFromInput(nums2);

  std::cout << s.mergeTwoLists(list1 , list2);

}
