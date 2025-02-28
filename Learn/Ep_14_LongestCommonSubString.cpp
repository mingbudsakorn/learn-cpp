#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    int m = s1.size();
    int n = s2.size();

    vector< vector<int> > lcs(m + 1, vector<int>(n + 1, 0));
    int maxLen = 0;
    int endI = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
                if (lcs[i][j] > maxLen) {
                    maxLen = lcs[i][j];
                    endI = i;
                }
            } else {
                    lcs[i][j] = 0;
            }
        }
    }
    string result = "";
    for (int i = 0; i < maxLen; i++) {
        result = s1[endI-1] + result;
        endI--;
    }
    cout << result;
    return 0;
}


// 1 -> longest -> int
// 2 -> endIndex -> int

// [][][][]
// [][][][]
// [][][][]


/// @brief 
/// @return 

// pair<int,int> LCS(vector< vector< pair<int,int> > > &lcs, string &s1, string &s2, int i, int j) {

//     if (i<=0 || j<=0) {
//         return make_pair(0,0);
//     }

//     if (lcs[i][j].first != -1) return lcs[i][j];

//     if (s1[i-1] == s2[j-1]) {
//         pair<int,int> res = LCS(lcs, s1, s2, i-1, j-1);
//         lcs[i][j] = make_pair(res.first + 1, i-1);
//         // lcs(lcs, s1, s2, )
//     } else {
//            lcs[i][j] = make_pair(0, i-1);
//     }
//     return lcs[i][j];

// }

// int main() {
//     string s1 = "AAAACTGCTACCGGT";
//     string s2 = "CTGAATCTACTGCTATTGCAA";
//     int m = s1.size();
//     int n = s2.size();
//     vector< vector< pair<int,int> > > lcs(m + 1, vector< pair<int,int> >(n + 1, make_pair(-1,-1)));
//     pair<int,int> res = LCS(lcs, s1, s2, m, n);
//     cout << res.first << " " << res.second << endl;
//     cout << s1.substr(res.second - res.first, res.first) << endl;
// }