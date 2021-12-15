#include <bits/stdc++.h>
using namespace std;

vector<int> krawedzie[100007];
queue<int> kolejka;
int ile_laczen[100007];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ile_wierz, ile_kraw;
    cin >> ile_wierz >> ile_kraw;
    for(int i = 1; i <= ile_kraw; i++)
    {
        int a, b;
        cin >> a >> b;
        krawedzie[a].push_back(b);
        ile_laczen[b]++;
    }

    for(int i = 1; i <= ile_wierz; i++)
    {
        if(ile_laczen[i] == 0)
        {
            kolejka.push(i);
        }
    }
    while(!kolejka.empty())
    {
        int teraz = kolejka.front();
        kolejka.pop();
        for(int i = 0; i < krawedzie[teraz].size(); i++)
        {
            ile_laczen[krawedzie[teraz][i]]--;
            if(ile_laczen[krawedzie[teraz][i]] <= 0)
            {
                kolejka.push(krawedzie[teraz][i]);
            }
        }
    }
}

/*
test:
15 15
7 12
5 13
9 10
8 13
9 4
12 1
2 10
12 14
12 13
6 5
15 14
1 13
8 6
3 15
11 2

poprawna odpowiedz:
11 9 8 7 12 6 5 4 3 15 14 2 10 1 13
*/