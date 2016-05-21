#ifndef STACKPAIR_H_
#define STACKPAIR_H_
#include <vector>
#include <iostream>
#include <string>
using namespace std;

template<class T>
class StackPair{

  int frontStack, rearStack, upperBound;
  vector<T>* elements; 

  public:
  StackPair(int guaranteedCapacity);
  ~StackPair();
  int size() const;
  bool frontEmpty() const;
  bool rearEmpty() const;
  T popFront();
  T popRear();
  void pushFront(T& newItem);
  void pushRear(T& newItem);
  };

template<class T>
  StackPair<T>::StackPair(int guaranteedCapacity) : frontStack(-1), rearStack(guaranteedCapacity), 
                                                   upperBound(guaranteedCapacity), elements(new 
                                                   vector<T>(guaranteedCapacity)) {}

template<class T>
StackPair<T>::~StackPair(){
  delete(elements);
}

template<class T>
int StackPair<T>::size() const{
  return (frontStack + 1) +  (upperBound-rearStack);
} 

template<class T>
bool StackPair<T>::frontEmpty() const{
  return frontStack == -1;
}

template<class T>
bool StackPair<T>::rearEmpty() const{
  return rearStack == upperBound;
}

template<class T>
T StackPair<T>::popFront(){
  if(!frontEmpty()){
    return elements->at(frontStack--);
  }
  else{
    cerr << "Define an exception later for this.";
    return ' ';
  }
}

template<class T>
T StackPair<T>::popRear(){
  if(!rearEmpty()){
    return elements->at(rearStack++);
  }
  else{
    cerr << "Define an exception later for this.";
  return ' ';
  }
}
//REQ: Vector must not be completely full to prevent out-of-range errors.
template<class T>
void StackPair<T>::pushFront(T& newItem){
  elements->at(++frontStack) = newItem;
}
//REQ: Vector must not be completely full to prevent out-of-range errors.
template<class T>
void StackPair<T>::pushRear(T& newItem){
  elements->at(--rearStack) = newItem;
}
#endif
