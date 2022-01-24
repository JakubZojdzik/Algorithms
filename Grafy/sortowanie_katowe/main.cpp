#include <bits/stdc++.h>
using namespace std;

pair<int, int> punkty[1000007];
int X0 = 1;
int Y0 = 0;

inline bool na_lewo(int x, int y)
{
    return !(X0 * y - x * Y0 < 0 || (X0 * y - x * Y0 == 0 && X0 * x + Y0 * y > 0));
}

bool porownaj(pair<int, int> v1, pair<int, int> v2) // czy v1 jest mniejsze?
{
    bool a = na_lewo(v1.first, v1.second);
    bool b = na_lewo(v2.first, v2.second);
    if(a != b) return a;
    else return (v1.first * v2.second - v2.first * v1.second > 0);
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        punkty[i] = make_pair(a, b);
    }
    sort(punkty, punkty + n, porownaj);
    for (int i = 0; i < n; i++)
    {
        cout << punkty[i].first << " " << punkty[i].second << '\n';
    }
}
