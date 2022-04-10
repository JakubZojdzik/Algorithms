#include <bits/stdc++.h>
using namespace std;

vector<int> kraw[100007];
int depth[100007];
bool seen[100007];
int parent[100007];
int low[100007];
int n, m, d;
bool isAP[100007];

void findAPs(int w)
{
    int children = 0;
    seen[w] = true;
    depth[w] = d;
    low[w] = d;
    d++;
    for (int i = 0; i < kraw[w].size(); i++)
    {
        if(!seen[kraw[w][i]])
        {
            children++;
            parent[kraw[w][i]] = w;
            findAPs(kraw[w][i]);
            low[w] = min(low[w], low[kraw[w][i]]);
            if (low[kraw[w][i]] >= depth[w] && parent[w] != 0)
                isAP[w] = true;
        }
        else if(kraw[w][i] != parent[w])
            low[w] = min(low[w], depth[kraw[w][i]]);
    }
    d--;
    if (parent[w] == 0 && children > 1)
        isAP[w] = true;
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
    findAPs(1);
    for (int i = 1; i <= n; i++)
    {
        if(isAP[i])
            cout << i << ", ";
    }
    cout << '\n';
}

/*
7 8
1 2
1 3
2 3
2 7
2 4
2 5
4 6
5 6
*/
