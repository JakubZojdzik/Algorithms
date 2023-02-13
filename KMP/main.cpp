#include <bits/stdc++.h>
using namespace std;

int ps[500007];

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string a, b, x;
    cin >> a >> b;
    x = "!" + a + "#" + b;
    int n = int(x.size());
    int k = -1;
    ps[0] = -1;
    for(int i = 1; i < n; i++)
    {
        while(k >= 0 && x[i] != x[k+1])
        {
            k = ps[k];
        }
        k++;
        ps[i] = k;
    }

    for(int i = 0; i < n; i++)
    {
        if(ps[i] == int(a.size()))
        {
            cout << i - 2*int(a.size()) - 1 << ' ';
        }
    }
    cout << '\n';
}

/*
aaa
abcaaaancaancaaa

na
banananobano
*/