#include <bits/stdc++.h>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

int main()
{
    // stack
    stack<int> stack;
    stack.push(21);
    stack.push(22);
    stack.push(23);
    stack.push(24);
    stack.push(25);
    for(int i = 1; i <=10;i++){
        stack.push(i);
    }
    while (!stack.empty()){
        cout << stack.top() << endl;
        stack.pop();
    }
    
    // queue
    queue<int> queue;

    queue.push(30);
    queue.push(301);
    queue.push(302);
    queue.push(3023);
    queue.push(304);
    
    while (!queue.empty()){
        cout << queue.front() << endl;
        queue.pop();
    }

    //unordered_map
    unordered_map<char, int> err={{'a',10},{'b',3},{'c',4}};
    err['z']=20;
    err['h']=36;
    for(pair<char,int>eon : err) {
        cout << eon.first<<" "<<eon.second << endl;
    }

}