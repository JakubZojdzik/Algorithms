#include <bits/stdc++.h>
using namespace std;

int parent[500007], setsz[500007];

void make_set(int v)
{
    parent[v] = v;
    setsz[v] = 1;
}

int find_set(int v)
{
    if(parent[v] == v) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    int ar = find_set(a);
    int br = find_set(b);
    if(ar != br)
    {
        if(setsz[ar] < setsz[br]) swap(ar, br);
        parent[br] = ar;
        setsz[ar] += setsz[br];
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    make_set(1);
    make_set(2);
    make_set(3);
    make_set(4);
    make_set(5);

    cout << find_set(3) << '\n';
    union_sets(1, 2);
    cout << find_set(2) << '\n';
    cout << find_set(1) << '\n';
}
