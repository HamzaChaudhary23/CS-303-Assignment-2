#include <iostream>
#include "Stack.h"

int main() {
    Stack myStack;  // Create a stack object
    std::cout << "Stack created.\n";

    // Check if the stack is initially empty
    std::cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes\n" : "No\n");

    // Ask the user how many integers they want to push onto the stack
    int count;
    std::cout << "\nHow many integers would you like to push onto the stack? ";
    std::cin >> count;

    // Take integer inputs from the user and push them onto the stack
    std::cout << "Enter " << count << " integer(s):\n";
    for (int i = 0; i < count; ++i) {
        int value;
        std::cin >> value;
        myStack.push(value);
    }

    // Display the stack after pushing elements
    myStack.display();

    // Ask the user whether they want to remove an element and from where (top or bottom)
    char choice;
    std::cout << "\nDo you want to remove an element?\n";
    std::cout << "Enter 't' for top, 'b' for bottom, or 'n' for no: ";
    std::cin >> choice;

    // Perform pop operation based on user's choice
    if (choice == 't' || choice == 'T') {
        myStack.popTop();  // Remove top element
        std::cout << "Top element removed.\n";
        myStack.display(); // Show updated stack
    }
    else if (choice == 'b' || choice == 'B') {
        myStack.popBottom();  // Remove bottom element
        std::cout << "Bottom element removed.\n";
        myStack.display();    // Show updated stack
    }
    else {
        std::cout << "No element removed.\n";
    }

    // Try to display the top element of the stack
    try {
        std::cout << "\nTop element: " << myStack.top() << '\n';
    }
    catch (const std::exception& e) {
        std::cout << e.what() << '\n';  // Handle exception if stack is empty
    }

    // Try to calculate and display the average value of stack elements
    try {
        std::cout << "Average value: " << myStack.average() << '\n';
    }
    catch (const std::exception& e) {
        std::cout << e.what() << '\n';  // Handle exception if stack is empty
    }

    return 0;
}
