#include <bits/stdc++.h>
using namespace std;

vector<int> kraw[500007];
vector<int> order;
int deg[500007];

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        kraw[a].push_back(b);
        deg[b]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        if(deg[i] == 0) q.push(i);
    }

    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        order.push_back(v);
        for(int i = 0; i < int(kraw[v].size()); i++)
        {
            deg[kraw[v][i]]--;
            if(deg[kraw[v][i]] == 0)
            {
                q.push(kraw[v][i]);
            }
        }
    }

    for(int v : order)
    {
        cout << v << " ";
    }
    cout << '\n';
}

/*
15 15
7 12
5 13
9 10
8 13
9 4
12 1
2 10
12 14
12 13
6 5
15 14
1 13
8 6
3 15
11 2
*/