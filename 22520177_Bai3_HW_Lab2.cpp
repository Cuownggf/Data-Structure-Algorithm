//STT: 7
//Full Name: Nguyen Minh Cuong
//Lab2 - Homework - Exercise 03
//Notes or Remarks: ....

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> canSeePeople(vector<int>& heights) {
    int n = heights.size();
    vector<int> result(n, 0);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && heights[i] > heights[s.top()]) {
            s.pop();
            result[i]++;
        }
        if (!s.empty()) {
            result[i]++;
        }
        s.push(i);
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of people: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter the heights of each person: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    vector<int> result = canSeePeople(heights);

    cout << "The number of people each person can see is: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}


