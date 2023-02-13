#include <bits/stdc++.h>
using namespace std;

string P, T;
int ps[1000007]; // tablica długości maksymalnych prefikso-sufiksów

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> P >> T;
    int n = int(P.size());
    P = "!" + P;
    T = "!" + T;
    int k = -1;
    ps[0] = -1;
    for(int i = 1; i <= n; i++)
    {
        while(k >= 0 && P[k+1] != P[i])
        {
            k = ps[k];
        }
        k++;
        ps[i] = k;
    }
    int i = 0, j = 0;
    while(i <= T.size() - n)
    {
        while(j < n && P[j+1] == T[i+j+1])
        {
            j++;
        }
        if(j == n)
        {
            cout << i << '\n';
        }
        i += j-ps[j];
        j = max(0, ps[j]);
    }
}

/*
na
banananobano
*/