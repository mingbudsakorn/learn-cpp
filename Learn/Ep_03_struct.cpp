#include <iostream>

using namespace std;

typedef long long ll;

typedef struct person {
    string name;
    int age;
} P;

void test(P p) {
    cout << p.name << endl;
};

int main() {
    P p;
    p.name = "Tony";
    p.age = 42;

    test(p);

    ll long_ja = 12;
    
    return 0;
}
    