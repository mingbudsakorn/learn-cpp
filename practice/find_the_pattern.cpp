#include <bits/stdc++.h>
#include <string.h>
using namespace std;
// 10001
// 01010
// 00000
// 01010
// 10001
void printVector(vector<string> v) {
    for (string e : v) {
        cout << e << endl;
    }
}

bool checkPattern(vector<string> v, int row, int col, vector<string> pattern) {
    int pat = 1;
    for (int i = row + 1; i < row + 4; i++) {
        if (v[i].substr(col, 5) != pattern[pat]) {
            return false;
        }
        pat++;
    }
    return true;
}

int main() {
    int r, c;
    string temp;
    vector<string> input;
    string first = "10001";
    string second = "01010";
    string third = "00000";
    vector<string> pattern;
    pattern.push_back(first);
    pattern.push_back(second);
    pattern.push_back(third);
    pattern.push_back(second);
    pattern.push_back(first);

    cin >> r >> c;
    for (int i = 0; i < r; i++){
        cin >> temp;
        input.push_back(temp);
    }
    bool found = false;
    for (int row = 0; row < r - 4; row++) {
        for (int col = 0; col < c - 4; col++)
        {
            temp = input[row].substr(col, 5);
            if (temp == first && input[row + 4].substr(col, 5) == first) {
                // check pattern
                bool result = checkPattern(input, row, col, pattern);
                if (result) {
                    cout << col<< " " << row << endl;
                    found = true;
                    break;
                }
            }
        }     
    }
    if (!found) {
        cout << "Not Found";
    }
}