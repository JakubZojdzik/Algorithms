#include <bits/stdc++.h>
using namespace std;

string P, T;
int ps[1000007]; // tablica długości maksymalnych prefikso-sufiksów

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int y;
    cin >> y;
    while(y--)
    {
        int n;
        cin >> n;
        cin >> P >> T;
        if(P.size() > T.size()) continue;
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
}

/*
3
2
na
banananobano
6
foobar
foo
9
foobarfoo
barfoobarfoobarfoobarfoobarfoo




7
aabbaab
aabbaabasdksadaabbaabakdaabbaabaabbaabadsasd
1234567890123456789012345678901234567
0000000001111111111222222222233333333
       |         |      |  
*/