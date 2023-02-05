#include <bits/stdc++.h>
using namespace std;

pair<int, int> dp[2007][2007];

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string a, b;
    cin >> a >> b;

    a = "!" + a;
    b = "!" + b;
    for(int i = 1; i < int(a.size()); i++)
    {
        for(int j = 1; j < int(b.size()); j++)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = {dp[i-1][j-1].first + 1, 2};
            }
            else if(dp[i][j-1] > dp[i-1][j])
            {
                dp[i][j] = {dp[i][j-1].first, 0};
            }
            else
            {
                dp[i][j] = {dp[i-1][j].first, 1};
            }
        }
    }

    int p = int(a.size())-1, q = int(b.size())-1, cnt = 0, lim = dp[p][q].first;
    cout << lim << '\n';
    string res;
    while(cnt < lim)
    {
        if(dp[p][q].second == 2)
        {
            res = a[p] + res;
            p--; q--;
            cnt++;
        }
        else if(dp[p][q].second == 0)
        {
            q--;
        }
        else
        {
            p--;
        }
    }
    cout << res << '\n';
}