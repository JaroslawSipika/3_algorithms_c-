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
    for (int i=0; i<=n; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
}

void sortowanie(int *tab, int n)
{
    for (int i=n; i>0; i--)
    {
        int p = tab[0];
        tab[0] = tab[i];
        tab[i] = p;
        n--;
        zatapianie(tab,0,n);
    }
}


int main ()
{

    int tab[11] = {15,9,8,10,11,2,5,3,7,11,12};
    odczyt(tab,10);
    zatapianie(tab,1,10);
    odczyt(tab,10);
    zatapianie(tab,1,10);
    odczyt(tab,10);

    sortowanie(tab,10);
    odczyt(tab,10);

}
