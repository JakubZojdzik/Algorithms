#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll tree[2000007];
ll obc[2000007];
ll base = 1;

ll query(int p, int k, int v=1, int a=0, int b=base-1)
{
    if(a > k || b < p) return 0;
    if(a >= p && b <= k) return tree[v];
    int l = v<<1, r = l+1, mid = (a+b)>>1;
    tree[l] += obc[v] / 2;
    tree[r] += obc[v] / 2;
    obc[l] += obc[v] / 2;
    obc[r] += obc[v] / 2;
    obc[v] = 0;
    return query(p, k, l, a, mid) + query(p, k, r, mid+1, b);
}

void add(int p, int k, int x, int v=1, int a=0, int b=base-1)
{
    if(a > k || b < p) return;
    if(a >= p && b <= k)
    {
        tree[v] += (b-a+1) * x;
        obc[v] += (b-a+1) * x;
        return;
    }
    int l = v<<1, r = l+1, mid = (a+b)>>1;
    tree[l] += obc[v] / 2;
    tree[r] += obc[v] / 2;
    obc[l] += obc[v] / 2;
    obc[r] += obc[v] / 2;
    obc[v] = 0;
    add(p, k, x, l, a, mid);
    add(p, k, x, r, mid+1, b);
    tree[v] = tree[l] + tree[r];
}

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int n = 8;
    while(base < n)
        base <<= 1;

    cout << query(0, 7) << '\n';
    add(1, 4, 3);
    cout << query(0, 7) << '\n';
    add(0, 7, 1);
    cout << query(0, 7) << '\n';
    add(4, 4, -2);
    cout << query(0, 7) << '\n';
    add(3, 7, 5);
    cout << query(0, 7) << '\n';
}
