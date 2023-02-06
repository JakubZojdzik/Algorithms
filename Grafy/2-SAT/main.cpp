#include <bits/stdc++.h>
using namespace std;

vector<int> kraw[307];
int skladowa[307];
bool seen[307];
int asdf;
vector<int> wynik;

void dfs(int a)
{
    skladowa[a] = asdf;
    seen[a] = true;
    for (int i = 0; i < kraw[a].size(); i++)
    {
        if (!seen[kraw[a][i]])
        {
            dfs(kraw[a][i]);
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        if (c == 0)
        {
            kraw[2 * a + 1].push_back(2 * b);
            kraw[2 * b + 1].push_back(2 * a);
            kraw[2 * a].push_back(2 * b + 1);
            kraw[2 * b].push_back(2 * a + 1);
        }
        else
        {
            kraw[2 * a].push_back(2 * b);
            kraw[2 * b].push_back(2 * a);
            kraw[2 * a + 1].push_back(2 * b + 1);
            kraw[2 * b + 1].push_back(2 * a + 1);
        }
    }

    for (int i = 2; i <= n * 2 + 1; i++)
    {
        if (!seen[i])
        {
            dfs(i);
            asdf++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (skladowa[i * 2] == skladowa[i * 2 + 1])
        {
            cout << "Impossible\n";
            return 0;
        }
        if (skladowa[i * 2] > skladowa[i * 2 + 1])
        {
            wynik.push_back(i);
        }
    }
    if (wynik.size() > n)
    {
        cout << "Impossible\n";
        return 0;
    }
    cout << wynik.size() << '\n';
    for (int x : wynik)
    {
        cout << x << ' ';
    }
    cout << '\n';
}