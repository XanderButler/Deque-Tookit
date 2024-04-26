#ifndef DEQUE_H
#define DEQUE_H

template <typename T>
class Deque {
private:
    T** blockmap;
    int frontIndex;
    int backIndex;
    int blockSize;
    int size;

public:
    Deque();
    ~Deque();
    void push_front(const T& value);
    void pop_front();
    void push_back(const T& value);
    void pop_back();
    T& front();
    T& back();
    bool empty() const;
    int getSize() const;
    T& operator[](int index);
};

#endif // DEQUE_H
