#include <bits/stdc++.h>
using namespace std;

int last[1000];

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string wzo, s;
    cin >> wzo >> s;

    for(int i = 'a'; i <= 'z'; i++)
        last[i] = -1;

    for(int i = 0; i < int(wzo.size()); i++)
        last[wzo[i]] = i;

    int p = 0;
    vector<int> wyst;
    while(p + int(wzo.size()) <= int(s.size()))
    {
        int jest = p;
        int q = int(wzo.size())-1;
        while(q > -1 && wzo[q] == s[p+q]) q--;

        if(q == -1)
        {
            wyst.push_back(p);
            p++;
        }
        else
        {
            p += max(1, q - last[s[p+q]]);
        }
    }

    for(int poz : wyst)
    {
        cout << poz << " ";
    }
    cout << '\n';
}