#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll tab[200007];
ll tree[50000007];
ll limit = 1;

void change(ll v, ll x)
{
    ll add = x - tab[v];
    tab[v] = x;
    ll pkt = limit+v;
    while(pkt > 1)
    {
        tree[pkt] += add;
        pkt >>= 1;
    }
    tree[1] += add;
}

ll query(ll a, ll b)
{
    ll wynik = tab[a] + tab[b];
    if(a == b)
    {
        return tab[a];
    }
    a = limit+a;
    b = limit+b;
    while((a>>1) != (b>>1))
    {
        if(a%2 == 0)
        {
            wynik += tree[a+1];
        }
        if(b%2 == 1)
        {
            wynik += tree[b-1];
        }
        a >>= 1;
        b >>= 1;
    }
    return wynik;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll n, q, type, a, b;
    cin >> n >> q;
    
    while (limit <= n)
    {
        limit <<= 1;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> tab[i];
        tree[limit+i] = tab[i];
    }

    for(int i = limit; i > 0; i--)
    {
        tree[i] = tree[2*i] + tree[2*i+1];
    }
    for(int i = 0; i < q; i++)
    {
        cin >> type >> a >> b;
        if(type == 1)
        {
            change(a, b);
        }
        else
        {
            cout << query(a, b) << "\n";
        }
    }
}

/*
8 10
10 9 6 10 10 3 6 7
2 8 8
1 1 6
1 2 5
1 3 7
1 4 4
1 5 6
1 6 2
1 7 7
1 8 7
2 1 1
*/