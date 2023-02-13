#include <bits/stdc++.h>
using namespace std;

int parent[500007], height[500007];

void make_set(int v)
{
    parent[v] = v;
    height[v] = 0;
}

int find_set(int v)
{
    if(parent[v] == v) return v;
    return find_set(parent[v]);
}

void union_sets(int a, int b)
{
    int ar = find_set(a);
    int br = find_set(b);
    if(ar != br)
    {
        if(height[ar] < height[br]) swap(ar, br);
        parent[br] = ar;
        if(height[ar] == height[br]) height[ar]++;
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