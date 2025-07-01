#include "Single_Linked_List.h"
#include <iostream>

int main()
{
    Single_Linked_List<int> list;

    std::cout << "=== Testing Single_Linked_List (With Demo main file) ===\n";

    // --------------------------------------------------
    // 1. push_front
    // --------------------------------------------------
    std::cout << "\n[ push_front ]" << std::endl;
    list.push_front(5);   // List: 5
    list.push_front(3);   // List: 3 5
    list.display();

    // --------------------------------------------------
    // 2. push_back
    // --------------------------------------------------
    std::cout << "\n[ push_back ]" << std::endl;
    list.push_back(10);   // List: 3 5 10
    list.push_back(20);   // List: 3 5 10 20
    list.display();

    // --------------------------------------------------
    // 3. pop_front
    // --------------------------------------------------
    std::cout << "\n[ pop_front ]" << std::endl;
    list.pop_front();     // Removes 3
    list.display();

    // --------------------------------------------------
    // 4. pop_back
    // --------------------------------------------------
    std::cout << "\n[ pop_back ]" << std::endl;
    list.pop_back();      // Removes 20
    list.display();

    // --------------------------------------------------
    // 5. front & back
    // --------------------------------------------------
    std::cout << "\n[ front & back ]" << std::endl;
    std::cout << "Front: " << list.front() << std::endl; // Should be 5
    std::cout << "Back : " << list.back() << std::endl; // Should be 10

    // --------------------------------------------------
    // 6. empty
    // --------------------------------------------------
    std::cout << "\n[ empty ]" << std::endl;
    std::cout << "Is list empty? " << (list.empty() ? "Yes" : "No") << std::endl;

    // --------------------------------------------------
    // 7. insert
    // --------------------------------------------------
    std::cout << "\n[ insert ]" << std::endl;
    list.insert(1, 99);   // Insert 99 at index 1  -> 5 99 10
    list.display();

    // --------------------------------------------------
    // 8. remove
    // --------------------------------------------------
    std::cout << "\n[ remove ]" << std::endl;
    bool removed = list.remove(1); // Remove 99
    std::cout << "Removed index 1? " << (removed ? "Yes" : "No") << std::endl;
    list.display();

    // --------------------------------------------------
    // 9. find
    // --------------------------------------------------
    std::cout << "\n[ find ]" << std::endl;
    std::cout << "find(10): index = " << list.find(10) << std::endl; // Should be 1
    std::cout << "find(42): index = " << list.find(42) << " (size => not found)" << std::endl;

    return 0;
}