#include <bits/stdc++.h>
using namespace std;

constexpr int M = 2e5+7;
long long fenwick[M];

void add(int v, int x)
{
    if(v < 1)
    {
        cout << "ERROR\n";
        exit(420);
    }
    while(v < M)
    {
        fenwick[v] += x;
        v += v&(-v); //v&(-v) to wartość 2^lsb(v)
    }
}

long long query(int v)
{
    long long w = 0;
    while(v)
    {
        w += fenwick[v];
        v -= v&(-v);
    }

    return w;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s;
    int n, q, v, x, a, b;
    cin >> n >> q;
    while(q--)
    {
        cin >> s;
        if(s == "add")
        {
            cin >> v >> x;
            add(v, x);
            cout << "Dodano x=" << x << " do v=" << v << "\n"; 
        }
        else if(s == "query")
        {
            cin >> a >> b;
            cout << "suma[" << a << "," << b << "]=" << query(b) - query(a-1) << "\n";
        }
    }
}