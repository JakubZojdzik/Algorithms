#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll base = 1;
ll tree[2000007];
ll obc[2000007];

void add(int p, int k, int x, int v = 1, int a = 0, int b = base-1) // na przedziale [p, k] dodaj x, zaczynając od v który jest nad przedziałem [a, b]
{
    if(a > k || b < p) return;
    if(p <= a && k >= b)
    {
        tree[v] += (b-a+1) * x;
        obc[v] += (b-a+1) * x;
    }
    else
    {
        int l = v<<1, r = (v<<1)+1, mid = (a+b)>>1;
        tree[l] += obc[v] / 2;
        tree[r] += obc[v] / 2;
        obc[l] += obc[v]/2;
        obc[r] += obc[v]/2;
        obc[v] = 0;

        add(p, k, x, l, a, mid);
        add(p, k, x, r, mid+1, b);

        tree[v] = tree[l] + tree[r];
    }
}

ll query(int p, int k, int v = 1, int a = 0, int b = base-1) // na przedziale [p, k] dodaj x, zaczynając od v który jest nad przedziałem [a, b]
{
    if(a > k || b < p) return 0;
    if(p <= a && k >= b) return tree[v];
    else
    {
        int l = v<<1, r = (v<<1)+1, mid = (a+b)>>1;
        tree[l] += obc[v] / 2;
        tree[r] += obc[v] / 2;
        obc[l] += obc[v]/2;
        obc[r] += obc[v]/2;
        obc[v] = 0;

        return query(p, k, l, a, mid) + query(p, k, r, mid+1, b);
    }
}


int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    ll n = 8;
    // cin >> n;
    while(base < n)
        base <<= 1;
    
    add(1, 4, 3);
    add(0, 7, 1);
    add(4, 4, -2);
    add(3, 7, 5);
    cout << query(0, 7) << '\n';
}