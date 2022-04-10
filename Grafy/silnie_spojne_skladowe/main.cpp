#include <bits/stdc++.h>
using namespace std;

vector<int> kraw[10007];
vector<int> reverted[10007];
stack<int> S;
bool seen[10007];
int skladowa[10007];

void dfs(int a)
{
    seen[a] = true;
    for(int i = 0; i < kraw[a].size(); i++)
        if(!seen[kraw[a][i]])
            dfs(kraw[a][i]);
    S.push(a);
}

void dfs2(int a, int c)
{
    skladowa[a] = c;
    seen[a] = true;
    for(int i = 0; i < reverted[a].size(); i++)
        if(!seen[reverted[a][i]])
            dfs2(reverted[a][i], c);
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, a, b;
    cin >> n >> m; // n - wierzchołki, m - krawędzie
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        kraw[a].push_back(b);
        reverted[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) if(!seen[i]) dfs(i);
    for(int i = 1; i <= n; i++) seen[i] = false;
    int c = 0;
    while(!S.empty())
    {
        int v = S.top();
        S.pop();
        if(!seen[v]) dfs2(v, ++c);
    }

    for(int i = 1; i <= n; i++)
        cout << "Wierzchołek " << i << " należy do " << skladowa[i] << '\n';
}
