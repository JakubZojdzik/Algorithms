#include <bits/stdc++.h>
using namespace std;

vector<int> kraw[500007];
bool seen[500007];
int odl[500007], aktDist;

void dfs(int start)
{
    seen[start] = true;
    odl[start] = aktDist;
    aktDist++;
    for (int i = 0; i < kraw[start].size(); i++)
    {
        if(!seen[kraw[start][i]])
        {
            dfs(kraw[start][i]);
        }
    }
    aktDist--;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, a, b;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        kraw[a].push_back(b);
        kraw[b].push_back(a);
    }
    dfs(1);
    int maxDist = -1;
    int pocz;
    for (int i = 1; i <= n; i++)
    {
        if(odl[i] > maxDist)
        {
            maxDist = odl[i];
            pocz = i;
        }
    }
    aktDist = 0;
    for (int i = 1; i <= n; i++)
    {
        seen[i] = false;
        odl[i] = -1;
    }
    dfs(pocz);
    int kon;
    maxDist = -1;
    for (int i = 1; i <= n; i++)
    {
        if(odl[i] > maxDist)
        {
            maxDist = odl[i];
            kon = i;
        }
    }
    cout << "Najdluzsza scierzka to " << pocz << " -> " << kon << " i wynosi " << maxDist << " - " << maxDist+1 << "wierzchołków\n";
}

/*
12
1 2
1 3
1 4
4 5
5 6
6 7
6 8
6 9
7 10
8 12
9 11
*/