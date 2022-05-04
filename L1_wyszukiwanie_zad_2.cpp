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

int binSearch (int *tab, int n, int s)
{
    int ip = 0;
    int ik = n-1;
    int p;
    int counter = 0;

    while (ip <= ik)
    {
        int isr=(ip+ik)/2;
        counter++;
        if (s==tab[isr])
        {
            p = isr;
            cout << "Liczba wykonanych krokow: ";
            return counter;
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
    cout << "Liczba wykonanych krokow: ";
    return counter;
}

int intSearch(int *tab, int n, int s)
{
    int ip = 0;
    int ik = n-1;
    int p;
    int counter = 0;
    while ((tab[ip] <= s) && (s <= tab[ik]))
    {
        counter++;
        int isr=ip+(s-tab[ip])*(ik-ip)/(tab[ik]-tab[ip]);

        if (s==tab[isr])
        {
            p = isr;
            cout << "Liczba wykonanych krokow: ";
            return counter;
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
    cout << "Liczba wykonanych krokow: ";
    return counter;
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
    cout << binSearch(wsk, rozmiar, szukana) << endl;
    cout << intSearch(wsk, rozmiar, szukana) << endl;

    odczyt_tablicy(wsk, rozmiar);


}

