/**
 * YZM2031 - Lab Assignment 1
 * Problem 1: Dynamic Array Implementation
 * 
 * Student Name: [Yunus Emre Yılmaz]
 * Student ID: [24018015]
 * 
 * Instructions: Implement the TODO sections below
 */

#include <iostream>
#include <stdexcept>
using namespace std;

class DynamicArray {
private:
    int* data;
    int size;        // Current number of elements
    int capacity;    // Current capacity of array

    // Helper function to resize the array when full
    void resize() {
        // TODO: Implement resize function
        // 1. Double the capacity
        capacity = capacity*2;
        // 2. Create a new array with new capacity
        int* newArray = new int[capacity];
        // 3. Copy all elements from old array to new array
        for (int i = 0; i < size; i++){
            newArray[i] = data[i];   
        }
        // 4. Delete old array
        delete[] data;
        // 5. Update data pointer to point to new array
        data = newArray;
    }

public:
    // Constructor
    DynamicArray(int initialCapacity = 10) {
        // TODO: Initialize the array
        // 1. Set capacity to initialCapacity
        capacity = initialCapacity;
        // 2. Set size to 0
        size = 0;
        // 3. Allocate memory for data array
        data = new int[capacity];
        
    }

    // Destructor
    ~DynamicArray() {
        // TODO: Free allocated memory
        delete[] data;
        data = nullptr;
    }

    // Add element to end
    void add(int value) {
        // TODO: Implement add function
        // 1. Check if array is full (size >= capacity)
       if (size >= capacity) {
            resize();
       }
        // 2. Add value at index size
        data[size] = value;
        // 3. Increment size
        size++;
    }

    // Insert at specific position
    void insert(int index, int value) {
        // TODO: Implement insert function
        // 1. Validate index (0 <= index <= size)
        if (index < 0 || index > size) {
            return ;
        }
        else{
            // 2. Check if array is full, resize if needed
            if (size >= capacity) {
                resize();
            }
            // 3. Shift elements from index to the right
            for (int i = size; i > index; i--) {
                data[i] = data[i-1];
            }
            // 4. Insert value at index
            data[index] = value;
            // 5. Increment size
            size++;
        }
    }

    // Remove element at index
    void remove(int index) {
        // TODO: Implement remove function
        // 1. Validate index (0 <= index < size)
        if (index < 0 || index >= size) {
            return;
        }
        else{
            // 2. Shift elements from index+1 to the left
            for (int i = index; i < size - 1; i++) {
                data[i] = data[i + 1];
            }
            // 3. Decrement size
            size--;
        }
    }

    // Get element at index
    int get(int index) const {
        // TODO: Implement get function
        // 1. Validate index (0 <= index < size)
         if (index < 0 || index >= size) {
            return 0;
        }
        else{
            // 2. Return element at index
            return data[index];
        }
    }

    // Return current size
    int getSize() const {
        return size;
    }

    // Return current capacity
    int getCapacity() const {
        return capacity;
    }

    // Print all elements
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i];
            if (i < size - 1) cout << " ";
        }
        cout << endl;
    }
};

// Test cases
int main() {
    cout << "=== Testing Dynamic Array ===" << endl << endl;

    DynamicArray arr(5);

    // Test 1: Add elements
    cout << "Test 1: Add elements" << endl;
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);
    arr.add(50);
    cout << "Array: ";
    arr.print();  // Expected: 10 20 30 40 50
    cout << "Size: " << arr.getSize() << ", Capacity: " << arr.getCapacity() << endl;
    // Expected: Size: 5, Capacity: 5
    cout << endl;

    // Test 2: Trigger resize
    cout << "Test 2: Trigger resize by adding 6th element" << endl;
    arr.add(60);
    cout << "Array: ";
    arr.print();  // Expected: 10 20 30 40 50 60
    cout << "Size: " << arr.getSize() << ", Capacity: " << arr.getCapacity() << endl;
    // Expected: Size: 6, Capacity: 10
    cout << endl;

    // Test 3: Insert
    cout << "Test 3: Insert 25 at index 2" << endl;
    arr.insert(2, 25);
    cout << "Array: ";
    arr.print();  // Expected: 10 20 25 30 40 50 60
    cout << endl;

    // Test 4: Remove
    cout << "Test 4: Remove element at index 0" << endl;
    arr.remove(0);
    cout << "Array: ";
    arr.print();  // Expected: 20 25 30 40 50 60
    cout << endl;

    // Test 5: Get
    cout << "Test 5: Get element at index 2" << endl;
    cout << "Element at index 2: " << arr.get(2) << endl;  // Expected: 30
    cout << endl;

    cout << "=== All tests completed ===" << endl;

    return 0;
}

