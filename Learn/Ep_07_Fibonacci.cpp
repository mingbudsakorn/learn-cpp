
#include <bits/stdc++.h>

using namespace std;

int main() {

    map<int,int> m;

    // if (...) {
    //     return ...
    // }
    // fib (7) = fib(6) + fib(5)
    // fib (8) = fib(7) + fib(6)
    
}

subset {1}
1 2 3 
res = { {}, {1}, {1,2}, {1,2,3}  }
{1} -> {1,2}
    -> {1}

 1   calCSubset({1,2,3}, .. , {1}, 1)
        subset {1,2}
        // calCSubset({1,2,3}, .. , {1,2}, 2)
        //     subSet{1,2,3}
        //     calCSubset({1,2,3}, .. , {1,2,3}, 3)
        //     subSet{1,2}
        subSet{1}
        i = 2;
        subSet{1,3}