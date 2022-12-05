/*
    Jakub Żojdzik
    05-12-2022
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

deque<pair<ll, ll>> kol;

void push(ll x)
{
    ll cnt = 0;
    while(!kol.empty() && kol.back().fi >= x)
    {
        cnt += kol.back().se + 1;
        kol.pop_back();
    }
    kol.push_back({x, cnt});
}

void pop()
{
    if(kol.front().second == 0) kol.pop_front();
    else kol.front().second--;
}

ll top()
{
    return kol.front().fi;
}

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    push(1);
    push(5);
    pop();
    cout << top() << '\n';
    push(2);
    push(3);
    cout << top() << '\n';
    pop();
    pop();
    cout << top() << '\n';
}