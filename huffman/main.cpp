#include <bits/stdc++.h>
using namespace std;

class node //węzeł z grafu
{
public:
    int id;
    float wartosc;
    char znak;
    int nad;
    int wyzszy;
    node(float w = 0, int i = -1, char z = '\0', int n = -1) //czestotliwosc, znak, wartosc na krawedzi nad
    {
        wartosc = w;
        nad = n;
        znak = z;
        id = i;
    }

    bool operator<(node & ref_node)
    {
        return this->wartosc < ref_node.wartosc;
    }

    bool operator>(node & ref_node)
    {
        return this->wartosc > ref_node.wartosc;
    }

    node operator+(node & ref_node);
};

void printBinary(char); //wypisuje chara w binarce
inline int pos(char); //pozycja w alfabecie do wstawienia w czestotliwosc
void sortuj_drzewo(int, int); //sortowanie grafu
int printFromTree(char); //wypisuje skompresowana binarke
string tnij(string); //usuwa powtarzające się znaki

node drzewo[1000007];
int licznik;

//////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    float czestotliwosc[] = {8.2, 1.5, 2.8, 4.3, 13.0, 2.2, 2.0, 6.1, 7.0, 0.15, 0.77, 4.0, 2.4, 
                            6.7, 7.5, 1.9, 0.095, 6.0, 6.3, 9.1, 2.8, 0.98, 2.4, 0.15, 2.0, 0.074}; //0 - a, 34 - z. Brak liter wielkich i polskich
    string a = "Linux jest systemem wielokrotnie lepszym od systemu operacyjnego windows";
    int dlugosc1 = a.size() * 8;
    string gotowy = tnij(a);
    licznik = gotowy.size();
    cout << "\nOryginal dla slowa " << a << ":\n";
    for(int i = 0; i < a.size(); i++)
    {
        printBinary(a[i]);
        cout << "  ";
    }
    for(int i = 0; i < gotowy.size(); i++)
    {
        drzewo[i] = node(czestotliwosc[pos(gotowy[i])], i, gotowy[i]);
    }
    bool dalej = true;
    while(dalej)
    {
        sortuj_drzewo(0, licznik-1);
        int pom = 0;
        int pier, drug;
        for(int i = 0; i < licznik; i++)
        {
            if(drzewo[i].nad == -1)
            {
                if(pom == 0)
                    pier = i;
                if(pom == 1)
                    drug = i;
                pom++;
                if(pom == 2)
                {
                    drzewo[licznik] = drzewo[pier] + drzewo[drug];
                    drzewo[licznik].id = licznik;
                    drzewo[pier].wyzszy = licznik; 
                    drzewo[drug].wyzszy = licznik;
                    licznik++;
                    break;
                }
            }
        }
        if(pom <= 1)
            dalej = false;
    }

    //wypisywanie wyniku
    cout << "\n\nForma skompresowana:\n";
    int dlugosc2 = 0;
    for(int i = 0; i < a.size(); i++)
    {
        dlugosc2 += printFromTree(a[i]);
        cout << " ";
    }
    cout << "\n\n";
    cout << "Zastosowanie kodowania Huffmana zaoszczedzilo " << dlugosc1-dlugosc2 << " bitow, co przyczynilo sie do zmniejszenia wagi napisu o " << int(float(float(dlugosc1-dlugosc2)/dlugosc1)*100) << "%\n\n";
}

///////////////////////////////////////////////////////////////////////////////


inline int pos(char c)
{
    return int(tolower(c)) - 97;
}

void printBinary(char c) {
    for (int i = 7; i >= 0; --i) {
        std::cout << ((c & (1 << i))? '1' : '0');
        if(i == 4) cout << "-";
    }
}

void sortuj_drzewo(int lewy, int prawy)
{
    if(prawy <= lewy) return;
	int i = lewy - 1, j = prawy + 1;
	node pivot = drzewo[(lewy+prawy)/2];
	while(1)
	{
		while(pivot>drzewo[++i]);
		while(pivot<drzewo[--j]);
		if( i <= j)
			swap(drzewo[i],drzewo[j]);
		else
			break;
	}
	if(j > lewy)
	    sortuj_drzewo(lewy, j);
	if(i < prawy)
	    sortuj_drzewo(i, prawy);
}

int printFromTree(char a)
{
    node startowy;
    int liczba = 0;
    for(int i = 0; i < licznik; i++)
    {
        if(drzewo[i].znak == a)
        {
            startowy = drzewo[i];
            break;
        }
    }
    while(startowy.nad != -1)
    {
        cout << startowy.nad;
        liczba++;
        for(int i = 0; i < licznik; i++)
        {
            if(drzewo[i].id == startowy.wyzszy)
            {
                startowy = drzewo[i];
                break;
            }
        }
    }
    return liczba;
}

string tnij(string napis)
{
    int index = 0;    
    int a = 0;
    for(int i = 0; i < napis.size(); i++) 
    { 
        int j;   
        for (j = 0; j < i; j++)  
            if (napis[i] == napis[j]) 
            {
                a++;
                break; 
            }
        if(j == i)
            napis[index++] = napis[i]; 
    } 
    napis.resize(napis.size()-a);
    return napis; 
}

node node::operator+(node & ref_node)
{
    node wynik(this->wartosc + ref_node.wartosc);
    if(this->wartosc < ref_node.wartosc)
    {
        this->nad = 0;
        ref_node.nad = 1;
    }
    else
    {
        this->nad = 1;
        ref_node.nad = 0;
    }
    return wynik;
}

//Jakub Żojdzik klasa 1A
//cpp lepszy, w pythonie nie dalo by sie zrobic choc troche tak ladnego kodu
//Pozdrawiam