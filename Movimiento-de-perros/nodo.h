#include"perro.h"

struct NODO
{
    Perro *p;
    NODO *sig;

    NODO()
    {
        p = NULL;
        sig = NULL;
    }
};
