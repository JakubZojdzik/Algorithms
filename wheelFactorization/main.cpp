#include <bits/stdc++.h>
#include <chrono>
using namespace std;
typedef long long ll;

vector<int> factors;
vector<int> temp = {37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 121, 127, 131, 137, 139, 143, 149, 151, 157, 163, 167, 169, 173, 179, 181, 187, 191, 193, 197, 199, 209, 211};
int inc[] = {2, 4, 2, 4, 6, 2, 6};

void wheel(ll n)
{
    while (n % 2 == 0)
    {
        factors.push_back(2);
        n /= 2;
    }
    while (n % 3 == 0)
    {
        factors.push_back(3);
        n /= 3;
    }
    while (n % 5 == 0)
    {
        factors.push_back(5);
        n /= 5;
    }
    ll k = 7;
    ll i = 0;
    while (k * k <= n)
    {
        if (n % k == 0)
        {
            factors.push_back(k);
            n /= k;
        }
        else
        {
            k += inc[i];
            i = (i + 1) % 8;
        }
    }
    if (n > 1)
    {
        factors.push_back(n);
    }
}

void primeFactors(ll n)
{
    while (n % 2 == 0)
    {
        factors.push_back(2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n = n / i;
        }
    }
    if (n > 2)
        factors.push_back(n);
}

int main()
{
    // chrono::steady_clock sc;
    // auto start = sc.now();

    // wheel(1000000000000000000);

    // auto end = sc.now();
    // auto time_span = static_cast<chrono::duration<double>>(end - start);
    // cout << "Wheel factorization took: " << time_span.count() << " seconds\n";
    // factors.clear();

    // start = sc.now();

    // primeFactors(1000000000000000000);

    // end = sc.now();
    // time_span = static_cast<chrono::duration<double>>(end - start);
    // cout << "Normal factorization took: " << time_span.count() << " seconds\n";

    for (int i = 0; i < temp.size()-1; i++)
    {
        cout << temp[i+1] - temp[i] << ", "
    }
}