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

    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int n = 4;
    cout << "n = 4" << endl;
    // from 0 > 3

    vector<int> d;
    vector<int> p;
    vector<int> un; // 0, 1, 2, 3
    for (int i = 0; i < n; i++)
    {
        d.push_back(999);
        p.push_back(-1);
        un.push_back(i);
    }

    d[0] = 0;

    // vector<int> tt = {2,5};
    // tt.pop_back();
    // tt.pop_back();
    // cout << tt.empty() << endl;
    // cout << tt.size() << endl;
    // while (!un.empty())
    // {
    //     /* code */
    // }

    vector<int> cat = {1,2,-3,4,5,-1};
    cout <<"index_of_min: " << index_of_min(cat).first << " " << index_of_min(cat).second << endl;
    return 0;
}
