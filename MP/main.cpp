#include <bits/stdc++.h>
using namespace std;

string P, T;
int ps[1000007]; // tablica długości maksymalnych prefikso-sufiksów

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> P >> T;
    int n = int(P.size());
    if(P.size() > T.size()) return 0;
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
        i = i+j-ps[j];
        j = max(0, ps[j]);
    }
}

/*
na
banananobano
*/