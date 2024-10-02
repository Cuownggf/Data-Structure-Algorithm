#include<iostream>
#include<string>
using namespace std;

class Node{
   public: 
    string url;
    Node *prev;
    Node *next;

    Node(string url) : url(url), prev(NULL), next(NULL) {}
};

class BrowserHistory{
    private:
        Node *head;
        Node *current;
        Node *tail;
    
    public:
        BrowserHistory(string homePage){
            head = new Node(homePage);
            current = head;
            tail = head;
        }

        void visit(string newUrl){
            Node *newNode = new Node(newUrl);
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
        }

        string back(int number){
            if(current == head){
                cout << head->url;
            } else {
                while(current->prev != NULL && number > 0){
                    current = current->prev;
                    number--;
                }
                return current->url;
            }
        }

        string forward(int number){
            if(current == tail){
                cout << tail->url;
            } else {
                while(current->next != NULL && number > 0){
                    current = current->next;
                    number--;
                }
                return current->url;
            }
        }

};

int main(){
    string homePage;
    cout << "Enter home page: " << endl;
    getline(cin, homePage);

    BrowserHistory browser(homePage);

    string command;
    while(1){
        cout << "Enter commands: visit, back, forward, exit." << endl;
        cin >> command;
        
        if(command == "visit"){
            string url;
            cout << "Enter url: " << endl;
            cin.ignore();
            getline(cin, url);
            browser.visit(url);
            cout << "null" << endl;
        } else if (command == "back") {
            int number;
            cout << "Enter number of steps back: " << endl;
            cin >> number;
            cout << "Currently on page: " << endl;
            cin.ignore();
            cout << browser.back(number) << endl;
        } else if (command == "forward") {
            int number;
            cout << "Enter number of steps forward: " << endl;
            cin >> number;
            cout << "Currently on page: " << endl;
            cin.ignore();
            cout << browser.forward(number) << endl;
        } else if (command == "exit") {
            break;
        } else {
            cout << "Invalid command!" << endl;
        }

    }

    return 0;
}
