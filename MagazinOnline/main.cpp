#include <iostream>
#include "produs.h"
using namespace std;
int main()
{
    Produs lapte;
    Produs* lista = new Produs[100];
    cout << lista[0];
    cout << lista[1];
    cout << lapte;
    return 0;
}