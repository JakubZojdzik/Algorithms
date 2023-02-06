#include <bits/stdc++.h>
using namespace std;

vector<int> kraw[500007], rev[500007];
stack<int> S;
bitset<500007> seen;
int scc[500007];

void dfs1(int v)
{
    seen[v] = 1;
    for(int i = 0; i < int(kraw[v].size()); i++)
    {
        if(!seen[kraw[v][i]])
        {
            dfs1(kraw[v][i]);
        }
    }
    S.push(v);
}

void dfs2(int v, int c)
{
    scc[v] = c;
    seen[v] = 1;
    for(int i = 0; i < int(rev[v].size()); i++)
    {
        if(!seen[rev[v][i]])
        {
            dfs2(rev[v][i], c);
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
        rev[b].push_back(a);
    }

    for(int i = 1; i <= n; i++)
        if(!seen[i])
            dfs1(i);

    seen.reset();
    int c = 0;
    while(!S.empty())
    {
        int v = S.top();
        S.pop();
        if(!seen[v])
        {
            dfs2(v, c++);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << "scc[" << i << "] = " << scc[i] << '\n';
    }
}

/*
7 10
1 2
2 3
3 1
1 7
5 7
3 5
3 4
4 6
4 5
5 6
*/