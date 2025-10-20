/**
 * YZM2031 - Lab Assignment 1
 * Problem 3: Stack-Based Expression Evaluator
 * 
 * Student Name: [Yunus Emre Yılmaz]
 * Student ID: [24018015]
 * 
 * Instructions: Implement the TODO sections below
 */

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

/**
 * Evaluates a postfix expression
 * 
 * Algorithm:
 * 1. Create an empty stack
 * 2. Scan the expression from left to right:
 *    - If the element is a number, push it to the stack
 *    - If the element is an operator:
 *      a. Pop two operands from stack (second operand first, then first operand)
 *      b. Perform the operation
 *      c. Push result back to stack
 * 3. The final result is the only element left in the stack
 */
int evaluatePostfix(const string& expression) {
    // TODO: Implement postfix evaluation
    // 
    // Hint: Use stringstream to parse the expression
    // Example:
    //   stringstream ss(expression);
    //   string token;
    //   while (ss >> token) {
    //       // Process each token
    //   }
    //
    // Hint: Check if token is an operator
    //   if (token == "+" || token == "-" || token == "*" || token == "/")
    //
    // Hint: Convert string to integer
    //   int num = stoi(token);
    
    stack<int> s;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int var2 = s.pop();
            int var1 = s.pop();

            int result = 0;
            if (token == "+") result = var1 + var2;
            else if (token == "-") result = var1 - var2;
            else if (token == "*") result = var1 * var2;
            else if (token == "/") {
                if (var2 == 0) {
                    throw runtime_error("Division by zero");
                }
                result = var1 / var2;
            }
            s.push(result);
        } 
        else {
            int num = stoi(token);
            s.push(num);
        }
    }
    return s.top();
}

// Test cases
int main() {
    cout << "=== Testing Postfix Expression Evaluator ===" << endl << endl;

    // Test 1: Simple addition
    cout << "Test 1: \"3 4 +\"" << endl;
    cout << "Result: " << evaluatePostfix("3 4 +") << endl;
    cout << "Expected: 7" << endl << endl;

    // Test 2: Expression with multiplication
    cout << "Test 2: \"3 4 + 2 *\"" << endl;
    cout << "Result: " << evaluatePostfix("3 4 + 2 *") << endl;
    cout << "Expected: 14" << endl << endl;

    // Test 3: Complex expression
    cout << "Test 3: \"5 1 2 + 4 * + 3 -\"" << endl;
    cout << "Result: " << evaluatePostfix("5 1 2 + 4 * + 3 -") << endl;
    cout << "Expected: 14" << endl << endl;

    // Test 4: Very complex expression
    cout << "Test 4: \"15 7 1 1 + - / 3 * 2 1 1 + + -\"" << endl;
    cout << "Result: " << evaluatePostfix("15 7 1 1 + - / 3 * 2 1 1 + + -") << endl;
    cout << "Expected: 5" << endl << endl;

    // Test 5: Subtraction
    cout << "Test 5: \"10 5 -\"" << endl;
    cout << "Result: " << evaluatePostfix("10 5 -") << endl;
    cout << "Expected: 5" << endl << endl;

    // Test 6: Division
    cout << "Test 6: \"20 4 /\"" << endl;
    cout << "Result: " << evaluatePostfix("20 4 /") << endl;
    cout << "Expected: 5" << endl << endl;

    cout << "=== All tests completed ===" << endl;

    return 0;
}

