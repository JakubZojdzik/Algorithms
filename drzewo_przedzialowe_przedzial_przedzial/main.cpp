#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll limit;
ll tree[2000007];
ll tree2[2000007];
ll tab[100007];

void add(int v, int a, int b, int p, int k, int x)
{
    if(k<a || p>b) 
    {
        return;
    }
    else if(p <= a && b <= k)
    {
        tree[v] += (b-a+1) * x;
        tree2[v] += (b-a+1) * x;
    }
    else
    {
        int l = v<<1, r = (v<<1)+1, mid = (a+b)>>1;
        tree[l] += tree2[v]>>1;
        tree[r] += tree2[v]>>1;
        tree2[l] += tree2[v]>>1;
        tree2[r] += tree2[v]>>1;
        tree2[v] = 0;

        add(l, a, mid, p, k, x);
        add(r, mid+1, b, p, k, x);

        tree[v] = tree[l] + tree[r];
    }
}

ll query(int v, int a, int b, int p, int k)
{
    if(k<a || p>b)
        return 0;
    else if(p <= a && b <= k)
        return tree[v];
    else
    {
        int l = v<<1, r = (v<<1)+1, mid = (a+b)>>1;
        tree[l] += tree2[v]>>1;
        tree[r] += tree2[v]>>1;
        tree2[l] += tree2[v]>>1;
        tree2[r] += tree2[v]>>1;
        tree2[v] = 0;

        return query(l, a, mid, p, k) + query(r, mid+1, b, p, k);
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll n, q;
    cin >> n >> q;
    limit = 1;
    while(limit < n)
    {
        limit *= 2;
    }
    limit = limit*2-1;
    for(int i = 1; i <= n; i++)
    {
        cin >> tab[i];
        tree[limit/2+i] = tab[i];
    }
    for(int i = limit/2; i >= 1; i--)
    {
        tree[i] = tree[i*2] + tree[(i*2)+1];
    }

    char a;
    int b, c, d;
    for(int i = 0; i < q; i++)
    {
        cin >> a >> b >> c;
        if(a == 'q')
        {
            cout << query(1, 1, n, b, c) << "\n";
        }
        else
        {
            cin >> d;
            add(1, 1, n, b, c, d);
        }
    }
}

/*
8 7
1 2 3 4 0 8 1 7
q 3 5
q 1 8
a 5 8 1
a 3 7 3
q 2 6
a 4 4 56
q 4 6
*/