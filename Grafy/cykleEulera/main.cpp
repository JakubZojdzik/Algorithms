#include <bits/stdc++.h>
using namespace std;

constexpr int MX = 1000007;
int byc[MX];
vector<pair<int, int>> kraw[MX];
vector<int> wynik;

void dfs(int v)
{
    while(!kraw[v].empty())
    {
        pair<int, int> w = kraw[v].back();
        kraw[v].pop_back();
        if(byc[w.second] == 0)
        {
            byc[w.second] = 1;
            byc[w.second] = 1;
            dfs(w.first);
            wynik.push_back(w.first);
        }
    }
}

int main()
{
    int n, m, po, a, b;
    cin >> n >> m;
    int j = 1;
    for(int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        kraw[a].push_back({b, j});
        kraw[b].push_back({a, j});
        j++;
    }
    dfs(1);
    for(int w : wynik)
    {
        cout << w << " ";
    }
    cout << '\n';
}

/*
7 11
1 4
1 2
2 3
4 3
2 8
8 7
3 5
3 7
5 6
6 7
2 7
*/