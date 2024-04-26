#include <iostream>
#include "deque.h"

int main() {
    // Initialize deque
    Deque<int> myDeque;

    // Perform coordinated pushes and pops
    const int numIterations = 1000;
    for (int i = 0; i < numIterations; ++i) {
        // Push values to both front and back
        myDeque.push_front(i);
        myDeque.push_back(i * 2);

        // Pop values from both front and back
        myDeque.pop_front();
        myDeque.pop_back();

        // Access elements using []
        myDeque[i] = i * 3;
    }

    // Validate the deque size and contents
    if (!myDeque.empty()) {
        std::cout << "Deque size: " << myDeque.getSize() << std::endl;
        std::cout << "Front element: " << myDeque.front() << std::endl;
        std::cout << "Back element: " << myDeque.back() << std::endl;

        // Access elements using []
        for (int i = 0; i < myDeque.getSize(); ++i) {
            std::cout << "Element at index " << i << ": " << myDeque[i] << std::endl;
        }
    } else {
        std::cout << "Deque is empty!" << std::endl;
    }

    return 0;
}
