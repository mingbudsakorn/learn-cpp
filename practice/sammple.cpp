#include <bits/stdc++.h>
using namespace std;

int area(vector<string> vec, pair<int, int> xy, vector<vector<bool>> &visited)
{
    if (xy.first > vec[0].size() - 1 || xy.second > vec.size() - 1 || xy.first < 0 || xy.second < 0)
    {
        return 0;
    }
    int sum = 1;
    if (visited[xy.second][xy.first])
    {
        return 0;
    }
    visited[xy.second][xy.first] = true;
    if (vec[xy.second][xy.first] == '0')
    {
        sum += area(vec, {xy.first - 1, xy.second}, visited);
        sum += area(vec, {xy.first + 1, xy.second}, visited);
        sum += area(vec, {xy.first, xy.second - 1}, visited);
        sum += area(vec, {xy.first, xy.second + 1}, visited);
    }
    else
    {
        return 0;
    }

    return sum;
}

vector<string> vec;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    set<int> set;
    for (int i = 0; i <= n; i++)
    {
        string str;
        getline(cin, str);
        if(!str.empty()) {
            vec.push_back(str);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a;
            a = area(vec, {j, i}, visited);
            set.insert(a);
        }
    }
    int max = 0;
    for (auto it : set)
    {
        if (max < it)
        {
            max = it;
        }
    }
    cout << max;
}