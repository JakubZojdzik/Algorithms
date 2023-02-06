#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> kraw[500007];
int from[500007];
int dist[500007];
set<pair<int, int>> q;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, a, b, c;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        kraw[a].push_back({b, c});
    }

    // distances are calculated from vertex 1
    for(int i = 2; i <= n; i++)
    {
        from[i] = -1;
        dist[i] = 1e9+17;
    }
    dist[1] = 0;
    from[1] = 1;
    q.insert({0, 1});
    while(!q.empty())
    {
        int v = q.begin()->second;
        q.erase(q.begin());
        for(int i = 0; i < int(kraw[v].size()); i++)
        {
            int w = kraw[v][i].first;
            int len = kraw[v][i].second;
            if(dist[w] > dist[v] + len)
            {
                q.erase({dist[w], w});
                dist[w] = dist[v] + len;
                from[w] = v;
                q.insert({dist[w], w});
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << "dist[" << i << "] = " << dist[i] << '\n';
    }
    for(int i = 1; i <= n; i++)
    {
        cout << "from[" << i << "] = " << from[i] << '\n';
    }
}

/*
7 10
1 3 2
3 5 1
5 1 1
3 7 9
7 2 2
2 4 3
4 2 2
2 1 4
2 6 4
1 7 3
*/