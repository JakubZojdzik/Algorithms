#include <bits/stdc++.h>
using namespace std;

long long wynik[107][1000007];
long long waga[107];
long long wartosc[107];

int main()
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long ile, pojemnosc;
    cin >> ile >> pojemnosc;
    for(int i = 1; i <= ile; i++)
    {
        cin >> waga[i] >> wartosc[i];
    }

    for(int i = 1; i <= ile; i++)
    {
        for(int j = 1; j <= pojemnosc; j++)
        {
            if(j-waga[i] >= 0)
                wynik[i][j] = max(wynik[i-1][j], wynik[i-1][j-waga[i]] + wartosc[i]);
            else
                wynik[i][j] = wynik[i-1][j];
        }
    }
    cout << wynik[ile][pojemnosc];
}
