#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

deque<pair<ll, ll>> kol;

void push(ll x)
{
    ll cnt = 0;
    while(!kol.empty() && kol.back().first >= x)
    {
        cnt += kol.back().second + 1;
        kol.pop_back();
    }
    kol.push_back({x, cnt});
}

void pop()
{
    if(kol.front().second == 0) kol.pop_front();
    else kol.front().second--;
}

ll top()
{
    return kol.front().first;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    push(1);
    push(5);
    pop();
    cout << top() << '\n';
    push(2);
    push(3);
    cout << top() << '\n';
    pop();
    pop();
    cout << top() << '\n';
}