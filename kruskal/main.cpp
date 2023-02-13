#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> edges;
vector<tuple<int, int, int>> result;
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
    a = find_set(a);
    b = find_set(b);
    if(a != b)
    {
        if(height[a] < height[b]) swap(a, b);
        parent[b] = a;
        if(height[a] == height[b]) height[a]++;
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, a, b, c;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        edges.push_back({c, a, b}); // undirected
    }
    for(int i = 1; i <= n; i++)
    {
        make_set(i);
    }

    sort(edges.begin(), edges.end());
    int wei = 0;
    for(auto e : edges)
    {
        if(find_set(get<1>(e)) != find_set(get<2>(e)))
        {
            wei += get<0>(e);
            result.push_back(e);
            union_sets(get<1>(e), get<2>(e));
        }
    }
    cout << wei << '\n';
}

/*
3 3
1 2 1
2 3 2
1 3 3
*/