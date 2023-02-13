#include <bits/stdc++.h>
using namespace std;

vector<int> kraw[500007];
int up[20][500007];
int depth[500007];

void dfs(int v = 1, int from = 1)
{
    depth[v] = depth[from]+1;
    up[0][v] = from;
    for(int i = 0; i < int(kraw[v].size()); i++)
    {
        if(kraw[v][i] != from)
        {
            dfs(kraw[v][i], v);
        }
    }
}

int jump(int v, int x)
{
    int akt = 0;
    while(x)
    {
        if(x & 1)
            v = up[akt][v];
        x /= 2;
        akt++;
    }
    return v;
}

int lca(int a, int b)
{
    if(depth[a] < depth[b]) swap(a, b);
    a = jump(a, depth[a] - depth[b]);
    if(a == b) return a;
    int pocz = 0, kon = 5e5, srod;
    while(pocz+1 < kon)
    {
        srod = (pocz + kon) / 2;
        if(jump(a, srod) == jump(b, srod))
        {
            kon = srod;
        }
        else
        {
            pocz = srod;
        }
    }
    return jump(a, srod);
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, a, b;
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        cin >> a >> b;
        kraw[a].push_back(b);
        kraw[b].push_back(a);
    }
    dfs();
    for(int i = 1; i <= 5; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            up[i][j] = up[i-1][up[i-1][j]];
        }
    }

    cout << lca(5, 12) << '\n'; // 1
    cout << lca(10, 12) << '\n'; // 8
    cout << lca(8, 13) << '\n'; // 2
    cout << lca(8, 2) << '\n'; // 2
    cout << lca(1, 9) << '\n'; // 1
    cout << lca(8, 6) << '\n'; // 2
    cout << lca(10, 11) << '\n'; // 8
    cout << lca(3, 3) << '\n'; // 3

}

/*
13
1 2
1 3
1 4
3 5
2 6
2 7
2 8
2 9
8 10
8 11
11 12
6 13

*/