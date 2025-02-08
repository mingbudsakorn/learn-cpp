#include <iostream>
using namespace std;

long long binary_exponentiation(int a, int n) {
    if(n==1){
        return a;
    }
    if (n==2)
    {
        return a*a;
    }
    
    if(n%2==0){
        long long temp = binary_exponentiation(a,n/2);
        return temp*temp;
    } else {
        long long temp = binary_exponentiation(a,(n-1)/2);
        return temp*temp*a;
    }
}

int main() {
    cout << binary_exponentiation(10,15) << endl;
}