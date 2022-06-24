#include <bits/stdc++.h>
using namespace std;

// Klasa powstała z pomocą kodów znajdujących się na stronie https://www.geeksforgeeks.org/
class lint // lint = large int ;)
{
public:
    string value;
    lint();
    lint(string v);
    lint(int v);
    lint(long long v);
    lint operator=(const lint &b);
    lint operator=(const int &b);
    lint operator=(const long long &b);
    bool operator==(const lint &b);
    bool operator>(const lint &b);
    bool operator<(const lint &b);
    bool operator>=(const lint &b);
    bool operator<=(const lint &b);
    void repair();
    lint operator+(const lint &b);
    lint operator-(const lint &b);
    lint operator*(const lint &b);
    lint operator/(const int &b);
    void operator+=(const lint &b);
    void operator-=(const lint &b);
    void operator*=(const lint &b);
    void operator/=(const int &b);
    lint operator++();
    lint operator--();
    lint operator++(int);
    lint operator--(int);
};

lint::lint()
{
    value = "0";
}

lint::lint(string v)
{
    value = v;
    if (value == "")
        value = "0";
    repair();
}

lint::lint(int v)
{
    value = to_string(v);
}

lint::lint(long long v)
{
    value = to_string(v);
}

lint lint::operator=(const lint &b)
{
    value = b.value;
    repair();
    return *this;
}

lint lint::operator=(const int &b)
{
    value = to_string(b);
    return *this;
}

lint lint::operator=(const long long &b)
{
    value = to_string(b);
    return *this;
}

bool lint::operator==(const lint &b)
{
    return (value == b.value);
}

bool lint::operator>(const lint &b)
{
    if (value.length() != b.value.length())
        return (value.length() > b.value.length());
    for (int i = 0; i < value.length(); i++)
        if (value[i] > b.value[i])
            return true;
        else if (value[i] < b.value[i])
            return false;
    return false;
}

bool lint::operator<(const lint &b)
{
    if (value.length() != b.value.length())
        return (value.length() < b.value.length());
    for (int i = 0; i < value.length(); i++)
        if (value[i] < b.value[i])
            return true;
        else if (value[i] > b.value[i])
            return false;
    return false;
}

bool lint::operator>=(const lint &b)
{
    if (value.length() != b.value.length())
        return (value.length() > b.value.length());
    for (int i = 0; i < value.length(); i++)
        if (value[i] > b.value[i])
            return true;
        else if (value[i] < b.value[i])
            return false;
    return true;
}

bool lint::operator<=(const lint &b)
{
    if (value.length() != b.value.length())
        return (value.length() < b.value.length());
    for (int i = 0; i < value.length(); i++)
        if (value[i] < b.value[i])
            return true;
        else if (value[i] > b.value[i])
            return false;
    return true;
}

lint lint::operator+(const lint &b)
{
    string str1 = value;
    string str2 = b.value;
    if (str1.length() > str2.length())
        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i = 0; i < n1; i++)
    {
        int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    for (int i = n1; i < n2; i++)
    {
        int sum = ((str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    if (carry)
        str.push_back(carry + '0');
    reverse(str.begin(), str.end());
    return lint(str);
}

lint lint::operator-(const lint &b)
{
    string str1 = value;
    string str2 = b.value;
    if (*this < b)
        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i = 0; i < n2; i++)
    {
        int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
        str.push_back(sub + '0');
    }
    for (int i = n2; i < n1; i++)
    {
        int sub = ((str1[i] - '0') - carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
        str.push_back(sub + '0');
    }
    reverse(str.begin(), str.end());
    return lint(str);
}

lint lint::operator*(const lint &b)
{
    string num1 = value;
    string num2 = b.value;
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
        return lint("0");
    vector<int> result(len1 + len2, 0);
    int i_n1 = 0;
    int i_n2 = 0;
    for (int i = len1 - 1; i >= 0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0;
        for (int j = len2 - 1; j >= 0; j--)
        {
            int n2 = num2[j] - '0';
            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;
            carry = sum / 10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }

        if (carry > 0)
            result[i_n1 + i_n2] += carry;
        i_n1++;
    }

    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;
    if (i == -1)
        return lint("0");
    string s = "";
    while (i >= 0)
        s += std::to_string(result[i--]);
    return lint(s);
}

lint lint::operator/(const int &b)
{
    string number = value;
    string ans;
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < b)
        temp = temp * 10 + (number[++idx] - '0');
    while (number.size() > idx)
    {
        ans += (temp / b) + '0';
        temp = (temp % b) * 10 + number[++idx] - '0';
    }

    if (ans.length() == 0)
        return lint("0");
    return lint(ans);
}

void lint::operator+=(const lint &b)
{
    *this = *this + b;
}

void lint::operator-=(const lint &b)
{
    *this = *this - b;
}

void lint::operator*=(const lint &b)
{
    *this = *this * b;
}

void lint::operator/=(const int &b)
{
    *this = *this / b;
}

lint lint::operator++()
{
    *this = *this + lint("1");
    repair();
    return *this;
}

lint lint::operator--()
{
    *this = *this - lint("1");
    repair();
    return *this;
}

lint lint::operator++(int)
{
    lint temp = *this;
    repair();
    ++*this;
    return temp;
}

lint lint::operator--(int)
{
    lint temp = *this;
    repair();
    --*this;
    return temp;
}

ostream &operator<<(std::ostream &os, lint const &m)
{
    return os << m.value;
}

ostream &operator>>(std::ostream &os, lint const &m)
{
    return os >> m.value;
}

void lint::repair()
{
    if (value == "0")
        return;
    for (int i = 0; i < value.size(); i++)
    {
        if (value[i] != '0')
            break;
        value.erase(0, 1);
    }
}

int main()
{
    auto a = lint(15);
    auto b = lint(2);
    b += a;
    a += b;
    cout << a << ", " << b << '\n';
}