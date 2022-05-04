#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void wypelnianie_tablicy(int *tab, int n)
{
    srand((unsigned)time(nullptr));

    for (int i=0; i<n; i++)
    {
        tab[i]=rand()%10;
    }
}

void odczyt_tablicy(int*tab, int n)
{
    for (int i=0; i<n; i++)
    {
        cout << tab[i] << endl;
    }
}

int linSearch(int*tab, int n, int s)
{
    int i = 0;
    while ((i<=n))
    {
        if(tab[i]==s)
        {
            cout << "Indeks szukanej liczby: " << endl;
            return i;
        }
        else
            i++;
    }
    cout << "Nie znaleziono" << endl;
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
    cout << "Jakiej liczby szukasz" << endl;
    cin >> szukana;
    linSearch(wsk, rozmiar, szukana);

    odczyt_tablicy(wsk, rozmiar);

}
