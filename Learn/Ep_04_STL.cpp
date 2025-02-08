#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bits/stdc++.h>

using namespace std;

int main() {

    //1. vector
    // push_back(), pop_back(), size(), empty()
    // front(), back()
    vector<string> v = {"ant", "bird"};
    v.push_back("cat");
    // v.pop_back();
    cout << v.size() << endl;
    for (auto s : v) {
        cout << s << " ";
    }
    v[1] = "dog";
    v[v.size()-1] = "horse";
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << endl;
    }

    v.pop_back();

    cout << "=========" << endl;
    for (auto s : v) {
        cout << s << endl;
    }

    v.pop_back();
    v.pop_back();

    cout << v.empty() << endl;

    //2. list
    // push_back(), push_front(), pop_front(), pop_back()
    // empty(), front(), back()
    list<string> l = {"poppy", "lilly"};
    l.push_back("rose");
    l.push_front("sun flower");
    // l[1] = "gg";
    for (auto s : l) {
        cout << s <<endl;
    }

    cout << "-------------stack-------------------" << endl;
    //3. stack
    // push(), pop(), top(), size(), empty()
    stack<int> stack;
    stack.push(3);
    stack.push(4);
    int n = stack.size();
    while (!stack.empty()) {
        cout << stack.top() << endl;
        stack.pop();
    }

    cout << "---------------queue-----------------" << endl;
    //4. queue
    // push(), pop(), front(), size(), empty()
    queue<int> q;
    q.push(3);
    q.push(4);
    int nq = q.size();
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
    //5. deque

    cout << "---------------set-----------------" << endl;
    //6. set
    //auto sorting in ascending order
    set<int> set1 = {10,99,3,3,4};
    set1.insert(150);
    set<int, greater<int>> set2 = {50,99,3,3,4};
    set2.insert(150);
    set2.erase(150);
    vector<int> vv;
    // for (auto s : set2) {
    //     cout << s << endl;
    //     // vv.push_back(s);
    // }
    for (auto it = set1.begin(); it != set1.end(); ++it) {
        cout << *it << endl;
    }

    cout << "---------------map-----------------" << endl;
    //7. map => key, value
    // map[key] -> return value
    map<string, int> m = {{"Putter", 16}, {"Thunwa", 15}};
    m["Ming"] = 26;
    m.insert({"Jenny", 65});

    m.erase("Ming");

    cout << m["Ming"] << endl;

    for (auto pp : m) {
        //key -> pp.first
        //value -> pp.second
        cout << pp.first << ": " << pp.second << endl;
    }
 
    cout << "---------------PAIR-----------------" << endl;    
    //8. pair
    pair<int,int> pair1;
    pair1.first = 50;
    pair1.second = 25;
    cout << pair1.first << endl;
    
    // return 0;


    cout << "---------------PRIORITY QUEUE-----------------" << endl;  
    //default sorting order DESC
    priority_queue<int> pq;
    pq.push(50);
    pq.push(25);
    pq.push(300);
    pq.push(350);  

    priority_queue<int, vector<int>, greater<int>> minPq;
    minPq.push(50);
    minPq.push(25);
    minPq.push(300);
    minPq.push(350); 

    while (!minPq.empty())
    {
        cout << minPq.top() << endl;
        minPq.pop();
    }
    


}
    