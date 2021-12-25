#include <bits/stdc++.h>
using namespace std;

constexpr int LIMIT = 1007;

vector<int> kraw[LIMIT];
bool seen[LIMIT];
int lev[LIMIT];    // poziom wierzchołka w drzewie
int up[LIMIT][12]; // up[v][k] - wierzchołek gdy z v pójdziemy 2^k w górę

void dfs(int v, int from, int p)
{
    up[v][0] = from;
    seen[v] = true;
    lev[v] = p;
    for (int i = 0; i < kraw[v].size(); i++)
        if (!seen[kraw[v][i]])
            dfs(kraw[v][i], v, p + 1);
}

int move_up(int v, int l) // składamy kilka ruchów o potęgę 2 w ruch o l
{
    for (int i = 0; l > 0; i++)
    {
        if (l & 1)
            v = up[v][i];
        l = l >> 1;
    }
    return v;
}

int lca(int v, int w)
{
    if (lev[w] < lev[v])
        swap(v, w);              //w będzie zawsze niewyżej w drzewie niż v
    w = move_up(w, lev[w] - lev[v]); // wyrównanie wierzchołków
    if(w == v) return w;
    //binarne szukanie wspólnego wierzchołka
    int p = lev[w], k = 0, s;
    s = (p + k) / 2;
    while (up[v][0] != up[w][0])
    {
        s = (p + k) / 2;
        if (move_up(v, lev[v] - s) != move_up(w, lev[w] - s))
        {
            v = move_up(v, lev[v] - s);
            w = move_up(w, lev[w] - s);
            p = lev[w];
        }
        else k = s;
    }
    return up[v][0];
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    for (int Q = 1; Q <= q; Q++)
    {
        
        int n, a, b;
        cin >> n;
        for (int i = 0; i < LIMIT; i++)
        {
            kraw[i].clear();
            seen[i] = false;
            lev[i] = 0;
            for (int j = 0; j < 12; j++)
            {
                up[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            int m;
            cin >> m;
            for (int j = 1; j <= m; j++)
            {
                cin >> a;
                kraw[a].push_back(i);
                kraw[i].push_back(a);
            }
        }
        dfs(1, 1, 0); // korzeń w 1
        for (int v = 1; v <= n; v++)
        {
            for (int k = 1; lev[n] - pow(2, k) >= 0; k++)
            {
                up[v][k] = up[up[v][k - 1]][k - 1];
            }
        }
        cout << "Case " << Q << ": \n";
        int t;
        cin >> t;
        for (int i = 0; i < t; i++)
        {
            cin >> a >> b;
            cout << lca(a, b) << '\n';
        }
    }
}

/*
1
13
3 2 3 4
0
3 5 6 7
0
0
2 8 9
2 10 11
0
0
2 12 13
0
0
0
1
8 11
*/