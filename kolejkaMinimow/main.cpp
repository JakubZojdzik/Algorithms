#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

deque<pair<ll, ll>> K;

void push_element(ll x)
{
    ll cnt = 0;
    while(!K.empty() && K.back().first >= x)
    {
        cnt += K.back().second + 1;
        K.pop_back();
    }
    K.push_back(make_pair(x, cnt));
}

void pop_element()
{
    if(K.front().second == 0)
        K.pop_front();
    else
        K.front().second--;
}

ll min_element()
{
    return K.front().first;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    push_element(5);
    cout << min_element() << '\n';
    push_element(3);
    cout << min_element() << '\n';
    push_element(4);
    cout << min_element() << '\n';
    push_element(1);
    cout << min_element() << '\n';
    push_element(5);
    push_element(4);
    push_element(8);
    push_element(4);
    push_element(6);
    push_element(8);
    push_element(9);
    push_element(8);
    cout << min_element() << '\n';
    cout << "ZACZYNAM USUWANIE\n";
    pop_element();
    cout << min_element() << '\n';
    pop_element();
    cout << min_element() << '\n';
    pop_element();
    cout << min_element() << '\n';
    pop_element();
    cout << min_element() << '\n';
    pop_element();
    cout << min_element() << '\n';
    pop_element();
    cout << min_element() << '\n';
    pop_element();
    cout << min_element() << '\n';
    pop_element();
    cout << min_element() << '\n';
    pop_element();
    cout << min_element() << '\n';
    pop_element();
    cout << min_element() << '\n';
    pop_element();
    cout << min_element() << '\n';
    pop_element();
    cout << min_element() << '\n';
}