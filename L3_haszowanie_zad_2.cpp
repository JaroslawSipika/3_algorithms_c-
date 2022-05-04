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


int c = 0;
void wstaw(string *tabelka, string s)
{
    tabelka[c] = s;
    c++;
}



int szukaj(string *tabelka, string s, Element *tablica[10])
{
    Element *o = new Element;
    for (int i=0; i<10; i++)
    {
        o = tablica[i];
        while (o)
        {
            if (o->data == s)
            {
                cout << "Pozycja w tabeli: ";
                return i;
            }
            o=o->next;
        }
    }
    cout << "Nie znaleziono: ";
    return false;
}


int main()
{

Element *tablica[10];
string tabelka[40];
Element *p;
Element *r;
bool t;


wstaw(tabelka, "Jaroslaw");
wstaw(tabelka, "Mikolaj");
wstaw(tabelka, "Edmund");
wstaw(tabelka, "Waldemar");
wstaw(tabelka, "Gracjan");
wstaw(tabelka, "Eugeniusz");
wstaw(tabelka, "Alojzy");

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

cout << szukaj(tabelka,"Jaroslaw",tablica) << endl;
cout << szukaj(tabelka,"Waldemar",tablica) << endl;
cout << szukaj(tabelka,"Mikolaj",tablica) << endl;
cout << szukaj(tabelka,"Eugeniusz",tablica) << endl;
cout << szukaj(tabelka,"Ksenia",tablica) << endl;
}

