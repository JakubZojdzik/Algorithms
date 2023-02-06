#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll MOD = 1e9+9;
constexpr ll BASE = 31; // base of numeral system
ll h[500007]; // hash
ll p[500007]; // consecutive powers of base

bool comp(ll l1, ll r1, ll l2, ll r2) // compare substrings of s
{
    if(r1 - l1 != r2 - l2) return 0;
    if(l2 < l1)
    {
        swap(l1, l2);
        swap(r1, r2);
    }
    return ((h[l1] - h[r1+1] + MOD) % MOD == (((h[l2] - h[r2+1] + MOD) * p[l2 - l1]) % MOD));
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    s = "papiezalamakotapapiezakotmala";
    p[0] = 1;
    for(int i = 1; i <= int(s.size()); i++)
        p[i] = (p[i-1] * BASE) % MOD;
    for(int i = int(s.size())-1; i >= 0; i--)
    {
        h[i] = (h[i+1] + (s[i] - ll('a') + 1ll) * p[int(s.size())-1-i]) % MOD;
    }

    cout << comp(0, 5, 15, 20) << ", " << comp(11, 13, 22, 24) << ", " << comp(0, 1, 27, 28) << ", " << comp(26, 28, 6, 8) << '\n';
    // 1, 1, 0, 1
}