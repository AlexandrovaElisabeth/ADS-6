// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T *arr;
    int first, last, count;

 public:
    TPQueue() : first(0), last(0), count(0) {
        arr = new T[size];
    }
    ~TPQueue() {
        delete[] arr;
    }
    bool isEmpty() const {
        return 0 == count;
    }
    bool isFull() const {
        return size == count;
    }
    void push(const T& value) {
        if (isFull()) {
            throw std::string("Full");
        } else {
            int temp = first;
            while (temp != last && value.prior <= arr[temp].prior) {
                temp = (++temp) % size;
            }
            for (int i = last; i != temp; i = (size + i - 1) % size) {
                arr[(size + i - 1) % size] = arr[i];
            }
            count++;
            last = (last + 1) % size;
            arr[temp] = value;
        }
    }
    const T& pop() {
        if (isEmpty()) {
            throw std::string("Empty");
        } else {
            count--;
            return arr[first++ % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
