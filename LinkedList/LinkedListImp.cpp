#include<vector>
#include<iostream>


class Node{
  public: 
    int data;
    Node* next;

  public:
    Node(int data): data(data), next(nullptr){};

    Node(int data, Node* next){
      this->data= data;
      this->next = next;
    }
};


class LinkedList{
  public: 

  //++++++++++++++++++++++++++INSERTION IN THE LINKED LIST++++++++++++++++++++++++++
    
     Node* insertBeforeValueatKthPosition(Node *head , int ele , int val){
      if(head == nullptr)return nullptr; 
      
      if(head->data == val){
        return new Node(ele , head);
      }

      Node*temp = head;
      while(temp->next != nullptr){
        if(temp->next->data == val){
          Node* newNode = new Node(ele , temp->next);
          temp->next = newNode;
          break;
        }
        temp = temp->next;
      }
      return head;
    }




    Node* insertNodeatKthPosition(Node *head , int ele , int pos){
      if(head == nullptr){
        if(pos == 1){
          return new Node(ele);
        }else{
          return head;
        }
      }
      if(pos == 1){
        return new Node(ele , head);
      }
      int count = 0;
      Node*temp = head;
      while(temp != nullptr){
        count++;
        if(count == (pos-1)){
          Node* newNode = new Node(ele , temp->next);
          temp->next = newNode;
          break;
        }
        temp = temp->next;
      }
      return head;
    }

    Node* insertNodeAtTail(Node*head , int val){
      if(head == nullptr){
        return new Node(val);
      }

      Node* temp = head;
      while(temp->next != nullptr){
        temp = temp->next;
      }
      Node* newNode = new Node(val);
      temp->next = newNode;
      return head;
    }

    Node* insertNodeatStart(Node*head, int val){
      Node*temp = new Node(val , head);
      return temp;
    }

    //+++++++____________________DELETION IN THE LINKED LIST______________+++++++
    
     Node* removeElementAsValueFromLinkedList(Node*head , int val){
      if(head == nullptr)return head;

      if(head->data == val){
        
        Node*temp = head;

        if(head->next == nullptr)return nullptr;
        
        head = head->next;
        free(temp);
        return head;
      }
      
      Node* temp = head, *prev = nullptr;

      while(temp != nullptr){
        if(temp->data == val){
          prev->next = prev->next->next;
          free(temp);
          break;
        }
        prev = temp;
        temp = temp->next;
      }

      return head;
    }


    Node* removeElementFromKthPosition(Node*head , int k){
      if(head == nullptr)return head;

      if(k == 1){
        
        Node*temp = head;

        if(head->next == nullptr)return nullptr;
        
        head = head->next;
        free(temp);
        return head;
      }
      
      int count = 0; 
      Node* temp = head, *prev = nullptr;

      while(temp != nullptr){
        count++;
        if(count == k){
          prev->next = prev->next->next;
          free(temp);
          break;
        }
        prev = temp;
        temp = temp->next;
      }

      return head;
    }


    Node*removeElementFromTailOfLinkedList(Node*head){
      if(head == nullptr || head->next == nullptr)return nullptr;

      Node*temp  = head;

      while(temp->next->next != nullptr){
        temp = temp->next;
      }
      free(temp->next);
      temp->next = nullptr;
      return head;
    }

     Node* removeElementsFromStartOfLinkedList(Node *head){
      Node* temp = head; 

      if(head == nullptr)return head;

      head = head->next;
      delete temp;
      return head;
    }

    void printLinkedList(Node * head){
      while(head != nullptr){
        std::cout << head->data << " ";
        head = head->next;
      }
    }

    Node* generateLinkedListFromInput(std::vector<int>&nums){
      Node* head = new Node(nums[0]);
      Node* mover = head;

      for(int i= 1; i < nums.size(); i++){
        Node*temp = new Node(nums[i]);
        mover->next = temp;
        mover = temp;
      }
      return head;
    }

    std::vector<int> iterateOverLinkedList(std::vector<int>&nums){
      std::vector<int>ans;

      Node* head= generateLinkedListFromInput(nums);
      Node*temp = head;
      while(temp){
        ans.push_back(temp->data);
        temp= temp->next;
      }
      return ans;
    }

    int lengthOfTheGivenLinkedList(Node*head){
      int count = 0;
      Node*temp = head;
      while(temp){
        temp = temp->next;
        count++;
      }
      return count;
    }

    int checkInTheLinkedListElementIsPresentOrNot(Node*head , int target){
      Node* temp = head;
      while(temp){
        if(temp->data == target)return 1;
        temp = temp->next;
      }
      return 0;
    }

   
};

int main(){


  std::vector<int>nums = {5 ,3 ,23 , 1};
  LinkedList LL;
//  Node* ans = LL.generateLinkedListFromInput(nums);
//  std::cout<< ans << "\n";
//  std::cout << ans->data << "\n";
//  std::cout<< ans->next << "\n";
//  
//
//  Node* temp = ans;
//  while(temp){
//    std::cout<< temp->data << " ";
//    temp = temp->next;
//  }
// 
  //std::vector<int>result = LL.iterateOverLinkedList(nums);
  //for(auto it : result){
  //  std::cout<< it << " ";
  //}
//

 

  std::cout<<std::endl;
    
  Node* head = LL.generateLinkedListFromInput(nums);
  int k = 2;

  //std::cout<< LL.lengthOfTheGivenLinkedList(head);
   
  //std::cout<<std::endl;

  //std::cout << LL.checkInTheLinkedListElementIsPresentOrNot(head , 19);

  // std::cout<<std::endl;

  //head = LL.removeElementsFromStartOfLinkedList(head); // replace the previous head by new head, by assigning head = function(head)
  //head = LL.removeElementFromTailOfLinkedList(head);
  
  //head = LL.removeElementFromKthPosition(head,  k);
  //head = LL.insertNodeatStart(head,24);
  //head = LL.insertNodeAtTail(head, 56);
  //head = LL.insertNodeatKthPosition(head,45, 2);
  head =LL.insertBeforeValueatKthPosition(head , 100 , 3);
  LL.printLinkedList(head);
 
}
