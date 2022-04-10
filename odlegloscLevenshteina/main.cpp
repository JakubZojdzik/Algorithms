#include <bits/stdc++.h>
using namespace std;

int dp[10007][10007];
string a, b;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    int n = a.length();
    int m = b.length();
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int i = 0; i <= m; i++)
        dp[0][i] = i;

    int cost;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cost = (a[i - 1] == b[i - 1]) ? 0 : 1;
            dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + cost);
        }
    }
    cout << "aby przejsc od slowa " << a << " do " << b << " potrzebujemy " << dp[n][m] << " operacji prostych\n";
}