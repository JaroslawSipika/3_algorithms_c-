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
    double wynik;
    cout.precision(5);
    clock_t poczatek = clock();
    int counter=0;


    for (int i=1; i<n; i++)
    {
        int x = tab[i];
        int j = i-1;
        while (j>=0 && x<tab[j])
        {
            tab[j+1]=tab[j];
            j--;
            counter++;
        }
        tab[j+1]=x;
        counter++;

    }
    cout << "Liczba krokow: " << counter << endl;
    clock_t koniec = clock();
    wynik = (koniec-poczatek)/(double)CLOCKS_PER_SEC;
    cout<<"Czas wykonania: "<<wynik<<endl;
}

void sortowanie_przez_prosta_zamiane(int *tab, int n)
{

    double wynik;
    cout.precision(5);
    clock_t poczatek = clock();
    int counter=0;

    for (int i=1; i<n; i++)
    {
        for(int j=n-1; j>0; j--)
        {
            if(tab[j]<tab[j-1])
            {
                int x = tab[j-1];
                tab[j-1]=tab[j];
                tab[j]=x;
                counter++;
            }
        }
    }
    cout << "Liczba krokow: " << counter << endl;
    clock_t koniec = clock();
    wynik = (koniec-poczatek)/(double)CLOCKS_PER_SEC;
    cout<<"Czas wykonania: "<<wynik<<endl;
}

void sortowanie_przez_wybieranie(int *tab, int n)
{
    double wynik;
    cout.precision(5);
    clock_t poczatek = clock();
    int counter=0;

    for (int i=0; i<n-1; i++)
    {
        int min = i;
        for (int j=i+1; j<n; j++)
        {
            if(tab[j]<tab[min])
            {
                min = j;
            }
        }
        int x = tab[min];
        tab[min] = tab[i];
        tab[i] = x;
        counter++;
    }
    cout << "Liczba krokow: " << counter << endl;
    clock_t koniec = clock();
    wynik = (koniec-poczatek)/(double)CLOCKS_PER_SEC;
    cout<<"Czas wykonania: "<<wynik<<endl;
}

void sortowanie_szybkie(int *tab, int lewy, int prawy)
{
	if(prawy <= lewy) return;

	int i = lewy - 1;
	int j = prawy + 1;
	int pivot = tab[(lewy+prawy)/2];

	while(1)
	{
		while(pivot>tab[++i]);
		while(pivot<tab[--j]);
		if( i <= j)
			swap(tab[i],tab[j]);
		else
			break;
	}

	if(j > lewy)
	sortowanie_szybkie(tab, lewy, j);
	if(i < prawy)
	sortowanie_szybkie(tab, i, prawy);

}



int main()
{
    int rozmiar;
    cout << "Jak duza ma byc tablica?" << endl;
    cin >> rozmiar;

    int *wsk = new int[rozmiar];


    wypelnianie_tablicy(wsk, rozmiar);
    pokaz_tablice(wsk, rozmiar);
    cout << "SORTOWANIE PRZEZ PROSTE WSTAWIANIE" << endl;
    sortowanie_przez_wstawianie(wsk, rozmiar);
    pokaz_tablice(wsk, rozmiar);
    cout << endl;
    wypelnianie_tablicy(wsk, rozmiar);
    pokaz_tablice(wsk, rozmiar);
    cout << "SORTOWANIE PRZEZ PROSTA ZAMIANE" << endl;
    sortowanie_przez_prosta_zamiane(wsk, rozmiar);
    pokaz_tablice(wsk, rozmiar);
    cout << endl;
    wypelnianie_tablicy(wsk, rozmiar);
    pokaz_tablice(wsk, rozmiar);
    cout << "SORTOWANIE PRZEZ PROSTE WYBIERANIE" << endl;
    sortowanie_przez_wybieranie(wsk, rozmiar);
    pokaz_tablice(wsk, rozmiar);
    cout << endl;
    wypelnianie_tablicy(wsk, rozmiar);
    pokaz_tablice(wsk, rozmiar);
    cout << "SORTOWANIE SZYBKIE" << endl;
    sortowanie_szybkie(wsk, 0, rozmiar-1);
    pokaz_tablice(wsk, rozmiar);
}




