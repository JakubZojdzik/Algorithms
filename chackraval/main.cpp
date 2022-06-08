#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

struct trojka
{
    ll x, y, k;
    trojka(ll xinp = 0, ll yinp = 0, ll kinp = 0) : x(xinp), y(yinp), k(kinp) {}
};
ll D;
vector<trojka> trojki;

int main()
{
    cout << "Podaj D: ";
    cin >> D;

    trojka curr1(0, 0, 0), curr2(0, 0, 0);
    curr1.y = 1;
    curr2.y = 1;
    curr1.x = ll(sqrt(D));
    curr2.x = ll(ceil(sqrt(D)));

    curr1.k = curr1.x * curr1.x - D * curr1.y * curr1.y;
    curr2.k = curr2.x * curr2.x - D * curr2.y * curr2.y;
    trojki.push_back(curr1);
    trojki.push_back(curr2);
    if (__gcd(trojki[0].x, trojki[0].y) != 0)
    {
        int nwd = __gcd(trojki[0].x, trojki[0].y);
        trojki[0].x /= nwd;
        trojki[0].y /= nwd;
        trojki[0].k /= nwd * nwd;
    }
    if (__gcd(trojki[1].x, trojki[1].y) != 0)
    {
        int nwd = __gcd(trojki[1].x, trojki[1].y);
        trojki[1].x /= nwd;
        trojki[1].y /= nwd;
        trojki[1].k /= nwd * nwd;
    }

    ll w, m;
    int nrtrojki1, nrtrojki2;
    trojka jed, dwa;
    while (1)
    {
        for (int i = 0; i < trojki.size(); i++)
        {
            cout << i << ": (" << trojki[i].x << ", " << trojki[i].y << ", " << trojki[i].k << ")\n";
        }
        if (trojki[trojki.size() - 1].k == 1)
        {
            cout << "BRAWO! Przykładowe rozwiązania równania x^2 - " << D << "y^2 = 1 to x = " << trojki[trojki.size() - 1].x << "; y = " << trojki[trojki.size() - 1].y << '\n';
            return 0;
        }
        cout << "\nCo chcesz wykonać?\n";
        cout << "1. Połącz dwie dwójki\n";
        cout << "2. Zastosuj wzór redukujący\n";
        cout << "3. Użyj wzoru Brahmagupta (k = {-1; +-2; +-4})\n";

        cin >> w;
        switch (w)
        {
        case 1:
            cout << "Wybierz trojki do polaczenia\n";
            cin >> nrtrojki1 >> nrtrojki2;
            jed = trojki[nrtrojki1];
            dwa = trojki[nrtrojki2];
            trojki.push_back(trojka(jed.x * dwa.x + D * jed.y * dwa.y, jed.x * dwa.y + jed.y * dwa.x, jed.k * dwa.k));
            break;
        case 2:
            cout << "Wybierz trojkę do uproszczenia\n";
            cin >> nrtrojki1;
            jed = trojki[nrtrojki1];
            cout << "Podaj takie m, że " << jed.k << " dzieli (" << jed.x << " + " << jed.y << " * m)\n";
            m = -1;
            for (int i = 0; i <= abs(jed.k); i++)
                if ((jed.x + jed.y * i) % jed.k == 0)
                    if (m == -1 || abs(m * m - D) > abs(i * i - D))
                        m = i;
            cout << "Proponowane m = " << m << '\n';
            cin >> m;
            if ((jed.x + jed.y * m) % jed.k == 0)
                trojki.push_back(trojka((jed.x * m + D * jed.y) / jed.k, (jed.x + jed.y * m) / jed.k, (m * m - D) / jed.k));
            else
                cout << "Niepoprawne m\n";
            break;

        case 3:
            cout << "Wybierz trojkę\n";
            cin >> nrtrojki1;
            jed = trojki[nrtrojki1];
            if (jed.k == -1)
            {
                trojki.push_back(trojka(2 * jed.x * jed.x - jed.k, 2 * jed.x * jed.y, 1));
            }
            else if (jed.k == -2)
            {
                trojki.push_back(trojka(jed.x * jed.x + 1, jed.x * jed.y, 1));
            }
            else if (jed.k == 2)
            {
                trojki.push_back(trojka(jed.x * jed.x - 1, jed.x * jed.y, 1));
            }
            else if (jed.k == 4)
            {
                if (jed.x % 2 == 0)
                {
                    trojki.push_back(trojka((jed.x * jed.y) / 2, (jed.x * jed.x - 2) / 2, 1));
                }
                else
                {
                    trojki.push_back(trojka((jed.x / 2) * (jed.x * jed.x - 3), (jed.y / 2) * (jed.x * jed.x - 1), 1));
                }
            }
            else if (jed.k == -4)
            {
                trojki.push_back(trojka(((jed.x * jed.x + 2) * ((jed.x * jed.x + 1) * (jed.x * jed.x + 3) - 2)) / 2, (jed.x * jed.y * (jed.x * jed.x + 3) * (jed.x * jed.x + 1)) / 2));
            }
            break;
        }
        if (__gcd(trojki[trojki.size() - 1].x, trojki[trojki.size() - 1].y) != 0)
        {
            int nwd = __gcd(trojki[trojki.size() - 1].x, trojki[trojki.size() - 1].y);
            trojki[trojki.size() - 1].x /= nwd;
            trojki[trojki.size() - 1].y /= nwd;
            trojki[trojki.size() - 1].k /= nwd * nwd;
        }
        system(CLEAR);
    }
}