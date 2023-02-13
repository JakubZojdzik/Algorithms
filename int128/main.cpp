#include <bits/stdc++.h>
using namespace std;
typedef __int128 lint;

lint readlint()
{
    lint a = 0, b = 1;
    char c = getchar();
    if(c == '-')
    {
        b = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9')
    {
        a = 10*a + c - '0';
        c = getchar();
    }
    return a * b;
}

void printlint(lint x)
{
    if(x < 0)
    {
        cout << "-";
        x = -x;
    }
    if(x > 9)
        printlint(x / 10);
    cout << char(x % 10 + '0');
}

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    lint a, b;
    a = readlint();
    b = readlint();

    lint c = a+b;
    printlint(c);
    cout << '\n';
}

/*

*/