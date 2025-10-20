/**
 * YZM2031 - Lab Assignment 1
 * Problem 2: Singly Linked List Implementation
 * 
 * Student Name: [Yunus Emre Yılmaz]
 * Student ID: [24018015]
 * 
 * Instructions: Implement the TODO sections below
 */

#include <iostream>
using namespace std;

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    // Constructor
    LinkedList() : head(nullptr), size(0) {}

    // Destructor
    ~LinkedList() {
        // TODO: Free all nodes
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;                 
            current = nextNode;             
        }
        // 1. Traverse the list
        // 2. Delete each node
        // Hint: Save the next pointer before deleting current node
        
    }

    // Insert at beginning
    void insertFront(int value) {
        // TODO: Implement insertFront
        // 1. Create a new node
        Node* newNode = new Node(value);
        // 2. Set new node's next to current head
        newNode->next = head;
        // 3. Update head to new node
        head = newNode;
        // 4. Increment size
        size++;
    }

    // Insert at end
    void insertBack(int value) {
        // TODO: Implement insertBack
        // 1. Create a new node
        Node* newNode = new Node(value);
        // 2. If list is empty, set head to new node
        if (head == nullptr) {
            head = newNode;
        }
        // 3. Otherwise, traverse to the last node
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
        // 4. Set last node's next to new node
        current->next = newNode;
        // 5. Increment size
        size++;
        
    }

    // Insert at specific position
    void insertAt(int index, int value) {
        // TODO: Implement insertAt
        // 1. Validate index (0 <= index <= size){
        if (index < 0 || index > size) {
            cout << "Invalid index!" << endl;
            return;
        }
        // 2. If index is 0, call insertFront
         if (index == 0) {
            insertFront(value);
            return;
        }
        // 3. Otherwise, traverse to node at index-1
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        // 4. Create new node
        Node* newNode = new Node(value);
        // 5. Link new node between current node and next node
        newNode->next = current->next;
        current->next = newNode;
        // 6. Increment size
        size++;
    }

    // Delete first element
    void deleteFront() {
        // TODO: Implement deleteFront
        // 1. Check if list is empty
         if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        // 2. Save head pointer
        Node* temp = head;
        // 3. Move head to next node
        head = head->next; 
        // 4. Delete old head
        delete temp; 
        // 5. Decrement size
        size--;    
    }

    // Delete last element
    void deleteBack() {
        // TODO: Implement deleteBack        
        // 1. Check if list is empty
            if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        // 2. If only one node, delete it and set head to nullptr
         if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } 
        // 3. Otherwise, traverse to second-to-last node
        else {
            // ikinci son düğüme kadar git
            Node* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
        // 4. Delete last node
            delete current->next;
        // 5. Set second-to-last node's next to nullptr
            current->next = nullptr;
        }
        // 6. Decrement size
        size--;
    }

    // Search for value and return index (-1 if not found)
    int search(int value) {
        // TODO: Implement search
        // 1. Traverse the list
        // 2. Keep track of index
        // 3. If value found, return index
        // 4. If not found, return -1
        Node* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->data == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;  // Placeholder
    }

    // Reverse the list
    void reverse() {
        // TODO: Implement reverse
        // 1. Use three pointers: prev, current, next
        // 2. Initialize prev = nullptr, current = head
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        // 3. Traverse the list:
        //    - Save next node
        //    - Reverse current node's pointer
        //    - Move prev and current forward
        while (current != nullptr) {
            next = current->next;   
            current->next = prev;   
            prev = current;         
            current = next;         
        }
        // 4. Update head to prev
        head = prev;
    }

    // Print all elements
    void print() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " → ";
            }
            current = current->next;
        }
        cout << " → nullptr" << endl;
    }

    // Return size
    int getSize() const {
        return size;
    }
};

// Test cases
int main() {
    cout << "=== Testing Linked List ===" << endl << endl;

    LinkedList list;

    // Test 1: Insert operations
    cout << "Test 1: Insert operations" << endl;
    list.insertFront(10);
    list.insertFront(5);
    list.insertBack(20);
    list.insertBack(25);
    cout << "List: ";
    list.print();  // Expected: 5 → 10 → 20 → 25 → nullptr
    cout << "Size: " << list.getSize() << endl;
    cout << endl;

    // Test 2: Insert at position
    cout << "Test 2: Insert 15 at index 2" << endl;
    list.insertAt(2, 15);
    cout << "List: ";
    list.print();  // Expected: 5 → 10 → 15 → 20 → 25 → nullptr
    cout << endl;

    // Test 3: Search
    cout << "Test 3: Search operations" << endl;
    cout << "Index of 15: " << list.search(15) << endl;  // Expected: 2
    cout << "Index of 100: " << list.search(100) << endl;  // Expected: -1
    cout << endl;

    // Test 4: Delete operations
    cout << "Test 4: Delete front" << endl;
    list.deleteFront();
    cout << "List: ";
    list.print();  // Expected: 10 → 15 → 20 → 25 → nullptr
    cout << endl;

    cout << "Test 5: Delete back" << endl;
    list.deleteBack();
    cout << "List: ";
    list.print();  // Expected: 10 → 15 → 20 → nullptr
    cout << endl;

    // Test 6: Reverse
    cout << "Test 6: Reverse list" << endl;
    list.reverse();
    cout << "List: ";
    list.print();  // Expected: 20 → 15 → 10 → nullptr
    cout << endl;

    cout << "=== All tests completed ===" << endl;

    return 0;
}

