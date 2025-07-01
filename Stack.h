#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>
#include <numeric>
#include <stdexcept>

// Stack class to manage a stack of integers using a vector
class Stack {
private:
    std::vector<int> data; // Internal storage for stack elements

public:
    // Checks if the stack is empty
    bool isEmpty() const {
        return data.empty();
    }

    // Pushes a new integer onto the top of the stack
    void push(int value) {
        data.push_back(value);
    }

    // Removes the top element from the stack
    void popTop() {
        if (!isEmpty()) {
            data.pop_back();
        }
        else {
            std::cout << "Stack is empty. Cannot pop from top.\n";
        }
    }

    // Removes the bottom element from the stack (first in the vector)
    void popBottom() {
        if (!isEmpty()) {
            data.erase(data.begin());
        }
        else {
            std::cout << "Stack is empty. Cannot pop from bottom.\n";
        }
    }

    // Returns the top element of the stack
    int top() const {
        if (!isEmpty()) {
            return data.back();
        }
        else {
            throw std::runtime_error("Stack is empty. No top element.");
        }
    }

    // Calculates and returns the average of all elements in the stack
    double average() const {
        if (!isEmpty()) {
            int sum = std::accumulate(data.begin(), data.end(), 0);
            return static_cast<double>(sum) / data.size();
        }
        else {
            throw std::runtime_error("Stack is empty. Cannot compute average.");
        }
    }

    // Displays the stack elements from top to bottom
    void display() const {
        std::cout << "Stack (top→bottom): ";
        for (auto it = data.rbegin(); it != data.rend(); ++it)
            std::cout << *it << ' ';
        std::cout << '\n';
    }
};

#endif
