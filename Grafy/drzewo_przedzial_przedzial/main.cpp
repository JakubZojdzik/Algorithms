// Algorytm został napisany z pomocą strony http://www.algorytm.edu.pl/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll limit = 1;
ll suma[50000007];
ll obc[50000007]; // obciążenie

void add(int a, int b, int val)
{
    a += limit;
    b += limit;
    int dlugosc = 1;
    obc[a] += val;
    suma[a] += val;
    if (a != b)
    {
        obc[b] += val;
        suma[b] += val;
    }
    while (a > 0)
    {
        if (a < b - 1)
        {
            if (a % 2 == 0)
            {
                suma[a + 1] += val * dlugosc;
                obc[a + 1] += val;
            }
            if (b % 2 == 1)
            {
                suma[b - 1] += val * dlugosc;
                obc[b - 1] += val;
            }
        }

        if (b < limit)
        {
            suma[a] = suma[a * 2] + suma[a * 2 + 1] + obc[a] * dlugosc;
            suma[b] = suma[b * 2] + suma[b + 2 + 1] + obc[b] * dlugosc;
        }

        a >>= 1;
        b >>= 1;
        dlugosc <<= 1;
    }
}

int query(int a, int b)
{
    a += limit;
    b += limit;
    int dlugosc = 1, l = 1, r = 0;
    if (a != b)
        r = 1;
    ll wynik = 0;
    while (a > 0)
    {
        wynik += obc[a] * l + obc[b] * r;
        if (a < b - 1)
        {
            if (a % 2 == 0)
            {
                wynik += suma[a + 1];
                l += dlugosc;
            }
            if (b % 2 == 1)
            {
                wynik += suma[b - 1];
                r += dlugosc;
            }
        }
        a >>= 1;
        b >>= 1;
        dlugosc <<= 1;
    }
    return wynik;
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
    int q, option, a, b, c;
    cin >> q;
    while (q--)
    {
        cin >> option; //1 insert, 0 query
        if (option)
        {
            cin >> a >> b >> c;
            add(a, b, c);
        }
        else
        {
            cin >> a >> b;
            cout << query(a, b) << '\n';
        }
    }
}

/*
6 3
1 3 5 7
1 2 4 1
0 1 3
*/