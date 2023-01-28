/*
    Jakub Żojdzik
    27-01-2023
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

int seen[500007];
int low[500007];
int depth[500007];
vi kraw[500007];

vi AP;
vpii mosty;

void calc_depth(int v, int from)
{
    seen[v] = 1;
    depth[v] = depth[from] + 1;
    for(int i = 0; i < sz(kraw[v]); i++)
    {
        if(!seen[kraw[v][i]])
        {
            calc_depth(kraw[v][i], v);
        }
    }
}

// Jeżeli root ma stopień conajmniej 2, to również jest punktem artykulacji
int dfs(int x, int from)
{
    int res = 0;
    seen[x] = 1;
    low[x] = depth[x];
    cout << "akt: " << x << '\n';
    bool jest = 1, lisc = 1;
    for(int i = 0; i < sz(kraw[x]); i++)
    {
        if(kraw[x][i] == from) continue;
        if(seen[kraw[x][i]] == 0)
        {
            res++;
            lisc = 0;
            dfs(kraw[x][i], x);
            // x jest podejrzany o bycie punktem artykulacji lub należy do mostu
            if(!(low[kraw[x][i]] >= depth[x]))
            {
                jest = 0;
            }
            if(low[kraw[x][i]] == depth[kraw[x][i]])
            {
                mosty.pb({x, kraw[x][i]});
            }
            low[x] = min(low[x], low[kraw[x][i]]);
        }
        if(seen[kraw[x][i]] == 1)
        {
            low[x] = min(low[x], depth[kraw[x][i]]);
        }
    }
    if(jest && (!lisc) && x != from) AP.pb(x);
    return res;
}

int main()
{
    // cout.tie(0);
    // cin.tie(0)->sync_with_stdio(0);

    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        kraw[a].pb(b);
        kraw[b].pb(a);
    }
    cout << "wczytane\n";
    calc_depth(1, 1);
    for(int i = 1; i <= n; i++)
    {
        cout << "depth[" << i << "] = " << depth[i] << '\n';
        seen[i] = 0;
    }
    cout << "glebokosci policzone\n";
    if(dfs(1, 1) > 1) AP.pb(1);
    for(int i = 1; i <= n; i++)
    {
        cout << "low[" << i << "] = " << low[i] << '\n';
    }
    cout << "dfs policzony\n";
    for(int xd : AP)
    {
        cout << xd << ", ";
    }
    nl;
    for(auto xd : mosty)
    {
        cout << "(" << xd.first << ", " << xd.second << "); ";
    }
    nl;
}

/*
6 7
1 2
2 3
3 1
3 4
4 5
5 6
6 4
*/