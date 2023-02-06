#include <bits/stdc++.h>
using namespace std;

vector<int> kraw[500007], rev[500007];
bitset<500007> seen;
stack<int> S;
int scc[500007];
int res[500007];

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
    cin >> n >> m; // n - number of variables, m - number of conditions
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        if(a < 0 && b < 0) // not a, not b
        {
            a = -a; b = -b;
            kraw[2*a].push_back(2*b+1);
            kraw[2*b].push_back(2*a+1);
            rev[2*b+1].push_back(2*a);
            rev[2*a+1].push_back(2*b);
        }
        else if(a < 0 && b > 0) // not a, b
        {
            a = -a;
            kraw[2*a].push_back(2*b);
            kraw[2*b+1].push_back(2*a+1);
            rev[2*b].push_back(2*a);
            rev[2*a+1].push_back(2*b+1);
        }
        else if(a > 0 && b < 0) // a, not b
        {
            b = -b;
            kraw[2*a+1].push_back(2*b+1);
            kraw[2*b].push_back(2*a);
            rev[2*b+1].push_back(2*a+1);
            rev[2*a].push_back(2*b);
        }
        else if(a > 0 && b > 0) // a, b
        {
            kraw[2*a+1].push_back(2*b);
            kraw[2*b+1].push_back(2*a);
            rev[2*b].push_back(2*a+1);
            rev[2*a].push_back(2*b+1);
        }
    }

    for(int i = 2; i <= 2*n+1; i++)
    {
        if(!seen[i]) dfs1(i);
    }
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
        if(scc[2*i] == scc[2*i+1])
        {
            cout << "CONTRADITION\n";
            return 0;
        }
        if(scc[2*i] < scc[2*i+1])
        {
            res[i] = 0;
        }
        else
        {
            res[i] = 1;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << i << ": " << res[i] << '\n';
    }
}