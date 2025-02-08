#include <bits/stdc++.h>
using namespace std;

bool My_func(int a, int b)
{
    return (a % 10) < (b % 10);
}

int main()
{

    // sort
    vector<string> cat = {"Aren", "Arain", "Erwin", "Aba"};
    int n = cat.size();
    sort(cat.begin(), cat.end(), greater<string>());
    for (int i = 0; i < n; i++)
    {
        cout << cat[i] << endl;
    }

    // pair
    pair<int, int> P = {1, 2};
    cout << "Pair Before: " << P.second << P.first << P.second << endl;

    P.first = 5;
    P.second = 10;
    cout << "Pair After (1): " << P.second << P.first << P.second << endl;
    cout << "Pair After (2): " << get<0>(P) << get<1>(P) << endl;

    // tuple
    tuple<int, int, string, string> T = {1, 2, "Aren", "Arain"};
    cout << "Tuple: " << get<0>(T) << ' ' << get<0>(T) << ' ' << get<2>(T) << ' ' << get<3>(T) << endl;
    // Tuple: 1 2 Aren Arain

    // vector
    vector<string> V = {"Mikasa", "Hello", "Zeek", "I'm", "Arai kor dai"};
    V.push_back("jhbfhawf");
    V.push_back("dddddddddddddddddddddddddddddddd");
    V.pop_back();
    cout << V.front() << endl;

    cout << "vector :";
    for (int i = 0; i < V.size(); i++)
    {
        if (i == V.size() - 1)
        {
            cout << ' ' << V[i] << endl;
            ;
        }
        else
        {
            cout << ' ' << V[i] << ",";
        }
    }

    // list
    list<int> first = {1, 2, 3, 4, 5};
    cout << "first: ";
    for (auto i : first)
    {
        cout << i << ' ';
    }
    cout << endl;

    list<int> second(5, 200);
    cout << "second: ";
    for (auto i : second)
    {
        cout << i << ' ';
    }
    cout << endl;

    list<int> third(next(first.begin(), 2), first.end());
    cout << "third: ";
    for (auto i : third)
    {
        cout << i << ' ';
    }
    cout << endl;

    list<int> fourth(second);
    cout << "fourth: ";
    for (auto i : fourth)
    {
        cout << i << ' ';
    }
    cout << endl;
    

    first.insert(first.begin(), 5);
    cout << "first after insert: ";
    for (auto i : first)
    {
        cout << i << ' ';
    }
    cout << endl;
    first.push_front(25);
    first.push_back(55);
    cout << "first after push: ";
    for (auto i : first)
    {
        cout << i << ' ';
    }
    cout << endl;
    first.pop_back();
    first.pop_front();
    cout << "first after pop: ";
    for (auto i : first)
    {
        cout << i << ' ';
    }
    cout << endl;
    auto it = find(first.begin(),first.end(), 4);
    cout << "it: " << *it << endl;
    cout << "first: ";
    for (auto i : first)
    {
        cout << i << ' ';
    }
    cout << endl;

}