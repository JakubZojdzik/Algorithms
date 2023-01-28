/*
    Jakub Żojdzik
    28-01-2023
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

int wsk[500007];

int get(int x)
{
    if(x == wsk[x]) return x;
    return get(wsk[x]);
}

bool unit(int x, int y)
{
    if(get(x) == get(y)) return false;
    

}

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    
}

/*

*/