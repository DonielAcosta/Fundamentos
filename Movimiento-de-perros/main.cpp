#include"espacio.h"


int main()
{
    Espacio *E1 = new Espacio();
    for (int i=1; i<10; i++)
        E1->setPerro(new PerroS('*'));
    for (int i=1; i<10; i++)
        E1->setPerro(new Perro('*'));
    E1->ponerLider();
    E1->simular();
    return 0;
}