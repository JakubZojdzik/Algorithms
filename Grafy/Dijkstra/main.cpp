#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> sasiedzi[1007];
priority_queue<pair<int, int>> kolejka;
int tab[1007];
int poprzednik[1007];

void dijkstra(int pocz)
{
    kolejka.push(make_pair(0, pocz)); //pierwszy element na kolejke
    while(!kolejka.empty())
    {
        int wierzcholek = kolejka.top().second; //numer wierzcholka ktorym sie zajmujemy
        int odl = tab[wierzcholek]; //odleglosc od wierzcholka poczatkowego do aktualnego wierzcholka
        if(odl != -kolejka.top().first) //nie jest to optymalny wierzcholek to wywalamy go i idziemy dalej
        {
            kolejka.pop();
            continue;
        }
        for(int i = 0; i < sasiedzi[wierzcholek].size(); i++) //idziemy po wszystkich sasiadach tego wierzcholka
        {
            if(odl + sasiedzi[wierzcholek][i].second < tab[sasiedzi[wierzcholek][i].first]) //znalezlismy nowa optymalna droge od pocz do sasiada
            {
                poprzednik[sasiedzi[wierzcholek][i].first] = wierzcholek;
                tab[sasiedzi[wierzcholek][i].first] = odl + sasiedzi[wierzcholek][i].second; //zmieniamy wartosc w tab[sasiad wierzcholka] (tablicy optymalnych wartosci pocz-wierz)
                kolejka.push(make_pair(-1 * tab[sasiedzi[wierzcholek][i].first], sasiedzi[wierzcholek][i].first)); //dodajemy tego sasiada do kolejki
            }
        }
        kolejka.pop(); //wywalamy wierzcholek z kolejki
    }
}

int main()
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int ile_kraw, ile_wierz;
    cin >> ile_wierz >> ile_kraw;
    int pocz = 1;
    for(int i = 1; i <= ile_wierz; i++)
    {
        tab[i] = INT_MAX;
    }
    tab[pocz] = 0;
    for(int i = 0; i < ile_kraw; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        sasiedzi[a].push_back(make_pair(b, w));
        sasiedzi[b].push_back(make_pair(a, w));
    }
    dijkstra(pocz);
    int ile_testow;
    cin >> ile_testow;
    int testy[ile_testow];
    for(int i = 0; i < ile_testow; i++)
    {
        cin >> testy[i];
    }
    string wynik;
    cout << endl;
    for(int i = 0; i < ile_testow; i++)
    {
        wynik = "";
        int teraz = testy[i];
        while(teraz != pocz)
        {
            wynik = to_string(teraz) + " " + wynik;
            teraz = poprzednik[teraz];
        }
        cout << wynik << endl;
    }
}

/*
7 10
1 2 2
2 3 3
2 4 2
2 5 5
3 5 1
4 5 2
5 7 1
5 6 5
6 7 2
1 6 10
3
3
6
2
*/
