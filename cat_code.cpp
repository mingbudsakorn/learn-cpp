#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	cin >> a >> b;
	cin.ignore();
    map<string, int> h;
	for(int i=1; i<=a; i++){
		string temp;
		getline(cin,temp);
        h[temp] = i;
	}
	int n;
	cin >> n;
	cin.ignore();
	vector< vector<int> > ans(n);
    priority_queue <int, vector<int>, greater<int> > answer;
	for(int i=0; i<n; i++){
		int A;
		string B;
		cin >> A;
		cin.ignore();
		getline(cin,B);
        for(int l=0; l<A-b; l++){
            if(h.count(B.substr(l,b)) > 0){
                answer.push(h[B.substr(l,b)]);
            }
		}

        if (answer.empty()) {
            cout << "OK\n";
        }
        else {
            while (!answer.empty()){
                cout << answer.top() << " ";
                answer.pop();
            }
            cout << "\n";
        }
        
	}

	// for(int i=0; i<n; i++){
	// 	if(!ans[i].size()){
	// 		cout << "OK" << endl;
	// 		continue;
	// 	}
	// 	for(int j=0; j<ans[i].size(); j++){
	// 		cout << ans[i][j]+1 << " ";
	// 	}
	// 	cout << endl;		
	// }
}