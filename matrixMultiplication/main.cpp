#include <bits/stdc++.h>
using namespace std;

int A[10007][10007], B[10007][10007], C[10007][10007];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n1, m1, n2, m2;
    cin >> n1 >> m1 >> n2 >> m2;
    if(m1 != n2)
        return 0;
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m1; j++)
            cin >> A[i][j];

    for (int i = 0; i < n2; i++)
        for (int j = 0; j < m2; j++)
            cin >> B[i][j];

    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m2; j++)
            for (int k = 0; k < m1; k++)
                C[i][j] += A[i][k] * B[k][j];

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            cout << C[i][j] << ' ';
        }
        cout << '\n';
    }
}

/*
3 4 4 5
1 2 3 4
5 6 7 8
9 8 7 6
4 3 2 1 2
3 4 5 6 7
8 9 8 7 6
5 4 3 2 1
*/