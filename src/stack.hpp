#pragma once

const int MAX_SIZE = 5;

template <typename T>
class Stack {
private:
    T arr[MAX_SIZE];
    T *top;
    T *start;
    int current_size;

public:
    Stack() {
        top = arr;
        start = arr;
        current_size = 0;
    }

    void push(T element) {
        if ( !is_full() ) {
            *top = element;
            ++top;
            current_size++;
        } else {
            throw std::out_of_range("stack is full");
        }
    }

    T pop() {
        if ( !is_empty() ) {
            current_size--;
            top--;

            T popped_element = *top;
            return popped_element;
        } else {
            throw std::out_of_range("stack is empty");
        }
    }

    T peek() {
        if (!is_empty()) {
            top--;
            T peeked_element = *top;
            top++;
            return peeked_element;
        } else {
            throw std::out_of_range("stack is empty");
        }
    }

    bool is_full(){ return (start + MAX_SIZE == top); }
    bool is_empty(){ return (top == start); }
    int size(){ return current_size; }
};