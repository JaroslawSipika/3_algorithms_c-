#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


void wypelnianie_tablicy(int *tab, int n)
{
    srand((unsigned)time(nullptr));

    for (int i=0; i<n; i++)
    {
        tab[i]=rand()%100;
    }
}

void pokaz_tablice(int *tab, int n)
{
    for (int i=0; i<n; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
}

void sortowanie_przez_wstawianie(int *tab, int n)
{
    for (int i=1; i<n; i++)
    {
        int x = tab[i];
        int j = i-1;
        while (j>=0 && x<tab[j])
        {
            tab[j+1]=tab[j];
            j--;
        }
        tab[j+1]=x;

    }
}

int main()
{
    int rozmiar;
    cout << "Jak duza ma byc tablica?" << endl;
    cin >> rozmiar;

    int *wsk = new int[rozmiar];

    wypelnianie_tablicy(wsk, rozmiar);

    pokaz_tablice(wsk, rozmiar);


    sortowanie_przez_wstawianie(wsk, rozmiar);

    pokaz_tablice(wsk, rozmiar);


}


