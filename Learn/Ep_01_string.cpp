#include <iostream>

using namespace std;
int main() {
    // string s1;

    // cin >> s1;

    // cout << s1 << endl;

    // string s2;

    // getline(cin, s2);

    // cout << s2 << endl;

    //String
    // string s1 = "First";
    // string s2("First");
    // string s3 = s1 + s2;
    // cout << s1 << " " << s1.length() << endl;
    // cout << s3 << " " << s3.length() << endl;

    // cout << s1.compare(s2) << endl;

    // if (s1.compare(s2) == 0) {
    //     cout << "Yes1" << endl;
    // }

    // if (s1 == s2) {
    //     cout << "Yes2" << endl;
    // }

    // // -1 0 1
    // cout << s1[1] << endl;

    
    // string s;
    // s += "D2";
    // s -> "D2";
    // int n = s.length();
    

    //Ex1 check username, password
    string username = "user";
    string password = "pass";

    string u, p;

    int n = username.length();
    char a = username[0];

    //username:
    //password:

    // "Login successfully"
    // "username or password is invalid"

    // cout << "username: ";
    // cin >> u;

    // cout << "password: ";
    // cin >> p;

    // if (u == username && p.compare(password) == 0) {
    //     cout << "Login successfully" << endl;
    // } else {
    //     cout << "username or password is invalid" << endl;
    // }

    //Ex2 reverse input and print => pall => llap


    //assign() -> s.assign("Hello") => s = "Hello"
    //append() -> s.append("Hello") => s += "Hello"
    //insert(indexToInsert, stringToInsert)
    //erase(firstIndexToErase, numberOfStringToErase)

    string s = "Kpop";
    // s.insert(1, "-"); //"K-pop"
    // s.insert(4, "-"); //"Kpop-"
    // s.insert(10, "-"); //Error

    // string s2 = "123";
    // int tt = stoi(s2);
    // // s.erase(1, 50);
    // cout << tt << endl;

    //find(stringToFind) => if found => return index
    //if not found => return string::npos
    s = "Test string";
    
    int f = s.find("string");
    cout << f << endl;

    s = "Hello world!";
    //substr(startIndex, numberOfChar)
    cout << s.substr(1,5) << endl;

    //replace(startIndex, numberOfCharToReplace, stringToReplace)
    s.replace(1, 6, "ooo");
    cout << s << endl;

    int k = 121;
    int *ptr;
    ptr = &k;
    cout << *ptr << endl;
    
    return 0;
}