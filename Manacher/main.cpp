#include <bits/stdc++.h>
using namespace std;

int R[2][1000007];

int main()
{
    string s;
    cin >> s;
    int N = s.size();
    int i, rp, k;

    s = "@" + s + "#";

    for (int t = 0; t <= 1; t++)
    {
        R[t][0] = 0;
        rp = 0;
        i = 1;
        while (i <= N)
        {
            while (s[i - rp - 1] == s[i + t + rp])
                rp++;
            R[t][i] = rp;
            k = 1;
            while ((R[t][i - k] != rp - k) && (k < rp))
            {
                R[t][i + k] = min(R[t][i - k], rp - k);
                k++;
            }
            rp = max(rp - k, 0);
            i += k;
        }
    }

    s = s.substr(1, N);

    for (i = 1; i <= N; i++)
    {
        for (int j = 0; j <= 1; j++)
            for (rp = R[j][i]; rp > 0; rp--)
            {
                for (k = 1; k < i - rp; k++)
                    cout << " ";
                cout << s.substr(i - rp - 1, 2 * rp + j) << endl;
            }
    }
    cout << endl;
}