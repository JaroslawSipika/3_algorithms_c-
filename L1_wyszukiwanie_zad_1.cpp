#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void wypelnianie_tablicy(int *tab, int n)
{
    tab[0]=rand()%n;
    for (int i=1; i<n; i++)
    {
        tab[i]=tab[i-1]+rand()%n;
    }
}

void odczyt_tablicy(int*tab, int n)
{
    for (int i=0; i<n; i++)
    {
        cout << tab[i] << endl;
    }
}

int intSearch(int *tab, int n, int s)
{
    int ip = 0;
    int ik = n-1;
    int p;

    while ((tab[ip] <= s) && (s <= tab[ik]))
    {
        int isr=ip+(s-tab[ip])*(ik-ip)/(tab[ik]-tab[ip]);

        if (s==tab[isr])
        {
            p = isr;
            cout << "Znaleziono liczbe pod indeksem: ";
            return isr;
        }

        else if (s<tab[isr])
        {
            ik = isr-1;
        }

        else
        {
            ip = isr+1;
        }
    }
    return -1;
}

int main()
{
    int rozmiar;
    cout << "Podaj rozmiar tablicy" << endl;
    cin >> rozmiar;

    int *wsk = new int[rozmiar];

    wypelnianie_tablicy(wsk, rozmiar);

    int szukana;
    cout << "Jakie liczby szukasz" << endl;
    cin >> szukana;
    cout << intSearch(wsk, rozmiar, szukana) << endl;

    odczyt_tablicy(wsk, rozmiar);

}
