#include <iostream>
using namespace std;

struct Element
{
    int value;
    Element *next;
};

Element *stos = NULL;

void push(int v)
{
    Element *new1 = new Element;
    new1->value=v;
    new1->next=stos;
    stos=new1;
}

int pop ()
{
    int liczba = stos->value;
    Element *tmp = new Element;
    tmp = stos;
    stos = stos->next;
    delete tmp;
    return liczba;
}

void show()
{
    Element *tmp1 = new Element;
    tmp1 = stos;
    while (tmp1)
    {
        cout << tmp1->value;
        tmp1 = tmp1->next;
    }
    cout << endl;
}

int main()
{
    push(1);
    show();
    push(3);
    show();
    push(5);
    show();
    push(7);
    show();
    pop();
    show();
    pop();
    show();
    push(2);
    show();
    push(4);
    show();
    push(6);
    show();
    push(8);
    show();
    push(10);
    show();
    pop();
    show();
    pop();
    show();
    pop();
    show();
    pop();
    show();
    pop();
    show();
    pop();
    show();
}
