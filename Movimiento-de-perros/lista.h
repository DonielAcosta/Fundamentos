#include"nodo.h"

class ListaSimple
{
    NODO *cab;

    public:
    ListaSimple()
    {
        cab = NULL;
    }
    void agregarPerro(Perro *p)//Pilas asignación
    {
        NODO *nuevo = new NODO();
        nuevo->p = p;

        if (cab == NULL)
            cab = nuevo;
        else
        {
            nuevo->sig = cab;
            cab = nuevo;
        }

    }

    int lon()
    {
        int contador = 0;
        NODO *aux = cab;

        while (aux != NULL)
        {
            contador++;
            aux = aux->sig;
        }
        return contador;
    }

    void imprimir()
    {
        NODO *aux = cab;
        while(aux != NULL)
        {
            cout << aux->p->getRaza()<<" ";
            aux = aux->sig;
        }
        cout << endl;
    }

    void eliminar(char r)
    {
        NODO *aux = cab;
        NODO *aux1;
        if (cab->p->getRaza() == r)
        {
            cab = cab->sig;
            aux->sig = NULL;
            delete aux;
        }
        else
        {
            while (aux->sig != NULL)
            {
                if (aux->sig->p->getRaza() == r)
                {
                    aux1 = aux->sig;
                    aux->sig = aux->sig->sig;
                    aux1->sig = NULL;
                    delete aux1;
                    //return; si quiere eliminar solo el primer perro con la caracteristica
                }
                aux = aux->sig;
            }
        }
    }

    void PonerAPesar()
    {
        NODO *aux = cab;
        while(aux != NULL)
        {
            aux->p->pensar();
            aux = aux->sig;
        }
    }

    void eliminarGanadores(int lo)
    {
        NODO *aux = cab;
        NODO *aux1;
        if (cab->p->getPos() > lo)
        {
            cab = cab->sig;
            aux->sig = NULL;
            delete aux;
        }
        else
        {
            while (aux->sig != NULL)
            {
                if (aux->sig->p->getPos() > lo)
                {
                    aux1 = aux->sig;
                    aux->sig = aux->sig->sig;
                    delete aux1;
                }
                else
                {   
                    aux = aux->sig;
                }
            }
        }
    }

    char QuePerroImprimo(int i)
    {
        int contadorCol = 0;
        char caracter = '_';//adoquin

        NODO *aux = cab;
        while(aux != NULL)
        {
            if (aux->p->getPos() == i)
                contadorCol++;
            aux = aux->sig;
        }

        if (contadorCol == 1)
            return (char)254;
        if (contadorCol>1)
            return '*';
        return caracter;
    }
};
