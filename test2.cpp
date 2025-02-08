#include <iostream>
#include <vector>

using namespace std;

pair<int,int> index_of_min(vector<int> v)
{
    int index_of_min = 0;
    pair<int,int> out;
    int min = v.front();
    for(int i=0; i<v.size() ;i++){
        if (v[i] < min) {
            min = v[i];
            index_of_min = i;
        }
    }
    out.first =  min;
    out.second = index_of_min;
    return out;
}

int main()
{

    int a = 122;
    string s = to_string(a);

    cout << s[2] << endl;
    cout << s << endl;
    // cout << s2 << endl;
}
