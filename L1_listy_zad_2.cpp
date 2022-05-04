#include <iostream>
using namespace std;

struct Element
{
    int wartosc;
    Element *next;
};

Element *head = nullptr;


void printLista()
{
    Element *tmp = head;

    while(tmp)
    {
        cout << tmp->wartosc << " ";
        tmp = tmp->next;
    }
}

void addinOrder(int v)
{
    Element *nowy = new Element;

    if (head != NULL)
    {

        if (v > head->wartosc )
        {
            nowy -> wartosc = v;
            nowy -> next = head;
            head = nowy;
        }

        else
        {

            Element *po = head;
            Element *przed = NULL;


            while(po->wartosc>=v)
            {

                po = po -> next;
                if(po==nullptr)
                {
                    break;
                }
            }

            nowy -> wartosc = v;

            przed -> next = nowy;
            nowy -> next = po;

        }
    }

    else
    {
        nowy -> wartosc = v;
        nowy -> next = head;
        head = nowy;
    }

}

void delByVal(int v)
{
    Element *tmp1 = head;
    Element *tmp2 = NULL;

    while (v!=tmp1->wartosc)
    {
        tmp2 = tmp1;
        tmp1 = tmp1->next;

    }


    tmp2 -> next = tmp1 ->next;
    delete tmp1;

}

int main()
{
    addinOrder(9);
    printLista();
    cout << endl;
    addinOrder(7);
    printLista();
    cout << endl;
    addinOrder(5);
    printLista();
    cout << endl;
    addinOrder(1);
    printLista();
    cout << endl;
    addinOrder(3);
    printLista();
    cout << endl;
    addinOrder(3);
    printLista();
    cout << endl;
    addinOrder(4);
    printLista();
    cout << endl;
    addinOrder(6);
    printLista();
    cout << endl;
    addinOrder(7);
    printLista();
    cout << endl;
    addinOrder(15);
    printLista();
    cout << endl;
    delByVal(1);
    printLista();
    cout << endl;
    delByVal(6);
    printLista();
    cout << endl;
    delByVal(9);
    printLista();
    cout << endl;
    delByVal(4);
    printLista();
    cout << endl;
    delByVal(3);
    printLista();
    cout << endl;
}

