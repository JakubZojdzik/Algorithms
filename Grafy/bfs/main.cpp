#include <bits/stdc++.h>
using namespace std;

vector<int> kraw[100007];
vector<int> kol;
bool odwiedzony[100007];

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    int a, b;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        kraw[a].push_back(b);
        kraw[b].push_back(a);
    }
    kol.push_back(1);
    odwiedzony[1] = true;

    // zwykly najzwyklejszy bfs
    for(int i = 0; i < kol.size(); i++)
    {
        int w = kol[i];
        // TUTAJ TRZYMAMY I-TY WIERZCHOŁEK GRAFU W ZMIENNEJ 'w'
        for(int j = 0; j < kraw[w].size(); j++)
        {
            if(!odwiedzony[kraw[w][j]])
            {
                kol.push_back(kraw[w][j]);
                odwiedzony[kraw[w][j]] = true;
            }
        }
    }
    // koniec
    kol.clear();
    for(int i = 0; i <= n; i++)
    {
        odwiedzony[i] = 0;
    }


    // bfs z zapamietywaniem wiersza w ktorym jestesmy
    int wiersz = 1;
    while(true)
    {
        int s = kol.size();
        for(int i = 0; i < s; i++)
        {
            int w = kol[0];
            kol.pop_back();
            // TUTAJ TRZYMAMY I-TY WIERZCHOŁEK GRAFU W ZMIENNEJ 'w' ZNAJDUJĄCY SIĘ W WIERSZU 'wiersz'
            for(int j = 0; j < kraw[w].size(); j++)
            {
                if(!odwiedzony[kraw[w][j]])
                {
                    kol.push_back(kraw[w][j]);
                    odwiedzony[kraw[w][j]] = true;
                }
            }
            
        }
        wiersz++;
    }
}