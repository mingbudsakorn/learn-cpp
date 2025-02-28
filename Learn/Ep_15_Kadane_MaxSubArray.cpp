// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         vector<int> localMax(nums.size(), 0);
//         localMax[0] = nums[0];
//         int globalMax = nums[0];
//         for (int i = 1; i < nums.size(); i++) {
//             localMax[i] = max(nums[i], nums[i]+localMax[i-1]);
//             if (localMax[i] > globalMax) {
//                 globalMax = localMax[i];
//             }
//         }
//         return globalMax;
//     }
// };

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    cin >> n;
    vector<int> data(n,0);

    for (int i = 0; i< n; i++) {
        cin >> data[i];
    }

    int globalMax = -1;
    int localMax = 0;
    int globalStart = 0;
    int globalCount = 0;

    int start = 0;
    int count = 0;
    for (int i= 0; i< n; i++) {
        if (data[i] > localMax + data[i]) {
            //start new
            localMax = data[i];
            start = i;
            count = 1;
        } else {
            localMax = localMax + data[i];
            count++;
        }
        if (localMax > globalMax) {
            globalMax = localMax;
            globalStart = start;
            globalCount = count;
        }
    }

    if (globalMax <= 0) {
        cout << "Empty sequence";
    } else {
        for (int i = globalStart; i < globalStart + globalCount; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
        cout << globalMax;
    }

}
