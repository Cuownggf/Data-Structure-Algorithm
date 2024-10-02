//STT: 7
//Full Name: Nguyễn Minh Cường
//InClass - Part 1
//Notes or Remarks: ......

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(int value) {
        Node* newNode = new Node();
        if (!newNode) {
            cout << "Stack overflow!" << endl;
            return;
        }
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << " pushed onto the stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        cout << top->data << " popped from the stack." << endl;
        top = top->next;
        delete temp;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Top element is: " << top->data << endl;
    }
};

int main() {
    Stack stack;
    int choice, value;

    while (true) {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if Stack is Empty\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            stack.peek();
            break;
        case 4:
            if (stack.isEmpty()) {
                cout << "Stack is empty." << endl;
            } else {
                cout << "Stack is not empty." << endl;
            }
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}

