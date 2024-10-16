//STT: 7
//Full Name: Nguyen Minh Cuong
//Lab2 - Homework - Exercise 02
//Notes or Remarks: ....

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class BrowserHistory {
private:
    stack<string> backStack;    
    stack<string> forwardStack; 
    string currentURL;     
    
public:
    // Visit a new URL and clear the forward stack
    void visit(const string& url) {
        if (!currentURL.empty()) {
            backStack.push(currentURL);  
        }
        currentURL = url;                
        while (!forwardStack.empty()) { 
            forwardStack.pop();
        }
        cout << "Visited: " << currentURL << endl;
    }

    // Go back to the previous URL
    string back() {
        if (backStack.empty()) {
            cout << "No back history available" << endl;
            return currentURL;
        }
        forwardStack.push(currentURL);   
        currentURL = backStack.top();   
        backStack.pop();                 
        cout << "Back to: " << currentURL << endl;
        return currentURL;
    }

    // Go forward to the next URL
    string forward() {
        if (forwardStack.empty()) {
            cout << "No forward history available" << endl;
            return currentURL;
        }
        backStack.push(currentURL);       
        currentURL = forwardStack.top();  
        forwardStack.pop();               
        cout << "Forward to: " << currentURL << endl;
        return currentURL;
    }

    // Get the current URL
    string current() const {
        return currentURL;
    }
};

int main() {
    BrowserHistory browser;

    browser.visit("httt.uit.edu.vn");
    browser.visit("uit.edu.vn");
    browser.back();   
    browser.forward(); 
    browser.visit("daa.uit.edu.vn");
    browser.back();    

    return 0;
}

