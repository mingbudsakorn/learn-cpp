#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,l,c,p;
    char a,b;
    vector<tuple<char,char,int>> edges;
    set<char> set;
    cin >> n >> l >> c >> p;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        set.insert(a);
        set.insert(b);
        edges.push_back(make_tuple(a,b,-1));
    }
    for (int i = 0; i < l; i++) {
        cin >> a >> b;
        set.insert(a);
        set.insert(b);
        edges.push_back(make_tuple(a,b,1));
    }
    //Bellman's algorithm
    int inf = INT_MAX;
    map<char,int> dist;
    for(auto it: set) {
        dist.insert({it,inf});
    }
    dist['X'] = 0;

    for (int i = 0; i < set.size() -1 ; i++) {
        for(auto edge : edges) {
            char a = get<0>(edge);
            char b =  get<1>(edge);
            int w =  get<2>(edge);
            if (dist[b] > dist[a] + w) {
                dist[b] = dist[a] + w;
            }
            if (b == 'Y' && -dist[b] + p >= c) {
                cout << 'Y' << endl;
                return 0;
            }
        }
    }

    cout << 'N' << endl;

}