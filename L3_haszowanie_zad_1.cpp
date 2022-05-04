#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
using namespace std;

struct Element
{
    Element *next;
    string data;
};


unsigned int hasz(string s)
{
    unsigned int h;
    unsigned int i;

    h = 0;

    for (i=0; i<s.length(); i++)
    {
        h=31*h+s[i]-65;
    }
    return h%10;
}

int main()
{

Element *tablica[10];
string tabelka[40];
Element *p;
Element *r;
bool t;

    fstream plik;
    plik.open("haszowanie.txt", ios::in);

    if (plik.good()==false)
    {
        cout << "Plik nie istnieje!";
        exit(0);
    }

    int numerlinii = 0;
    string linia;

    while(getline(plik,linia))
    {
        tabelka[numerlinii] = linia;
        numerlinii++;
    }

    plik.close();


/*for (int i=0; i<40; i++)
{
    cout << tabelka[i] << endl;
}
*/

for (int i=0; i<10; i++)
{
    tablica[i] = NULL;
}

for (int i=0; i<40; i++)
{
    int h;
    h = hasz(tabelka[i]);
    p = tablica[h];
    t = true;

    if( p )
      while( true )
      {
        if( p->data == tabelka[i] )
        {
          t = false;
          break;
        }
        if( !p->next ) break;
        p = p->next;
      }

    if(t)
    {
        r = new Element;
        r->data = tabelka[i];
        r->next = NULL;
        if(!p)
        {
            tablica[h] = r;
        }
        else
        {
            p ->next = r;
        }
    }
}

for (int i=0; i<10; i++)
{
    cout << "T [ "<< i << " ] =" ;
    p = tablica[i];
    while (p)
    {
        cout << p->data << " ";
        p=p->next;
    }
    cout << endl;
}


}
