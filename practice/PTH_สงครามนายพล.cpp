#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<int> parent;
vector<int> man;
vector< pair<int,int> > match;

int fight(int a, int b);

int main() {
    int N, M;
    cin >> N >> M;

    parent = vector<int>(N+1, -1);
    man = vector<int>(N+1, 0);
    match = vector< pair<int,int> >(M);
    for (int i=1; i<=N; i++) {
        //input number of soldier
        int temp;
        cin >> temp;
        man[i] = temp;
    }

    for (int i=0; i<M; i++) {
        //input number of soldier
        int a,b;
        cin >> a >> b;
        match[i] = make_pair(a,b);
    }
    // cout << "----------" << endl;
    for (int i=0; i<M; i++) {
        int a = match[i].first;
        int b = match[i].second;
        cout << fight(a,b) << endl;
    }
    return 0;
}

int find(int i) {
    if (parent[i] == -1) {
        return i;
    }
    return parent[i] = find(parent[i]);
}

void unite(int targetParent, int child, int manChild) {
    int manToTransfer = manChild/2;
    parent[child] = targetParent;
    man[targetParent] += manToTransfer;   
}

int fight(int a, int b) {
    int parentA = find(a);
    int parentB = find(b);
    if (parentA == parentB) {
        return -1;
    }

    int manA = man[parentA];
    int manB = man[parentB];

    int win;

    if (manA == manB) {
        if (parentA < parentB) {
            //parentA win
            win = parentA;
            unite(parentA, parentB, manB);
        } else {
            win = parentB;
            unite(parentB, parentA, manA);
        }
    } else if (manA < manB) {
        //parentB win
        win = parentB;
        unite(parentB, parentA, manA);
    } else {
        //parentA win
        win = parentA;
        unite(parentA, parentB, manB);
    }
    return win;
}