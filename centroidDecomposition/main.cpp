#include <bits/stdc++.h>
using namespace std;

set<int> kraw[200007];
int wag[200007], parent[200007];

int dfs(int v, int from)
{
    wag[v] = 1;
    for(auto x : kraw[v])
    {
        if(x != from)
        {
            wag[v] += dfs(x, v);
        }
    }
    return wag[v];
}

int centroid(int v, int from, int n)
{
    for(auto x : kraw[v])
    {
        if(x != from && wag[x] > n/2)
        {
            return centroid(x, v, n);
        }
    }
    return v;
}

void build(int v, int from)
{
    int n = dfs(v, from);
    int c = centroid(v, from, n);
    if(from == -1)
    {
        from = c;
    }
    parent[v] = from;

    vector<int> tmp(kraw[c].begin(), kraw[c].end());
    for(auto x : tmp)
    {
        kraw[c].erase(x); kraw[x].erase(c);
        build(v, c);
    }
}

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int n, a, b;
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        cin >> a >> b;
        kraw[a].insert(b);
        kraw[b].insert(a);
    }

    build(1, -1);
}

/*

*/