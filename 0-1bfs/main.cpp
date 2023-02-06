#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> kraw[500007];
int from[500007];
int dist[500007];
deque<int> q;

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

    for(int i = 1; i <= n; i++)
    {
        from[i] = -1;
        dist[i] = 1e9+7;
    }
    q.push_back(1);
    dist[1] = 0;
    while(!q.empty())
    {
        int v = q.front();
        q.pop_front();
        for(int i = 0; i < int(kraw[v].size()); i++)
        {
            int w = kraw[v][i].first;
            int len = kraw[v][i].second;
            if(dist[w] > dist[v] + len)
            {
                dist[w] = dist[v] + len;
                from[w] = v;
                if(len == 0)
                    q.push_front(w);
                else
                    q.push_back(w);
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
1 3 1
3 5 1
5 1 0
3 7 1
7 2 0
2 4 0
4 2 1
2 1 1
2 6 1
1 7 0
*/