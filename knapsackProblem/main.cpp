#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[107][500007];
ll mass[107];
ll worth[107];

int main()
{
    cout.tie(0); cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, v;
    cin >> n >> v;
    for(int i = 1; i <= n; i++)
    {
        cin >> mass[i] >> worth[i];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= v; j++)
        {
            if(j >= mass[i])
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-mass[i]] + worth[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][v] << '\n';
}
