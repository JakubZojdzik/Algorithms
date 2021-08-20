#include <bits/stdc++.h>
using namespace std;

long long skok[1000007];
long long n;
long long modulo = 1000000007;
vector<string> nazwa;

long long nww(long long a, long long b)
{
    long long pocz1 = b;
    long long pocz2 = a;
	while(b)
		swap(a %= b, b);
	return ((pocz1*pocz2)/a)%modulo;
}

long long nww_tab(long long tab[], long long n)
{
    int wynik = tab[0];
    for(int i = 1; i < n; i++)
    {
        wynik = nww(tab[i], wynik);
        if(wynik == 1)
        {
            return 1;
        }
    }
    return wynik;
}


int main(int argc, char** argv)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    nazwa.assign(argv+1, argv+2);

    ifstream inFile(nazwa[0]+".in");
    inFile >> n;
    for(long long i = 0; i < n; i++)
    {
        inFile >> skok[i];
    }
    inFile.close();

    ofstream outFile(nazwa[0]+".out");
    outFile << nww_tab(skok, n) << "\n";
    outFile.close();
}