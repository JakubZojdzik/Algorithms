#include <bits/stdc++.h>
using namespace std;
typedef __int128 lint;

lint read()
{
    lint x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void print(lint x)
{
    if (x < 0)
    {
        cout << '-';
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    cout << char(x % 10 + '0');
}

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    
    lint a, b;
    a = read();
    b = read();
    
    if(a > b)
    {
        print(a);
        cout << " > ";
        print(b);
        cout << '\n';
    }
    else
    {
        print(a);
        cout << " < ";
        print(b);
        cout << '\n';
    }
}

/*
123456789012345678901234567890
987654321009876543210987654321

*/