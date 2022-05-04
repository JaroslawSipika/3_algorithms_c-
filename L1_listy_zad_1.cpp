#include <iostream>
using namespace std;

struct Element
{
    int wartosc;
    Element *next;
};

Element *head = NULL;


void addFront(int v)
{
    Element *nowy = new Element;
    nowy -> wartosc = v;
    nowy -> next = head;
    head = nowy;
}

void printLista()
{
    Element *tmp = head;

    while(tmp)
    {
        cout << tmp->wartosc << " ";
        tmp = tmp->next;
    }
}

void clearLista()
{
   Element *tmp = new Element;
   while (head)
   {
       tmp = head;
       head = head -> next;
       delete tmp;
   }
}


int main()
{

    addFront(5);
    addFront(7);
    addFront(6);
    addFront(4);
    addFront(3);
    addFront(3);
    addFront(5);
    addFront(7);
    addFront(9);
    printLista();
    clearLista();
    printLista();

}
