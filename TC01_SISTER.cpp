#include <stdio.h>
#include <iostream>

using namespace std;
#include <queue>;

int main() {
    int n;
    long k;
    scanf("%d %ld",&n, &k);
    int sugar[n];
    priority_queue<int> sugar_queue;
    for (int i=0; i<n; i++) {
        scanf("%d",&sugar[i]);
        sugar_queue.push(sugar[i]);
    } 

    // int temp_max = 0, index_temp = 0;
    long sum = 0;
    int count = 0;
    while (sugar_queue.size()>0) 
    {
        sum += sugar_queue.top();
        sugar_queue.pop();
        count++;
        if (sum >= k) {
            printf("%d", count);
            break;
        } 
    }
    
    // for (int i=0; i< n; i++) {
    //     temp_max = 0;
    //     for (int j = 0; j < n; j++) {
    //         if (sugar[j] > temp_max) {
    //             temp_max = sugar[j];
    //             index_temp = j;
    //         }
    //     }
    //     sugar[index_temp] = 0;
    //     sum += temp_max;
    //     count += 1;
    //     if (sum >= k) {
    //         printf("%d", count);
    //         break;
    //     }   
    // }
    // }
}