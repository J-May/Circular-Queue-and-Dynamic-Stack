#include <iostream>
#include "a2_dynamic_stack.hpp"

using namespace std;

typedef DynamicStack::StackItem StackItem; 
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack() {
    items_ = new StackItem[16];
    size_ = 0;
    capacity_ = 16;
    init_capacity_ = 16;
}

DynamicStack::DynamicStack(unsigned int capacity) {
    items_ = new StackItem[capacity];
    size_ = 0;
    capacity_ = capacity;
    init_capacity_ = capacity;
}

DynamicStack::~DynamicStack() {
    delete [] items_;
    items_ = NULL;
}

int DynamicStack::size() const {
    return size_;
}

bool DynamicStack::empty() const {
    return size_ == 0;
}

void DynamicStack::print() const {
    if (!empty()) {
        cout << "(";
        
        for (int i = 0; i < size_; i++) {
            cout << "[" << items_[i] << "]";
            if (i < size_ - 1) {
                cout << "->";
            }
        }
        cout << ")";
    }
    return;
}

StackItem DynamicStack::peek() const {
    if (empty()) {
        return EMPTY_STACK;
    }
    return items_[size_ - 1];
}

void DynamicStack::push(StackItem value) {
    if (size_== capacity_) {
        capacity_ = 2*capacity_;
        StackItem* tempstack = new StackItem[capacity_];
        
        for (int i = 0; i < size_; i++) {
            tempstack[i] = items_[i];
        }
        
        delete [] items_;
        items_ = tempstack;
        tempstack = NULL;
    }
        items_[size_] = value;
        size_++;
}

StackItem DynamicStack::pop() {
    if (empty()) {
        return EMPTY_STACK;
    }
    else{
        StackItem temp = items_[size_-1];
        items_[size_-1] = 0;
        size_--;
        
        if (size_ <= capacity_/4 && capacity_/2 >= init_capacity_) {
            capacity_ = capacity_/2;
            
            StackItem* tempstack = new StackItem[capacity_];
            
            for (int i = 0; i < size_; i++) {
                tempstack[i] = items_[i];
            }
            
            delete [] items_;
            items_ = tempstack;
            tempstack = NULL;
        }
        return temp;
    }
}
