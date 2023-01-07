/*
    Jakub Żojdzik
    06-01-2023
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

int ps[100007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    string s;
    // cin >> s;
    s = "aababaa";
    s = "!" + s;
    ps[0] = -1;
    int b = -1;
    for(int i = 1; i < sz(s); i++)
    {
        while(b > -1 && s[i] != s[b+1])
        {
            b = ps[b];
        }
        b++;
        ps[i] = b;
        debug(ps[i]);
    }
}

/*
aabaababaa
*/