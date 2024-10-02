#include<iostream>
#include <string>

using namespace std;

struct Node{
    int exPireTime;   // Expiration time of the token
    string tokenId;   // Unique ID for the token
    Node *next;       // Pointer to the next node in the list

    Node(string id, int time) : exPireTime(time), tokenId(id), next(NULL) {}
};

class AuthenticationManager{
    private:
        int timeTolive;   // Time to live for each token
        Node *head;       // Head pointer for the linked list of tokens
        
        // Function to remove expired tokens
        void removeExpireTime(int currentTime){
            // While the head exists and the token at the head has expired
            while(head != NULL && head->exPireTime < currentTime){
                Node *temp = head;
                head = head->next;
                delete temp;  // Remove the expired token
            }
        }

    public:
        // Constructor to initialize timeToLive and head
        AuthenticationManager(int timeToLive) : timeTolive(timeToLive), head(NULL) {}

        // Function to generate a new token
        void generate(string tokenId, int currentTime){
            removeExpireTime(currentTime); // Clean the list of expired tokens
            // Create a new token with tokenId and its expiration time
            Node *newNode = new Node(tokenId, currentTime + timeTolive);
            
            if(head == NULL) {
                head = newNode;  // If the list is empty, set head to new token
            } else {
                Node *temp = head;
                // Traverse to the end of the list
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = newNode;  // Add new token to the end of the list
            }
        }

        // Function to renew an existing token
        void renewToken(string tokenId, int currentTime){   
            removeExpireTime(currentTime); // Remove expired tokens
            Node *temp = head;

            while(temp){
                // If tokenId matches and it's still valid
                if(temp->tokenId == tokenId && temp->exPireTime > currentTime){
                    temp->exPireTime = timeTolive + currentTime; // Renew the expiration time
                    return;
                }
                temp = temp->next;  // Move to the next token
            }
        }

        // Function to count tokens that have not expired
        int countUnexpiredTokens (int currentTime){
            removeExpireTime(currentTime); // Remove expired tokens
            Node *temp = head;
            int count = 0;
            while(temp){
                if(temp->exPireTime > currentTime) count++; // Count valid tokens
                temp = temp->next;
            }
            return count;  // Return the count of unexpired tokens
        }
};

int main(){
    int time;
    cout<<"Enter time to live for tokens: " << endl;
    cin >> time;
    AuthenticationManager auth(time);
    cout<<"null"<<endl;

    cout<<"Enter 'generate' to create a new token." << endl;
    cout<<"Enter 'renew' to renew an existing token." << endl;
    cout<<"Enter 'counttoken' to count unexpired tokens." << endl;
    cout<<"Enter 'exit' to exit the loop!" << endl;
    cout<<"Invalid input, please enter again!" << endl;

    string enter;
    cin.ignore();  // Ignore the leftover newline character
    while(true){
        cout<<"Enter command: ";
        getline(cin, enter);

        if(enter == "generate"){
            string tokenId;
            cout<<"Enter tokenId: " << endl;
            getline(cin, tokenId);  // Get token ID from user
            
            int currentTime;
            cout<<"Enter currentTime: " << endl;
            cin >> currentTime;
            cin.ignore();  // Ignore the leftover newline character

            auth.generate(tokenId, currentTime);
            cout<<"null" << endl;
        }
        else if(enter == "renew"){
            string tokenId;
            cout<<"Enter tokenId: " << endl; 
            getline(cin, tokenId);
            
            int currentTime;
            cout<<"Enter currentTime: " << endl;
            cin >> currentTime;
            cin.ignore();
            auth.renewToken(tokenId, currentTime);
            cout<<"null"<<endl;
        }
        else if(enter == "counttoken"){
            int currentTime;
            cout<<"Enter currentTime: ";
            cin >> currentTime;
            cin.ignore();
            
            int count = auth.countUnexpiredTokens(currentTime);
            cout<<"Number of unexpired tokens: "<< count << endl;
        }
        else if(enter == "exit") break;  // Exit the loop
        else cout<<"Invalid input, please try again!" << endl;
    }

    return 0;
}

