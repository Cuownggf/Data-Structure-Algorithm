#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class BrowserHistory {
private:
    vector<string> history;
    int currentIndex;
    int methodCalls = 0; 
    string homepage;

    bool isValidURL(const string& url) {
        if (url.length() < 1 || url.length() > 20) {
            return false;
        }
        for (int i = 0; i < url.length(); i++) {
            char ch = url[i];
            if (!islower(ch) && ch != '.') {
                return false;
            }
        }
        return true;
    }

public:
    BrowserHistory(string homepage) {
        if (!isValidURL(homepage)) {
            return;
        }
        this->homepage = homepage;
        history.push_back(homepage);
        currentIndex = 0;
    }

    void visit(string url) {
        if (methodCalls >= 5000) return;

        if (!isValidURL(url) || url.find('.') == string::npos) {
            cout << "NULL.\n";
            return;
        }

        history.resize(currentIndex + 1);
        history.push_back(url);
        currentIndex++;
        methodCalls++;
    }

    string back(int steps) {
        if (methodCalls >= 5000) return history[currentIndex];

        if (currentIndex - steps < 0) {
            currentIndex = 0;
            return homepage;
        }

        currentIndex = max(0, currentIndex - steps);
        methodCalls++;
        return history[currentIndex];
    }

    string forward(int steps) {
        if (methodCalls >= 5000) return history[currentIndex];

        if (currentIndex + steps >= history.size()) {
            currentIndex = history.size() - 1;
            return history[currentIndex];
        }

        currentIndex = min((int)history.size() - 1, currentIndex + steps);
        methodCalls++;
        return history[currentIndex];
    }
};

int main() {
    string homepage;
    cout << "Enter the homepage URL: ";
    cin >> homepage;

    BrowserHistory browserHistory(homepage);

    int choice;
    string url;
    int steps;

    do {
        cout << "1. Visit a new URL\n";
        cout << "2. Go back steps\n";
        cout << "3. Go forward steps\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the URL to visit: ";
                cin >> url;
                browserHistory.visit(url);
                break;
            case 2:
                cout << "Enter the number of steps to go back: ";
                cin >> steps;
                cout << "Current URL after going back: " << browserHistory.back(steps) << endl;
                break;
            case 3:
                cout << "Enter the number of steps to go forward: ";
                cin >> steps;
                cout << "Current URL after going forward: " << browserHistory.forward(steps) << endl;
                break;
            case 4:
                cout << "Exiting browser history.\n";
                break;
            default:
                cout << "Invalid choice. Please select a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}

