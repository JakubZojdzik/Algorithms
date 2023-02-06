#include <bits/stdc++.h>
using namespace std;

int parent[500007];
int height[500007];

int find(int x)
{
    if(parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unit(int x, int y)
{
    int xset = find(x);
    int yset = find(y);
    if(xset == yset)
        return;

    if(height[xset] < height[yset])
    {
        swap(xset, yset);
    }
    parent[yset] = xset;
    if(height[xset] == height[yset])
        height[xset]++;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n = 10;
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    cout << find(3) << '\n';
    unit(4, 3);
    cout << find(3) << '\n';
    unit(2, 1);
    cout << find(3) << '\n';
    unit(2, 5);
    unit(2, 6);
    unit(6, 7);
    cout << find(3) << '\n';
    unit(4, 5);
    cout << find(3) << '\n';
    cout << find(1) << '\n';
}