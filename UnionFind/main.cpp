#include <bits/stdc++.h>
using namespace std;

vector<int> zbior[100005];
int tab[100005];

int main()
{
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int liczb, zapytan;
    cin >> liczb >> zapytan;
    for(int i = 1; i <= liczb; i++)
    {
        tab[i] = i;
        zbior[i].push_back(i);
    }
    for(int i = 0; i < zapytan; i++)
    {
        string typ;
        int l1, l2;
        cin >> typ >> l1 >> l2;
        if(typ[0] == 'u')
        {
            if(zbior[tab[l2]].size() < zbior[tab[l1]].size()) swap(l1, l2); //tab[l1] jest mniejsze
            int z1 = tab[l1];
            int z2 = tab[l2];
            if(z1 == z2)
                continue;

            int roz = zbior[z1].size();
            for(int j = 0; j < roz; j++)
            {
                zbior[z2].push_back(zbior[z1][j]);
                tab[zbior[z1][j]] = tab[l2];
            }
        }
        else
        {
            if(tab[l1] == tab[l2])
                cout << "YES\n";
            else cout << "NO\n";
        }
        
    }
}

/*
4 4
union 1 2
union 1 3
get 1 4
get 2 3
*/