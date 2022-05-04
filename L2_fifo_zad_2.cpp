#include <iostream>
using namespace std;

struct Element
{
    int wartosc;
    Element *next;
};

Element *head = NULL;


void enqueue(int v)
{
    Element *nowy = new Element;
    nowy -> wartosc = v;
    nowy -> next = 0;

    if (head == NULL)
    {
        head = nowy;
    }

    else
    {
        Element *tmp = new Element;
        tmp = head;
        while(tmp->next)
        {
            tmp=tmp->next;
        }
        tmp->next=nowy;
    }

}

void wypisz()
{
    Element *tmp = new Element;
    tmp = head;
    while(tmp)
    {
        cout << tmp->wartosc << " ";
        tmp = tmp -> next;
    }
cout << endl;
}

int dequeue ()
{
    if (head!=NULL)
    {
        Element *tmp = new Element;
        tmp = head;
        head = head -> next;
        delete tmp;
    }
}

int main()
{

enqueue (1);
wypisz();
enqueue (3);
wypisz();
enqueue (5);
wypisz();
enqueue (7);
wypisz();
dequeue();
wypisz();
dequeue();
wypisz();
enqueue (2);
wypisz();
enqueue (4);
wypisz();
enqueue (6);
wypisz();
enqueue (8);
wypisz();
enqueue (10);
wypisz();
dequeue();
wypisz();
dequeue();
wypisz();
dequeue();
wypisz();
dequeue();
wypisz();
dequeue();
wypisz();
dequeue();
wypisz();
}
