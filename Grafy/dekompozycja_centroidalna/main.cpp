/*
    Jakub Żojdzik
    17-01-2023
*/

#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.hpp"
#else
#define debug(...)
#define dt
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<long long, long long>> vpll;

#define fi first
#define se second
#define pb push_back
#define rep(i, x, y) for(ll i = (ll)x; i <= (ll)y; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define nl cout << '\n'

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

    vi tmp(kraw[c].begin(), kraw[c].end());
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
    rep(i, 0, n-2)
    {
        cin >> a >> b;
        kraw[a].insert(b);
        kraw[b].insert(a);
    }

    build(1, -1);
}

/*

*/