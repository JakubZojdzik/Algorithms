#include <bits/stdc++.h>
using namespace std;

vector<int> kraw[500007];
int up[500007];
int lvl[500007];
bitset<500007> seen;
int cnt;

int dfs(int v, int from = 0)
{
    seen[v] = 1;
    lvl[v] = lvl[from]+1;
    up[v] = lvl[v];
    for(int i = 0; i < int(kraw[v].size()); i++)
    {
        if(kraw[v][i] == from) continue;
        if(!seen[kraw[v][i]])
        {
            if(v == 1) cnt++;
            up[v] = min(up[v], dfs(kraw[v][i], v));
        }
        else
        {
            up[v] = min(up[v], lvl[kraw[v][i]]);
        }
    }
    return up[v];
}

void bridges_AP(int v)
{
    seen[v] = 1;
    for(int i = 0; i < int(kraw[v].size()); i++)
    {
        if(!seen[kraw[v][i]])
        {
            if(up[kraw[v][i]] > lvl[v])
            {
                cout << v << " =-= " << kraw[v][i] << " is a bridge\n";
            }
            if(up[kraw[v][i]] >= lvl[v] && v != 1)
            {
                cout << v << " is an articulation point\n";
            }
            bridges_AP(kraw[v][i]);
        }
    }
}

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
        kraw[b].push_back(a);
    }

    dfs(1);
    seen.reset();
    bridges_AP(1);
    if(cnt > 1)
    {
        cout << "1 is an articulation point\n";
    }
}

/*
7 8
1 3
1 2
2 3
2 7
2 4
2 5
4 6
5 6
*/