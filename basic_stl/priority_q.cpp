#include <iostream>
#include <queue>
using namespace std;

int main() {
    //Max heap
    priority_queue<int> pq;
    // empty(), size(), top(), push(), pop()
    // swap(), emplace()
    pq.push(23);
    pq.push(21);
    pq.push(15);
    pq.push(99);
    while (pq.size()!=0){
        cout << pq.top() << endl;
        pq.pop();
    }

    cout << "--------------------------" << endl;
    //Min heap
    priority_queue<int,vector<int>,greater<int>> minpq;
    minpq.push(23);
    minpq.push(21);
    minpq.push(15);
    minpq.push(99);
    while (minpq.size()!=0){
        cout << minpq.top() << endl;
        minpq.pop();
    }

    cout << "--------------------------" << endl;
    //string
    priority_queue<string,vector<string>,greater<string>> pqs;
    // empty(), size(), top(), push(), pop()
    // swap(), emplace()
    pqs.push("Ming");
    pqs.push("Mint");
    pqs.push("Mei");
    pqs.push("Kao");
    while (pqs.size()!=0){
        cout << pqs.top() << endl;
        pqs.pop();
    }
}