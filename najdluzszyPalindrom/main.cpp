// kod napisany przy pomocy strony https://www.geeksforgeeks.org/
#include <bits/stdc++.h>
using namespace std;

string longestPalSubstr(char *str)
{
    int maxLength = 1;
    int start = 0;
    int len = strlen(str);
    int low, high;
    for (int i = 1; i < len; ++i)
    {
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            --low;
            ++high;
        }
        ++low;
        --high;
        if (str[low] == str[high] && high - low + 1 > maxLength)
        {
            start = low;
            maxLength = high - low + 1;
        }
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            --low;
            ++high;
        }
        ++low;
        --high;
        if (str[low] == str[high] && high - low + 1 > maxLength)
        {
            start = low;
            maxLength = high - low + 1;
        }
    }
    string w;
    while (maxLength--)
        w += str[start++];

    return w;
}

int main()
{
    char str[] = "forgeeksskeegfor";
    cout << "\nLength is: " << longestPalSubstr(str) << '\n';
}