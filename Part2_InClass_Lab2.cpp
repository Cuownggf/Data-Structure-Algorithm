//STT: 7
//Full Name: Nguyễn Minh Cường
//InClass - Part 2
//Notes or Remarks: ......

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() {
        head = tail = NULL;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node();
        if (!newNode) {
            cout << "Queue overflow!" << endl;
            return;
        }
        newNode->data = value;
        newNode->next = NULL;

        if (tail == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        cout << value << " enqueued to the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow! Cannot dequeue." << endl;
            return;
        }

        Node* temp = head;
        cout << head->data << " dequeued from the queue." << endl;
        head = head->next;

        if (head == NULL) {
            tail = NULL;
        }

        delete temp;
    }

    void printhead() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "head element is: " << head->data << endl;
    }

    void printtail() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "tail element is: " << tail->data << endl;
    }
};

int main() {
    Queue queue;
    int choice, value;

    while (true) {
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Print head Element\n";
        cout << "4. Print tail Element\n";
        cout << "5. Check if Queue is Empty\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            queue.enqueue(value);
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.printhead();
            break;
        case 4:
            queue.printtail();
            break;
        case 5:
            if (queue.isEmpty()) {
                cout << "Queue is empty." << endl;
            } else {
                cout << "Queue is not empty." << endl;
            }
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}

