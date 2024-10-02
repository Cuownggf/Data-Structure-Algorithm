//STT: 7
//Full Name: Nguyễn Minh Cường
//Homework 01 - Exercise 01
//Notes or Remarks: ......

#include<iostream>
#include <string>

using namespace std;

struct Node{
    int exPireTime;  
    string tokenId;   
    Node *next;     

    Node(string id, int time) : exPireTime(time), tokenId(id), next(NULL) {}
};

class AuthenticationManager{
    private:
        int timeTolive; 
        Node *head;     
        
        void removeExpireTime(int currentTime){
            while(head != NULL && head->exPireTime < currentTime){
                Node *temp = head;
                head = head->next;
                delete temp;
            }
        }

    public:
        AuthenticationManager(int timeToLive) : timeTolive(timeToLive), head(NULL) {}

        void generate(string tokenId, int currentTime){
            removeExpireTime(currentTime);
            Node *newNode = new Node(tokenId, currentTime + timeTolive);
            
            if(head == NULL) {
                head = newNode;
            } else {
                Node *temp = head;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void renewToken(string tokenId, int currentTime){   
            removeExpireTime(currentTime);
            Node *temp = head;

            while(temp){
                if(temp->tokenId == tokenId && temp->exPireTime > currentTime){
                    temp->exPireTime = timeTolive + currentTime; 
                    return;
                }
                temp = temp->next; 
            }
        }

        int countUnexpiredTokens (int currentTime){
            removeExpireTime(currentTime);
            Node *temp = head;
            int count = 0;
            while(temp){
                if(temp->exPireTime > currentTime) count++;
                temp = temp->next;
            }
            return count; 
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
    cout<<"Enter 'countUnexpiredTokens' to count unexpired tokens." << endl;
    cout<<"Enter 'exit' to exit the loop!" << endl;
    cout<<"Invalid input, please enter again!" << endl;

    string enter;
    cin.ignore();
    while(true){
        cout<<"Enter command: ";
        getline(cin, enter);

        if(enter == "generate"){
            string tokenId;
            cout<<"Enter tokenId: " << endl;
            getline(cin, tokenId);
            
            int currentTime;
            cout<<"Enter currentTime: " << endl;
            cin >> currentTime;
            cin.ignore(); 

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
        else if(enter == "countUnexpiredTokens"){
            int currentTime;
            cout<<"Enter currentTime: ";
            cin >> currentTime;
            cin.ignore();
            
            int count = auth.countUnexpiredTokens(currentTime);
            cout<<"Number of unexpired tokens: "<< count << endl;
        }
        else if(enter == "exit") break;
        else cout<<"Invalid input, please try again!" << endl;
    }

    return 0;
}
