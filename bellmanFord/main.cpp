#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<tuple<int, int, int>> kraw;
int cost[500007], from[500007];

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, a, b, c;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        kraw.push_back(make_tuple(a, b, c));
    }

    for(int i = 1; i <= n; i++) cost[i] = 1e9+7;
    cost[1] = 0;
    bool mod;
    for (int i = 0; i < n - 1; i++)
    {
        mod = false;
        for (auto k : kraw)
        {
            if (cost[get<1>(k)] > cost[get<0>(k)] + get<2>(k))
            {
                cost[get<1>(k)] = cost[get<0>(k)] + get<2>(k);
                from[get<1>(k)] = get<0>(k);
                mod = true;
            }
        }
        if(!mod)
            break;
    }

    for(int i = 1; i <= n; i++)
    {
        cout << "cost = " << cost[i] << ", pop = " << from[i] << '\n';
    }
}