#include <bits/stdc++.h>
#include <chrono>
using namespace std;
typedef long long ll;

ll c;
int main()
{
    ll a = 2137420;
    ll b = 42069;

    auto start1 = chrono::steady_clock::now();
    for (int i = 0; i < 1e7; i++)
    {

        c = a - (a / b) * b;
    }
    auto end1 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds1 = end1 - start1;
    cout << "elapsed 1 time: " << elapsed_seconds1.count() << "s\n";

    c = 0;
    auto start2 = chrono::steady_clock::now();
    for (int i = 0; i < 1e7; i++)
    {
        c = a % b;
    }
    auto end2 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds2 = end2 - start2;
    cout << "elapsed 2 time: " << elapsed_seconds2.count() << "s\n";

    c = 0;
    auto start3 = chrono::steady_clock::now();
    for (int i = 0; i < 1e7; i++)
    {

        c = a - (a / b) * b;
    }
    auto end3 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds3 = end3 - start3;
    cout << "elapsed 1 time: " << elapsed_seconds3.count() << "s\n";

    c = 0;
    auto start4 = chrono::steady_clock::now();
    for (int i = 0; i < 1e7; i++)
    {
        c = a % b;
    }
    auto end4 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds4 = end4 - start4;
    cout << "elapsed 2 time: " << elapsed_seconds4.count() << "s\n";
}