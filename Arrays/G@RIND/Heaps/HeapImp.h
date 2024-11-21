#ifndef HEAP_H
#define HEAP_H

#include<iostream>
#include <stdexcept>
#include<vector>

using std::vector;

template <typename T>
class Heap{

  vector<T>list;    

  private: 
      void swap(int first , int second){
        T temp = list[first];
        list[first] = list[second];
        list[second] = temp;
      }

      int parent(int index){
        return (index - 1)/2;
      }

      int left(int index) {
        return index * 2 + 1;
      }

      int right(int index){
        return index*2 + 2;
      }

      void upheap(int index){
        if(index == 0){return;}
        int p = parent(index);
        if(list[index] < list[p]){
          swap(index , p);
          upheap(p);
        }
      }

      void downheap(int index) {
        int min = index;
        int leftIdx = left(index);
        int rightIdx = right(index);

        if (leftIdx < list.size() && list[min] > list[leftIdx]) {
            min = leftIdx;
        }

        if (rightIdx < list.size() && list[min] > list[rightIdx]) {
            min = rightIdx;
        }

        if (min != index) {
            swap(min, index);
            downheap(min);
        }
    }

  public:
      Heap(){}

      void insert(T value){
        list.push_back(value);
        upheap(list.size() - 1);
      }

      T remove(){
        if(list.empty()){
            throw std::runtime_error("Removing from an empty heap");
        }
        T temp = list[0];
        T last = list.back();
        list.pop_back();

        if(!list.empty()){
          list[0] = last;
          downheap(0);
        }
        return temp;
      }

      std::vector<T> heapSort(){
        std::vector<T>data;
        while(!list.empty()){
          data.push_back(this->remove());
        }
        return data;
      }

};


#endif 
