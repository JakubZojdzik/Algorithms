#include <bits/stdc++.h> 
using namespace std; 

int table[5007][5007];

string LCS(string str1, string str2) 
{ 
    int m = str1.length();
    int n = str2.length();
    string lcs = "";
    int table[m+1][n+1]; 
    int i, j; 
    //length of lcs
    for(i = 0; i <= m; i++) 
    { 
        for(j = 0; j <= n; j++) 
        { 
            if (i == 0 || j == 0) 
                table[i][j] = 0;
            else if (str1[i-1] == str2[j-1]) 
                table[i][j] = 1 + table[i-1][j-1]; 
            else
                table[i][j] = max(table[i-1][j], table[i][j-1]); 
        } 
    } 
    
    //accual lcs
    i = m, j = n;
    while(i > 0 && j > 0)
    {
        if(str1[i-1] == str2[j-1])
        {
            lcs.push_back(str1[i-1]);
            i--;
            j--;
        }
        else if(table[i-1][j] > table[i][j-1])
            i--;
        else
            j--;
    }
    reverse(lcs.begin(),lcs.end());
    return lcs;
} 

int main() 
{ 
  string str1; 
  string str2;
  cin >> str1 >> str2;
  
  cout << LCS(str1, str2) << '\n';
} 