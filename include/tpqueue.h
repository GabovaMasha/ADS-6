// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
T *arr;
int first;
int last;

 public:
TPQueue() :
first(0), last(0) {
arr = new T[size];
}
void push(T el) {
if (last - first >= size) {
throw std::string("!");
} else {
int it = last++;
while ((--it >= first) && (arr[it % size].prior < el.prior)) {
arr[(it + 1) % size] = arr[it % size];
}
arr[(it + 1) % size] = el;
}
}
T pop() {
return arr[(first++) % size];
}
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
