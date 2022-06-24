#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class rlint
{
public:
    vector<int> value;
    rlint(int v);
    rlint(long long v);
    rlint();
    rlint operator=(const rlint &b);
    rlint operator=(const int &b);
    rlint operator=(const long long &b);
    bool operator==(const rlint &b);
    bool operator>(const rlint &b);
    bool operator<(const rlint &b);
    bool operator>=(const rlint &b);
    bool operator<=(const rlint &b);
    rlint operator+(const rlint &b);
    rlint operator-(const rlint &b);
    rlint operator*(const rlint &b);
    rlint operator/(const int &b);
    void operator+=(const rlint &b);
    void operator-=(const rlint &b);
    void operator*=(const rlint &b);
    void operator/=(const int &b);
    rlint operator++();
    rlint operator--();
    rlint operator++(int);
    rlint operator--(int);
};

rlint::rlint(int v = 0)
{
    value.push_back(v);
}

rlint::rlint(ll v)
{
    value.push_back(v % ((ll)1 << 31));
    value.push_back(v >> 31);
}

rlint::rlint()
{
    value.push_back(0);
}

rlint rlint::operator=(const rlint &b)
{
    value = b.value;
    return *this;
}

rlint rlint::operator=(const int &b)
{
    value.push_back(b);
    return *this;
}

rlint rlint::operator=(const long long &v)
{
    value.clear();
    value.push_back(v % ((ll)1 << 31));
    value.push_back(v >> 31);
    return *this;
}

bool rlint::operator==(const rlint &b)
{
    return (value == b.value);
}

bool rlint::operator>(const rlint &b)
{
    if (value.size() != b.value.size())
    {
        return (value.size() > b.value.size());
    }
    for (int i = b.value.size() - 1; i >= 0; i--)
    {
        if (value[i] != b.value[i])
        {
            return (value.size() > b.value.size());
        }
    }
    return false;
}

bool rlint::operator<(const rlint &b)
{
    rlint xd = b;
    return xd > *this;
}

bool rlint::operator>=(const rlint &b)
{
    rlint xd = b;
    return !(xd < b);
}

bool rlint::operator<=(const rlint &b)
{
    rlint xd = b;
    return !(xd > b);
}

rlint rlint::operator+(const rlint &b)
{
    vector<int> qwertz = b.value, ztrewq = value;
    rlint res(0);
    ll curr_res;

    if (value.size() < b.value.size())
        swap(qwertz, ztrewq);

    for (int i = ztrewq.size(); i < qwertz.size(); i++)
        ztrewq.push_back(0);

    for (int i = 0; i < qwertz.size(); i++)
    {
        curr_res = (ll)qwertz[i] + (ll)ztrewq[i];
        res.value[i] += (curr_res % ((ll)1 << 31));
        res.value.push_back(curr_res >> 31);
    }
    if(res.value.size()>1 && res.value[res.value.size()-1] == 0) res.value.pop_back();
    return res;
}

int main()
{
    rlint a(1234567890);

    for (int i = 0; i < 65; i++)
        a = a + a;
    for (int i : a.value)
        cout << i << ' ';
}