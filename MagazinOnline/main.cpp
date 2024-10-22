#include <iostream>
#include "produs.h"
using namespace std;
int main()
{
    Produs lapte("lapte", "praf", "delicios", 5.78);
    Produs nimic;
    cout << lapte;
    cout << nimic;
    return 0;
}