#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll nthFib(ll val)
{
    ll a = 1, b = 0, c = 0, d = 1;
    ll x = 1, y = 1, z = 1, w = 0;
    while(val)
    {
        if(val & 1)
        {
            ll tmpa = a*x + b*z;
            ll tmpb = a*y + b*w;
            ll tmpc = c*x + d*z;
            ll tmpd = c*y + d*w;
            a = tmpa;
            b = tmpb;
            c = tmpc;
            d = tmpd;
        }
        ll tmpx = x*x + y*z;
        ll tmpy = x*y + y*w;
        ll tmpz = z*x + w*z;
        ll tmpw = z*y + w*w;
        x = tmpx;
        y = tmpy;
        z = tmpz;
        w = tmpw;
        val /= 2;
    }
    return b;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;
    cin >> n;
    cout << nthFib(n) << '\n';
}