#include <iostream>
#include "deque.h"

// Constructor
template <typename T>
Deque<T>::Deque() {
    blockmap = nullptr;
    frontIndex = 0;
    backIndex = -1;
    blockSize = 10; // Initial block size
    size = 0;
    blockmap = new T*[blockSize];
    for (int i = 0; i < blockSize; ++i) {
        blockmap[i] = new T[blockSize];
    }
}

// Destructor
template <typename T>
Deque<T>::~Deque() {
    for (int i = 0; i < blockSize; ++i) {
        delete[] blockmap[i];
    }
    delete[] blockmap;
}

// Push element to the front
template <typename T>
void Deque<T>::push_front(const T& value) {
    --frontIndex;
    if (frontIndex < 0) {
        // Resize blockmap and move elements if necessary
    }
    blockmap[frontIndex / blockSize][frontIndex % blockSize] = value;
    ++size;
}


// Pop element from the front
template <typename T>
void Deque<T>::pop_front() {
    if (size == 0) {
        // Handle underflow
    }
    --size;
    ++frontIndex;
}

// Push element to the back
template <typename T>
void Deque<T>::push_back(const T& value) {
    ++backIndex;
    if (backIndex >= blockSize) {
        // Resize blockmap and move elements if necessary
    }
    blockmap[backIndex / blockSize][backIndex % blockSize] = value;
    ++size;
}

// Pop element from the back
template <typename T>
void Deque<T>::pop_back() {
    if (size == 0) {
        // Handle underflow
    }
    --size;
    --backIndex;
}

// Access the first element
template <typename T>
T& Deque<T>::front() {
    if (size == 0) {
        // Handle empty deque
    }
    return blockmap[frontIndex / blockSize][frontIndex % blockSize];
}

// Access the last element
template <typename T>
T& Deque<T>::back() {
    if (size == 0) {
        // Handle empty deque
    }
    return blockmap[backIndex / blockSize][backIndex % blockSize];
}

// Check if deque is empty
template <typename T>
bool Deque<T>::empty() const {
    return size == 0;
}

// Get the size of the deque
template <typename T>
int Deque<T>::getSize() const {
    return size;
}

// Array-like access operator
template <typename T>
T& Deque<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        // Handle out-of-bounds access
    }
    return blockmap[(frontIndex + index) / blockSize][(frontIndex + index) % blockSize];
}

// Explicit template instantiation for int
template class Deque<int>;
