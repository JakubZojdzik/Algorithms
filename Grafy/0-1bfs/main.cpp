#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> kraw[100007];
int dist[100007];
deque<int> kol;

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int a, b, c;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        kraw[a].push_back(make_pair(b, c));
        kraw[b].push_back(make_pair(a, c));
    }
    kol.push_back(1); // poczatek w wierzchołku 1
    for (int i = 2; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }
    int wiersz = 1;
    while (!kol.empty())
    {
        int w = kol[0];
        kol.pop_front();
        for(int j = 0; j < kraw[w].size(); j++)
        {
            if(dist[kraw[w][j].first] > dist[w] + kraw[w][j].second)
            {
                dist[kraw[w][j].first] = dist[w] + kraw[w][j].second;
                if (kraw[w][j].second)
                    kol.push_back(kraw[w][j].first);
                else
                    kol.push_front(kraw[w][j].first);
            }
        }
    }

    cout << '\n';
    for (int i = 1; i <= n; i++)
    {
        cout << "do " << i << " odl = " << dist[i] << '\n';
    }
}

/*
9 13
1 2 0
1 8 1
2 8 1
2 3 1
3 4 0
3 6 0
3 9 1
4 5 1
4 6 1
5 6 1
6 7 1
7 8 1
8 9 1
*/
