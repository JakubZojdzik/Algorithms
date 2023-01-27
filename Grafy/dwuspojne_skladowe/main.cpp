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

void dfs(int x)
{
    seen[x] = 1;
    low[x] = depth[x];
    for(int i = 0; i < sz(kraw[x]); i++)
    {
        if(seen[kraw[x][i]] == 0)
        {
            dfs(x);
            // x jest podejrzany o bycie punktem artykulacji lub należy do mostu
            if(low[kraw[x][i]] >= depth[x])
            {
                AP.pb(x);
            }
            if(low[kraw[x][i]] >= depth[kraw[x][i]])
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

    seen[x] = 2;
}

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    
}

/*

*/