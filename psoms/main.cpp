#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class node
{
public:
    ll psoms, suma, l, r;
    node(int p=0, int s=0, int ll=0, int rr=0)
    {
        psoms = p;
        suma = s;
        l = ll;
        r = rr;
    }
};

node drzewo[3000007];
ll limit;

node aktualizuj(node k, node l)  // k po lewej, l po prawej xd
{
    node nowy;
    nowy.psoms = max(k.psoms, l.psoms);
    nowy.psoms = max(nowy.psoms, k.r+l.l);
    nowy.suma = k.suma + l.suma;
    nowy.l = max(k.l, k.suma+l.l);
    nowy.r = max(l.r, l.suma+k.r);
    return nowy;
}

void change(ll v, ll x)
{
    ll pkt = limit/2+v;
    drzewo[pkt] = node(x, x, max(x, ll(0)), max(x, ll(0)));
    while (pkt > 1)
    {
        pkt /= 2;
        drzewo[pkt] = aktualizuj(drzewo[2*pkt], drzewo[2*pkt+1]);
    }
    drzewo[1] = aktualizuj(drzewo[2], drzewo[3]);
}

ll query(ll a, ll b)
{
    if(a == b)
        return drzewo[limit/2+a].psoms;
    a += limit/2;
    b += limit/2;
    node wynik1 = drzewo[a];
    node wynik2 = drzewo[b];
    while(a/2 != b/2)
    {
        if(a%2 == 0)
        {
            wynik1 = aktualizuj(wynik1, drzewo[a+1]);
        }
        if(b%2 == 1)
        {
            wynik2 = aktualizuj(drzewo[b-1], wynik2);
        }
        a /= 2;
        b /= 2;
    }
    return aktualizuj(wynik1, wynik2).psoms;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;
    limit = 1;
    while(limit < n)
        limit *= 2;
    limit = limit*2-1;

    for(int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        drzewo[limit/2+i] = node(a, a, max(a, 0), max(a, 0));
    }
    for(int i = limit/2; i > 0; i--)
        drzewo[i] = aktualizuj(drzewo[i*2], drzewo[i*2+1]);
    cout << query(1, n) << "\n";
}