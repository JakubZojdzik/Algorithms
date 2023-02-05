#include <bits/stdc++.h>
using namespace std;

int ps[100007];

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    s = "aababaa";
    s = "!" + s;
    ps[0] = -1;
    int b = -1;
    for(int i = 1; i < int(s.size()); i++)
    {
        while(b > -1 && s[i] != s[b+1])
        {
            b = ps[b];
        }
        b++;
        ps[i] = b;
    }
}