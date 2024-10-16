//STT: 7
//Full Name: Nguyen Minh Cuong
//Lab2 - Homework - Exercise 01
//Notes or Remarks: ....

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class TowerOfHanoi {
private:
    stack<int> A, B, C;  // Stacks representing the towers
    int numDisks;

public:
    TowerOfHanoi(int n) : numDisks(n) {
        for (int i = n; i >= 1; i--) {
            A.push(i);
        }
    }

    // Function to move disks and print the current state
    void moveDisks(int n, char from, char to, char aux) {
        if (n == 1) {
            cout << from << " -> " << to << endl;
            moveTopDisk(from, to);
            displayTowers();
            return;
        }
        moveDisks(n - 1, from, aux, to);
        cout << from << " -> " << to << endl;
        moveTopDisk(from, to);
        displayTowers();
        moveDisks(n - 1, aux, to, from);
    }

    // Function to move the top disk between towers
    void moveTopDisk(char from, char to) {
        stack<int>* fromTower;
        stack<int>* toTower;

        switch (from) {
            case 'A': fromTower = &A; break;
            case 'B': fromTower = &B; break;
            case 'C': fromTower = &C; break;
        }
        switch (to) {
            case 'A': toTower = &A; break;
            case 'B': toTower = &B; break;
            case 'C': toTower = &C; break;
        }

        // Move the top disk
        int disk = fromTower->top();
        fromTower->pop();
        toTower->push(disk);
    }

    // Function to display the current state of all towers
    void displayTowers() {
        cout << "====================" << endl;
        cout << "A Tower\nSTACK = "; displayStack(A);
        cout << "B Tower\nSTACK = "; displayStack(B);
        cout << "C Tower\nSTACK = "; displayStack(C);
        cout << "====================\n" << endl;
    }

    // Function to display a stack
    void displayStack(stack<int> tower) {
        vector<int> temp;
        while (!tower.empty()) {
            temp.push_back(tower.top());
            tower.pop();
        }
        cout << "< ";
        for (int i = temp.size() - 1; i >= 0; i--) {
            cout << temp[i] << " ";
        }
        cout << ">" << endl;
    }

    void printDemoHeader() {
        cout << "======== Demo Stack ========\n";
        cout << "0. Creating Tower.\n";
        cout << "1. A -> B\n";
        cout << "2. B -> A\n";
        cout << "3. B -> C\n";
        cout << "4. C -> B\n";
        cout << "5. C -> A\n";
        cout << "6. A -> C\n";
        cout << "============================\n";
    }
};

int main() {
    int numDisks;

    cout << "Enter the number of disks: ";
    cin >> numDisks;

    TowerOfHanoi tower(numDisks);

    tower.printDemoHeader();

    cout << "Initial state of towers:" << endl;
    tower.displayTowers();

    // Solve the Tower of Hanoi puzzle
    tower.moveDisks(numDisks, 'A', 'C', 'B');

    return 0;
}


