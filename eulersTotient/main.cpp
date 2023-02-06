#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll totient(ll x)
{
    ll res = x;
    for(ll i = 2; i*i <= x; i++)
    {
        if(x % i == 0)
        {
            while(x % i == 0) x /= i;
            res -= res / i;
        }
    }
    if(x > 1)
        res -= res / x;

    return res;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;
    cin >> n;
    cout << totient(n) << '\n';
}