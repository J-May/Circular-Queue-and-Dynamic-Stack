#include <iostream>
#include "a2_circular_queue.hpp"

using namespace std;

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue() {
    items_ = new QueueItem[16];
    head_ = 0;
    tail_ = 0;
    capacity_ = 16;
    size_ = 0;
    
}

CircularQueue::CircularQueue(unsigned int capacity) {
    items_ = new QueueItem[capacity];
    head_ = 0;
    tail_ = 1;
    capacity_ = capacity;
    size_ = 0;
}

CircularQueue::~CircularQueue() {
    delete []items_;
    items_ = NULL;
}

int CircularQueue::size() const {
    return size_;
}

bool CircularQueue::empty() const {
    
    return size_ == 0;
}

bool CircularQueue::full() const {
    
    return size_ == capacity_;
}

void CircularQueue::print() const {
    
    if (!empty()) {
        cout << "(";
        
    int index = head_;
    
    for (int i = 0; i < size_; i++) {
        index = (index + i)%size_;
        cout << "[" << items_[index] << "]";
        if (i < size_ - 1) {
            cout << "->";
        }
    }
        cout << ")";
    }
    return;
}

QueueItem CircularQueue::peek() const {
    
    if (empty()) {
        return EMPTY_QUEUE;
    }
    else return items_[head_];
}

bool CircularQueue::enqueue(QueueItem value) {
    if (size_ < capacity_) {
        items_[tail_] = value;
        tail_ = (tail_+1)%capacity_;
        size_++;
        return true;
    }
    else return false;
}

QueueItem CircularQueue::dequeue() {
    
    if (!empty()) {
        QueueItem thing = items_[head_];
        items_[head_] = 0;
        head_ = (head_+1)%capacity_;
        size_--;
        return thing;
    }
    else return EMPTY_QUEUE;
}
