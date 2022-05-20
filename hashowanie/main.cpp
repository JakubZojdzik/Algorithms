#include <bits/stdc++.h>
using namespace std;

// "Mam bardzo długi kod, ale jest fajny lubię go" ~ Jakub Żółdzik

long long sumy[1000007];
constexpr int mod = 1000000007;
long long potegi[1000009];

bool czy_rowne(long long p1, long long k1, long long p2, long long k2)
{
   if(p1 > p2)
   {
      swap(p1, p2);
      swap(k1, k2);
   }
   long long pier;
   long long drug;
   if(p1-1 >= 0)
      pier = sumy[k1] - sumy[p1-1];
   else
      pier = sumy[k1];

   if(p2-1 >= 0)
      drug = sumy[k2] - sumy[p2-1];
   else
      drug = sumy[k2];

   if(pier < 0)
      pier += mod;
   if(drug < 0)
      drug += mod;
   return (pier * static_cast<long long>(potegi[p2-p1]) % mod == drug % mod);
}

int main()
{
   cin.tie(NULL);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   string napis;
   cin >> napis;
   potegi[0] = 1;
   for(int i = 1; i < 1000009; i++)
   {
      potegi[i] = (potegi[i-1] * 31) % mod;
   }

   sumy[0] = int(napis[0])-'a'+1;
   for(int i = 1; i < napis.size(); i++)
   {
      sumy[i] = (sumy[i-1] + ((napis[i] - 'a' + 1) * potegi[i])) % mod;
   }
   int q;
   cin >> q;
   for(int p = 0; p < q; p++)
   {
      long long pocz1, kon1, pocz2, kon2;
      cin >> pocz1 >> kon1 >> pocz2 >> kon2;
      pocz1--;
      kon1--;
      pocz2--;
      kon2--;
      long long r1 = kon1 - pocz1+1;
      long long r2 = kon2 - pocz2+1;

      if(r1 < r2)
      {
         if(czy_rowne(pocz1, kon1, pocz2, pocz2+r1-1))
         {
            cout << "MNIEJSZY\n";
            continue;
         }
         else
         {
            kon2 = pocz2+r1-1;
            r2 = r1;
         }
      }
      else if(r1 > r2)
      {
         if(czy_rowne(pocz1, pocz1+r2-1, pocz2, kon2))
         {
            cout << "WIEKSZY\n";
            continue;
         }
         else
         {
            kon1 = pocz1+r2-1;
            r1 = r2;
         }
      }
      if(czy_rowne(pocz1, kon1, pocz2, kon2))
      {
         cout << "ROWNY\n";
         continue;
      }
      long long pocz = -1;
      long long kon = r1-1;
      while(pocz+1 < kon)
      {
         long long srod = (pocz+kon)/2;
         if(czy_rowne(pocz1, pocz1 + srod, pocz2, pocz2 + srod))
         {
            pocz = srod + 1;
         }
         else
         {
            kon = srod;
         }
         srod = (pocz+kon)/2;
      }
      int odp = kon;
      if(czy_rowne(pocz1, pocz1+pocz, pocz2, pocz2 + pocz) == false) odp = pocz;

      if(napis[pocz1+odp] > napis[pocz2+odp])
      {
         cout << "WIEKSZY\n";
      }
      else
      {
         cout << "MNIEJSZY\n";
      }
   }
}
