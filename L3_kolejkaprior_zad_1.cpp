#include <iostream>
using namespace std;


void zatapianie(int *tab, int i, int n)
{
    int left = 2*i+1;
    int right = 2*i+2;
    int wiekszy;

    if (left <= n && tab[left]>tab[i])
    {
        wiekszy = left;
    }
    else
    {
        wiekszy = i;
    }
    if (right <= n && tab[right]>tab[wiekszy])
    {
        wiekszy = right;
    }
    if (wiekszy != i)
    {
        int p = tab[wiekszy];
        tab[wiekszy]=tab[i];
        tab[i]=p;
        zatapianie(tab, wiekszy, n);
    }

}

void wynurzanie(int *tab, int i, int n)
{
    if (i>0)
    {
        int ojciec = (i-1)/2;
        if (tab[i]>tab[ojciec])
        {
            int p = tab[ojciec];
            tab[ojciec] = tab[i];
            tab[i]=p;
            wynurzanie(tab, ojciec, n);
        }
    }
}

void odczyt(int *tab, int n)
{
    for (int i=0; i<n; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
}

/*void sortowanie(int *tab, int n)
{
    for (int i=n; i>0; i--)
    {
        cout << i << endl;
        int p = tab[0];
        tab[0] = tab[i];
        tab[i] = p;
        n--;
        zatapianie(tab,0,n);
    }
}*/

bool isEmpty(int *tab)
{
    if (tab[0]==0)
    {
        return true;
    }
}

void insertKol(int *tab,int &n, int v)
{
    tab[n] = v;
    wynurzanie(tab, n, n);
    n++;
}

int extractKol(int *tab, int &n)
{
    if (n<=0)
    {
        cout << "Kolejka pusta" << endl;
    }
    else
    {
        int temp = tab[0];
        tab[0] = tab[n];
        tab[n] = temp;
        n--;
        zatapianie(tab, 0, n);
        return temp;
    }

}


int main ()
{

    int rozmiar = 0;
    int n = 0;
    int tab[8] = {};
    odczyt(tab,rozmiar);
   // cout << isEmpty << endl;
    insertKol(tab,rozmiar, 25);
    odczyt(tab,rozmiar);
    insertKol(tab,rozmiar, 18);
    odczyt(tab,rozmiar);
    insertKol(tab,rozmiar, 15);
    odczyt(tab,rozmiar);
    insertKol(tab,rozmiar, 9);
    odczyt(tab,rozmiar);
    insertKol(tab,rozmiar, 4);
    odczyt(tab,rozmiar);

    insertKol(tab,rozmiar, 20);
    odczyt(tab,rozmiar);
    cout<< extractKol(tab,rozmiar) << endl;
    odczyt(tab,rozmiar);
    cout<< extractKol(tab,rozmiar) << endl;
    odczyt(tab,rozmiar);
}

