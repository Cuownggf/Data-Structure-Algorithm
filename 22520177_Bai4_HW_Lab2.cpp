#include <iostream>

using namespace std;

struct Node {
    int index; 
    Node* next; 

    Node(int i) : index(i), next(NULL) {}
};

class Stack {
private:
    Node* topNode; 

public:
    Stack() : topNode(NULL) {}

    void push(int index) {
        Node* newNode = new Node(index);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (topNode) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    int top() {
        if (topNode) {
            return topNode->index;
        }
        return -1;
    }

    bool isEmpty() {
        return topNode == NULL;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// Function to calculate the minimum coins needed to buy all fruits
int minimumCoins(int prices[], int n) {
    Stack stack;

    for (int i = 0; i < n; ++i) {
        stack.push(i);
    }

    for (int i = (n - 1) / 2; i > 0; --i) {
        int minPriceIndex = -1;
        int minPrice = INT_MAX;

        for (int j = i; j < 2 * i + 1 && j < n; ++j) {
            if (prices[j] < minPrice) {
                minPrice = prices[j];
                minPriceIndex = j;
            }
        }

        prices[i - 1] += prices[minPriceIndex];
    }

    return prices[0];
}

int main() {

    int prices[] = {3, 1, 2};  // Example 1
    int n = sizeof(prices) / sizeof(prices[0]);
    int result = minimumCoins(prices, n);
    cout << "Example 1 input: {3, 1, 2}" << endl;
    cout << "Minimum coins required: " << result << endl;
    
    int prices2[] = {1, 10, 1, 1};  // Example 2
    int k = sizeof(prices2) / sizeof(prices2[0]);
    int result2 = minimumCoins(prices2, k);
    cout << "Example 2 input: {1, 10, 1, 1}" << endl;
    cout << "Minimum coins required: " << result2 << endl;
    
    int prices3[] = {26, 18, 6, 12, 49, 7, 45, 45};  // Example 3
    int l = sizeof(prices3) / sizeof(prices3[0]);
    int result3 = minimumCoins(prices3, l);
    cout << "Example 3 input: {26, 18, 6, 12, 49, 7, 45, 45}" << endl;
    cout << "Minimum coins required: " << result3 << endl;

    return 0;
}
