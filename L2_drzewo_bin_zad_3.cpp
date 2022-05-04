#include <iostream>
using namespace std;

class Drzewo{
    private:
        int *wsk;
        int index = 1;
    public:
        int rozmiar = 15;
        int ustaw_lewego(int);
        int ustaw_prawego(int);
        void dodajWezel(int *, int);
        void preorder(int);
        void inorder(int);
        void postorder(int);
        void wyswietltablice();
};

void Drzewo::dodajWezel(int *tab, int v)
{
    wsk = tab;
    wsk[index] = v;
    index++;
}

void Drzewo::wyswietltablice()
{
    for (int i=1; i<index; i++)
    {
        cout << wsk[i] << endl;
    }
}

int Drzewo::ustaw_lewego(int index)
{
    if (wsk[index]!=0 && (2*index<=rozmiar))
    {
            return 2*index;
    }
    return -1;
}

int Drzewo::ustaw_prawego(int index)
{
    if (wsk[index]!=0 && (((2*index))+1<=rozmiar))
    {
            return (2*index)+1;
    }
    return -1;
}

void Drzewo::preorder(int index)
{
    if (index > 0 && wsk[index]!=0)
    {
        cout << wsk[index] << " ";
        preorder(ustaw_lewego(index));
        preorder(ustaw_prawego(index));
    }
}

void Drzewo::inorder(int index)
{
    if (index > 0 && wsk[index]!=0)
    {
        inorder(ustaw_lewego(index));
        cout << wsk[index] << " ";
        inorder(ustaw_prawego(index));
    }
}

void Drzewo::postorder(int index)
{
    if (index > 0 && wsk[index]!=0)
    {
        postorder(ustaw_lewego(index));
        postorder(ustaw_prawego(index));
        cout << wsk[index] << " ";
    }
}


int main()
{
    Drzewo drzewko1;
    int *wsk = new int[drzewko1.rozmiar];

    int wartosc;
    wartosc = 3;
    drzewko1.dodajWezel(wsk, wartosc);
    wartosc = 8;
    drzewko1.dodajWezel(wsk, wartosc);
    wartosc = 5;
    drzewko1.dodajWezel(wsk, wartosc);
    wartosc = 1;
    drzewko1.dodajWezel(wsk, wartosc);
    wartosc = 0;
    drzewko1.dodajWezel(wsk, wartosc);
    wartosc = 2;
    drzewko1.dodajWezel(wsk, wartosc);
    wartosc = 4;
    drzewko1.dodajWezel(wsk, wartosc);
    wartosc = 0;
    drzewko1.dodajWezel(wsk, wartosc);
    wartosc = 9;
    drzewko1.dodajWezel(wsk, wartosc);
    wartosc = 0;
    drzewko1.dodajWezel(wsk, wartosc);
    wartosc = 0;
    drzewko1.dodajWezel(wsk, wartosc);
    wartosc = 7;
    drzewko1.dodajWezel(wsk, wartosc);
    wartosc = 0;
    drzewko1.dodajWezel(wsk, wartosc);
    wartosc = 0;
    drzewko1.dodajWezel(wsk, wartosc);
    wartosc = 3;
    drzewko1.dodajWezel(wsk, wartosc);


    drzewko1.preorder(1);
    cout << endl;
    drzewko1.inorder(1);
    cout << endl;
    drzewko1.postorder(1);

}
