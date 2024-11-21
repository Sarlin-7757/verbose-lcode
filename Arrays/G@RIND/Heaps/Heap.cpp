#include<iostream>
#include<vector>
#include "HeapImp.h"


int main(){
  try{

    Heap<int>heap;

    heap.insert(10);
    heap.insert(4);
    heap.insert(15);
    heap.insert(20);
    heap.insert(0);
    heap.insert(7);


    std::vector<int> sortedElements = heap.heapSort();
    std::cout<< "Sorted elements: ";

    for(int elem: sortedElements){
      std::cout<< elem << " ";
    }
    std::cout<< std::endl;
  }
  catch(const std::exception &e){
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
