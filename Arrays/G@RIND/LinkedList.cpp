#include<iostream>

using std::cout;
using std::endl;

struct ListNode{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr){}
  ListNode(int x): val(x), next(nullptr){}
  ListNode(int x , ListNode *next): val(x), next(next){}
};

class LinkedList{
  ListNode *head;

  public: 
    LinkedList(){head = nullptr;}

    void insertNode(int);

    void printList();

    void deleteNode(int);

    ListNode * searchNode(ListNode* p , int key);
    
    ListNode* getHead() {
      return head;
    }

};

ListNode* LinkedList :: searchNode(ListNode *p , int key){
  while(p != nullptr){
    if(key == p->val){
      return (p); 
    }
    p = p->next;
  }
  return nullptr;
}

void LinkedList::deleteNode(int nodeOffset){
  ListNode *temp1 = head, *temp2 = nullptr;

  int ListLen = 0;  

  if(head == nullptr){
    std::cout<< "List is empty" << "\n";
    return;
  }
  while(temp1 != nullptr){
    temp1 = temp1->next;
    ListLen++;
  }

  if(ListLen < nodeOffset){
    std::cout<< "Index out of range"<< "\n";
    return;
  }

  temp1 = head;

  if(nodeOffset == 1){
    head = head->next;
    delete temp1;
    return;
  }

  while(nodeOffset-- > 1){
    temp2 = temp1;

    temp1 = temp1->next;
  }

  temp2 -> next = temp1->next;
  delete temp1;
}

void LinkedList::insertNode(int data){
  ListNode* newNode = new ListNode(data);

  if(head == nullptr){
    head = newNode;
    return;
  }

  ListNode* temp = head;
  while(temp->next != nullptr){
    temp = temp->next;
  }
  temp->next = newNode;
}


void LinkedList::printList(){
  ListNode* temp = head;
  if(head == nullptr){
    std::cout<< "list empty"<< "\n";
    return;
  }

  while(temp != nullptr){
    std::cout << temp->val << " ";
    temp = temp->next;
  }
}

int main(){

  LinkedList list;

  list.insertNode(1);
  list.insertNode(2);
  list.insertNode(3);
  list.insertNode(4);

  std::cout << "Elements of the list are ";

  list.printList();


  list.insertNode(10);

  std::cout << "New list is"<< "\n";
    
  list.printList();


  list.deleteNode(2);

  std::cout << std::endl;


  std::cout<< "Elements after deleting a node are " << "\n";

  list.printList();
  
  std::cout<< std::endl;


  int searchValue = 20;
  ListNode* result = list.searchNode(list.getHead(), searchValue);

  if(result != nullptr){
    std::cout<<searchValue << " found - "<< result->val<< "\n";
  }
  else{
    std::cout<< "not found "<< result << "\n";
  }
  
  
//  ListNode* head;

  //head->val = 10;

  //std::cout<< head->val << "\n";
  //std::cout<< head->next << "\n";

  //ListNode*first;
  //std::cout << createNode(first , 10);
  //std:: cout << first->val;
  
//  ListNode* node = new ListNode(10); 
//  
//  ListNode* temp1 = new ListNode(20);
//  ListNode* temp2  = new ListNode(30);
//
//
//  head->next = temp1;
//  temp1->next = temp2;
//
  return 0;

}


