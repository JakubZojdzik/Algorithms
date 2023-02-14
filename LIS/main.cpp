#include <bits/stdc++.h>
using namespace std;

int a[500007], d[500007];

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++)
    {
        d[i] = 1e9+9;
    }
    d[0] = -1e9-9;

    for(int i = 0; i < n; i++)
    {
        int l = upper_bound(d, d+n, a[i]) - d;
        if(d[l] > a[i] && d[l-1] < a[i])
        {
            d[l] = a[i];
        }
    }

    int res = 0;
    for(int i = 0; i <= n; i++)
    {
        cout << i << ": " << d[i] << '\n';
        if(d[i] < 1e9+9)
        {
            res = i;
        }
    }
    cout << res << '\n';
}

/*
10
8 3 4 6 5 2 0 7 9 1
*/