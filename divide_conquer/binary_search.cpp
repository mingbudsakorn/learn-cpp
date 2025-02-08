#include <iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int target) {
    if (end < start) {
        return -1;
    }

    int middle = (start + end)/2;

    if(arr[middle]==target) {
        return middle;
    }

    if(arr[middle]<target) {
        start = middle + 1;
        return binarySearch(arr, start, end, target);
    }
    else{
        end = middle - 1;
        return binarySearch(arr, start, end, target);
    }
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 99;
    cout << binarySearch(arr,0,n-1,target) << endl;
}