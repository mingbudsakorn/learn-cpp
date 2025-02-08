// MergeSort -> O(nlogn)
// Bubble O(n^2)

// // Divide and Conquer = การแบ่งแยกและเอาชนะ
// [1, 50, 66, 88, 99, 12]
// 1. Divide -> Split array in to half
// 2. Conquer -> Recursive sort each array
// 3. Merge -> Combine two sorted array in to one


/*
...[1, 50, 66, 88, 99, 12] ......
    /                 \
[1, 50, 66]          [88, 99, 12]
    /      \            /       \
[1,50]     [66]      [88,99]    [12]
/    \       |        /   \       |
[1] [50]   [66]     [88]  [99]   [12]

merge
[1,50]     [66]     [88, 99]      [12]

[1, 50, 66]          [12, 88, 99]
     \                  /
    [1, 12, 50, 66, 88, 99]
*/

#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int left, int mid, int right) {
    //copy vector into 2 vector(left, right)
    int n1 = mid - left + 1;
    int n2 = right - mid;
//    [     ]    [      ]
//    left mid  mid+1 right

    // Create temp vector
    vector<int> leftArr, rightArr;

    //Copy vector
    for (int i = 0; i < n1; i++) {
        leftArr.push_back(arr[left+i]);
    }
    for (int i = 0; i < n2; i++) {
        rightArr.push_back(arr[mid+1+i]);
    }

    int a = 0, b = 0, k = left;
    //           k
    //  .......[                          ].......
    //         [          ]    [          ]
    //           a             b

    //merge both arrays
    while (a < n1 && b < n2) {
        if (leftArr[a] < rightArr[b]) {
            arr[k++] = leftArr[a++];
        } else {
            arr[k] = rightArr[b];
            k++;
            b++;
        }
    }

    while (a < n1) {
        arr[k++] = leftArr[a++];
    }
    while (b < n2) {
        arr[k++] = rightArr[b++];
    }
}

void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) { //do mergeSort if n(selected range) > 1
        int mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        //merge
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(arr,0, arr.size()-1);
    for (auto e : arr) {
        cout << e << " ";
    }
}