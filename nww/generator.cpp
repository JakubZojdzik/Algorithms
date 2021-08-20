#include <bits/stdc++.h>
using namespace std;

int tab[1000007];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    const long long n = 1000000;
    string komenda = "";
    for(int k = 15; k >= 1; k--)
    {
        for(int l = 0; l < 3; l++)
        {
            long long ile = int(n / k);
            string nazwa = "zab" + to_string(k);
            nazwa += 'a' + l;

            ofstream wejscie(nazwa + ".in");
            wejscie << ile << "\n";

            for(int i = 0; i < ile; i++)
            {
                tab[i] = rand() % 10000000 + 1;
                wejscie << tab[i] << "\n";
            }
            komenda += "./main " + nazwa + ";";
        }
    }
    komenda.pop_back();
    system(komenda.c_str());
}