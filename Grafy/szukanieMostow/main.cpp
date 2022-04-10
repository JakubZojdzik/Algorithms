#include <bits/stdc++.h>
using namespace std;

vector<int> kraw[100007];
int depth[100007];
bool seen[100007];
int parent[100007];
int low[100007];
int n, m, d;
vector<pair<int, int>> mosty;

void findBridges(int w)
{
    seen[w] = true;
    depth[w] = d;
    low[w] = d;
    d++;
    for (int i = 0; i < kraw[w].size(); i++)
    {
        if(!seen[kraw[w][i]])
        {
            parent[kraw[w][i]] = w;
            findBridges(kraw[w][i]);
            low[w] = min(low[w], low[kraw[w][i]]);
            if(low[kraw[w][i]] > depth[w])
                mosty.push_back(make_pair(kraw[w][i], w));
        }
        else if(kraw[w][i] != parent[w])
        {
            low[w] = min(low[w], depth[kraw[w][i]]);
        }
    }
    d--;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        kraw[a].push_back(b);
        kraw[b].push_back(a);
    }
    findBridges(1);
    for(auto a : mosty)
    {
        cout << a.first << ", " << a.second << '\n';
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
