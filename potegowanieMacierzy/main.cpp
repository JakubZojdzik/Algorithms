#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long A[1007][1007], B[1007][1007], temp[1007][1007], wynik[1007][1007];
int n, pot;

void jeden(ll (&tab)[1007][1007])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == j)
                tab[i][j] = 1;
            else
                tab[i][j] = 0;
        }
    }
}

void mnoz(ll (&x)[1007][1007], ll (&y)[1007][1007], ll (&rez)[1007][1007])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            wynik[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                wynik[i][j] += x[i][k] * y[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rez[i][j] = wynik[i][j];
        }
    }
}

void macPow(int pot)
{
    jeden(B);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = A[i][j];
        }
    }
    int aktu = 0;
    int wartpot = 0;
    while (pot > 0)
    {
        if(pot & 1)
        {
            while (aktu < wartpot)
            {
                mnoz(temp, temp, temp);
                aktu++;
            }
            mnoz(temp, B, B);
        }
        pot >>= 1;
        wartpot++;
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> pot;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    macPow(pot);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << B[i][j] << ' ';
        }
        cout << "\n";
    }
    cout << '\n';
}

/*
3 7
3 5 1
2 3 1
4 4 3
*/