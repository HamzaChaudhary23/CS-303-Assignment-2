#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <cstddef>
#include <stdexcept>
#include <iostream>

template <typename Item_Type>
class Single_Linked_List {
private:
    struct Node {
        Item_Type data;
        Node* next;

        explicit Node(const Item_Type& item) : data(item), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    std::size_t num_items;

public:
    Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}
    ~Single_Linked_List();

    // -------------------- push_front --------------------
    void push_front(const Item_Type& item);

    // -------------------- push_back --------------------
    void push_back(const Item_Type& item);

    // -------------------- pop_front --------------------
    void pop_front();

    // -------------------- pop_back --------------------
    void pop_back();

    // -------------------- front and back --------------------
    Item_Type& front();
    const Item_Type& front() const;
    Item_Type& back();
    const Item_Type& back() const;

    // -------------------- empty --------------------
    bool empty() const noexcept;

    // -------------------- insert --------------------
    void insert(std::size_t index, const Item_Type& item);

    // -------------------- remove --------------------
    bool remove(std::size_t index);

    // -------------------- find --------------------
    std::size_t find(const Item_Type& item) const;

    // -------------------- size --------------------
    std::size_t size() const noexcept { return num_items; }

    // -------------------- display --------------------
    void display(std::ostream& os = std::cout) const;
};

// -------------------- Destructor --------------------
template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (!empty()) pop_front();
}

// -------------------- push_front --------------------
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node* new_node = new Node(item);
    if (empty()) {
        head = tail = new_node;
    }
    else {
        new_node->next = head;
        head = new_node;
    }
    ++num_items;
}

// -------------------- push_back --------------------
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node* new_node = new Node(item);
    if (empty()) {
        head = tail = new_node;
    }
    else {
        tail->next = new_node;
        tail = new_node;
    }
    ++num_items;
}

// -------------------- pop_front --------------------
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    if (empty()) throw std::runtime_error("pop_front() on empty list");

    Node* old_head = head;
    head = head->next;
    delete old_head;
    --num_items;

    if (!head) tail = nullptr;
}

// -------------------- pop_back --------------------
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    if (empty()) throw std::runtime_error("pop_back() on empty list");

    if (head == tail) {
        delete head;
        head = tail = nullptr;
    }
    else {
        Node* current = head;
        while (current->next != tail) current = current->next;
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    --num_items;
}

// -------------------- front and back --------------------
template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::front() {
    if (empty()) throw std::runtime_error("front() on empty list");
    return head->data;
}
template <typename Item_Type>
const Item_Type& Single_Linked_List<Item_Type>::front() const {
    if (empty()) throw std::runtime_error("front() on empty list");
    return head->data;
}
template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::back() {
    if (empty()) throw std::runtime_error("back() on empty list");
    return tail->data;
}
template <typename Item_Type>
const Item_Type& Single_Linked_List<Item_Type>::back() const {
    if (empty()) throw std::runtime_error("back() on empty list");
    return tail->data;
}

// -------------------- empty --------------------
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const noexcept {
    return num_items == 0;
}

// -------------------- insert --------------------
template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(std::size_t index, const Item_Type& item) {
    if (index == 0) {
        push_front(item);
        return;
    }
    if (index >= num_items) {
        push_back(item);
        return;
    }

    Node* current = head;
    for (std::size_t i = 0; i < index - 1; ++i) current = current->next;

    Node* new_node = new Node(item);
    new_node->next = current->next;
    current->next = new_node;
    ++num_items;
}

// -------------------- remove --------------------
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(std::size_t index) {
    if (index >= num_items) return false;

    if (index == 0) {
        pop_front();
        return true;
    }

    Node* current = head;
    for (std::size_t i = 0; i < index - 1; ++i) current = current->next;

    Node* to_remove = current->next;
    current->next = to_remove->next;
    if (to_remove == tail) tail = current;

    delete to_remove;
    --num_items;
    return true;
}

// -------------------- find --------------------
template <typename Item_Type>
std::size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    Node* current = head;
    std::size_t index = 0;

    while (current) {
        if (current->data == item) return index;
        current = current->next;
        ++index;
    }
    return num_items;
}

// -------------------- display --------------------
template <typename Item_Type>
void Single_Linked_List<Item_Type>::display(std::ostream& os) const {
    Node* current = head;
    os << "List: ";
    while (current) {
        os << current->data << " ";
        current = current->next;
    }
    os << "(size: " << num_items << ")\n";
}

#endif // SINGLE_LINKED_LIST_H
