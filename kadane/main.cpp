#include <bits/stdc++.h>
using namespace std;

int a[500007];

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

    int here = -1e9, res = here;
    for(int i = 0; i < n; i++)
    {
        here = max(a[i], here + a[i]);
        res = max(res, here);
    }

    cout << res << '\n';
}