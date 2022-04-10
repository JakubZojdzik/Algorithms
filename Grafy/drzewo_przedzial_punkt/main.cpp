// Algorytm został napisany z pomocą strony http://www.algorytm.edu.pl/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll tree[50000007];
ll limit = 1;

void add(int a, int b, int val)
{
    a += limit;
    b += limit;
    tree[a] += val;
    if(a != b)
        tree[b] += val;
    while((a>>1) != (b>>1))
    {
        if(a%2 == 0)
            tree[a + 1] += val;
        if(b%2 == 1)
            tree[b - 1] += val;
        a >>= 1;
        b >>= 1;
    }
}

int query(int n)
{
    n += limit;
    int w = 0;
    while (n > 0)
    {
        w += tree[n];
        n >>= 1;
    }
    return w;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    while (limit <= n)
    {
        limit <<= 1;
    }
    int m, a, b, c;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        if (a == 0) // dodanie do [b; c] wartosc a
        {
            cin >> a;
            add(b, c, a);
        }
        else // zapytanie o wierzcholek b
        {
            cout << query(b) << '\n';
        }
    }
}