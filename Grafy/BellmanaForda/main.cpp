// Algorytm został napisany z pomocą strony http://algorytmy.ency.pl/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<tuple<int, int, int>> kraw;
int koszt[500007], poprzedni[500007];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        kraw.push_back(make_tuple(a, b, c));
    }
    int pocz = 1;
    for (int i = 1; i <= n; i++)
    {
        koszt[i] = INT_MAX;
    }
    koszt[pocz] = 0;
    bool mod;
    for (int i = 0; i < n - 1; i++)
    {
        mod = false;
        for (auto k : kraw)
        {
            if (koszt[get<1>(k)] > koszt[get<0>(k)] + get<2>(k))
            {
                koszt[get<1>(k)] = koszt[get<0>(k)] + get<2>(k);
                poprzedni[get<1>(k)] = get<0>(k);
                mod = true;
            }
        }
        if(!mod)
            break;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "koszt = " << koszt[i] << ", pop = " << poprzedni[i] << '\n';
    }

}

/*
5 7
1 2 2
1 3 4
2 3 3
2 4 3
3 4 -1
4 5 2
3 5 4
*/