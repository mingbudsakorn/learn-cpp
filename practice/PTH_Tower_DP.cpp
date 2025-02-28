#include <iostream>
#include <vector>

using namespace std;

int maxLevelTower(vector< vector<int> > &e, vector< vector<int> > &dp, int curr, int pow) {
    if (pow <= 0) {
        return curr;
    }

    if (dp[curr][pow] != -1) {
        return dp[curr][pow];
    };

    int out = curr;
    for (int toGo: e[curr]) {
        int temp = maxLevelTower(e, dp, toGo, pow-1);
        if (temp > out) {
            out = temp;
        }
    }
    dp[curr][pow] = out;
    return dp[curr][pow];
}

int main() {
    int k, n, m;
    cin >> k >> n >> m;
    vector< vector<int> > e(n + 1);
    vector< vector<int> > dp(n + 1, vector<int>(k + 1, -1));
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        e[a].push_back(b);
    }
    cout << maxLevelTower(e, dp , 1, k);

}