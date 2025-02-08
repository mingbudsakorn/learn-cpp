#include <bits/stdc++.h>
using namespace std;

void move(int &boxHeight, int &Hole, int times){
    for(int i=0; i<times; i++){
        Hole--;
        if(Hole==0){
            Hole=boxHeight;
        }
    }
}
int main(){
    int shortest = 1000;
    int n;
    cin >> n;
    vector<int> boxHeight;
    vector<int> Hole;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        boxHeight.push_back(a);
    }
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        Hole.push_back(a);
        if(boxHeight[i]<Hole[i]){
            cout << "no";
            return 0;
        }
    }
    vector<int> holeCopy = Hole;
    int hooly;
    for(int i=0; i<n; i++){
        int temp = 0;
        Hole = holeCopy;
        for( int j=0; j!=i; j++){
            while(Hole[j] != Hole[i]){
                move(boxHeight[j], Hole[j], 1);
                temp++;
            }
        }
        if(shortest > temp){
            if(temp != 0){
                shortest = temp;
            }
            hooly = i; 
        }
    } 
    cout << shortest << " " << hooly;
}