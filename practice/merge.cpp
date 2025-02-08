#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M, Q, a, b, k;
    int temp;
    
    cin >> N;
    cin >> M;
    cin >> Q;
    vector<pair<int,int>> xDist(N);
    vector<pair<int,int>> yDist(M);

    for(int i=0; i<N; i++){
        cin >> xDist[i].first;
    }
    for(int i=0; i<N; i++){
        cin >> xDist[i].second;
    }

    for(int i=0; i<M; i++){ 
        cin >> yDist[i].first;
    }
    for(int i=0; i<M; i++){
        cin >> yDist[i].second;
    }

    for(int i=0; i<Q; i++){
        cin >> 
    }

    //use map to store key=(a,b) value=vector if k
    
}