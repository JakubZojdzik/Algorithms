#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int, int>> kraw[107];
ll dp[107][107];

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m, a, b, c;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = LONG_LONG_MAX;
            if(i == j) dp[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        kraw[a].push_back(make_pair(b, c));
        dp[a][b] = c;
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(dp[i][k] != LONG_LONG_MAX && dp[k][j] != LONG_LONG_MAX && dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = dp[i][k] + dp[k][j];

    for(int i = 1; i <= n; i++)
    {
        if(dp[i][i] < 0)
        {
            cout << "Negative cicle\n";
            return 0;
        }
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << '\n';
}
