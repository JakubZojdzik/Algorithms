#include <bits/stdc++.h>
using namespace std;

vector<int> kraw[100007];
bool odwiedzony[100007];
int n;

void dfs(int w)
{
    for(int i = 0; i < kraw[w].size(); i++)
    {
        if(!odwiedzony[kraw[w][i]])
        {
            dfs(kraw[w][i]);
        }
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    
    cin >> n;
    int a, b;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        kraw[a].push_back(b);
        kraw[b].push_back(a);
    }


}