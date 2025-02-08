#include <iostream>
using namespace std;

int merge(int arr[],int begin,int mid,int end){
    int sizeOfLeft = mid - begin + 1;
    int left[sizeOfLeft];
    int sizeOfRight = end - mid;
    int right[sizeOfRight];
    int in = 0;
    for(int i = 0; i<sizeOfLeft; i++){
        left[i] = arr[begin+i];
    }
    for(int i = 0; i<sizeOfRight; i++){
        right[i] = arr[mid+i+1];
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int mergeIndex = begin;
    while (leftIndex < sizeOfLeft && rightIndex < sizeOfRight){
        if(left[leftIndex] <= right[rightIndex]){
            arr[mergeIndex] = left[leftIndex];
            leftIndex++;
            mergeIndex++;
        }
        else{
            arr[mergeIndex] = right[rightIndex];
            mergeIndex++;
            rightIndex++;
            in += sizeOfLeft - leftIndex;
        }
    }
    while (leftIndex < sizeOfLeft){
        arr[mergeIndex] = left[leftIndex];
        mergeIndex++;
        leftIndex++;
    }
    while (rightIndex < sizeOfRight){
        arr[mergeIndex] = right[rightIndex];
        mergeIndex++;
        rightIndex++;
    }
    return in;
}

int mergeSort(int arr[],int begin,int end){
    if(begin >= end){
        return 0;
    }
    int mid = (begin + end)/2;
    int in = 0;
    in+= mergeSort(arr,begin,mid);
    in+= mergeSort(arr,mid+1,end);
    in+= merge(arr,begin,mid,end);
    return in;
}

int main(){
    int arr[]={6,5,12,10,9,1};
    int sizeOfArray=sizeof(arr) / sizeof(arr[0]);

    for(int i=0;i<sizeOfArray;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    int inv = mergeSort(arr,0,sizeOfArray-1);
    for(int i=0;i<sizeOfArray;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "IN=" << inv ;
}
