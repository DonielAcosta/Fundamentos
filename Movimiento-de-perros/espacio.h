#include"perroSeguidor.h"

class Espacio
{
    Perro *Geo[fila][columna];

    public:
    Espacio()
    {
        for (int i=0; i<fila; i++)
            for (int j=0; j<columna; j++)
                Geo[i][j] = nullptr;
    }

    void setPerro(Perro *p)
    {
        int i,j;
        i = j = 0;
        if (hayEspacio() == true)
        {
            while(Geo[i][j]!=nullptr)
            {
                i = rand()%fila;
                j = rand()%columna;
            }
            p->setPosx(i);
            p->setPosy(j);
            Geo[i][j] = p;
        }
    }


    void finalizar()
    {
        for (int i=0; i<fila; i++)
            for (int j=0; j<columna; j++)
                if (Geo[i][j]!=nullptr)
                    if (Geo[i][j]->getEdad()>Geo[i][j]->getEdadFin())
                    {
                        if (Geo[i][j]->getLider()==nullptr)
                            this->ponerLider();
                        cout << "Finalizar"<< endl;
                        delete Geo[i][j];
                        Geo[i][j] = nullptr;
                    }
    }

    bool hayMachoEnMoore(int i,int j)
    {
        if (Geo[i][j]->getEdad()<=15)
            return false;
        for (int k=i-1; k<=i+1; k++)
            for (int m=j-1; m<=j+1; m++)
                if (Geo[k][m]!=nullptr)
                    if (Geo[k][m]->getSexo()==true && Geo[k][m]->getEdad()>15)
                        return true;
        return false;
    }

    void ponerLider()
    {
        PerroS* l = new PerroS('L');
        
        for (int i=0; i<fila; i++)
            for (int j=0; j<columna; j++)
                if (Geo[i][j]!=nullptr)
                    Geo[i][j]->setLider(l);
        this->setPerro(l);
    }

    void reproducir()
    {
         for (int i=1; i<fila-1; i++)
            for (int j=1; j<columna-1; j++)
                if (Geo[i][j]!=nullptr)
                    if (Geo[i][j]->getSexo() == false && hayMachoEnMoore(i,j))
                        if (hayEspacio())    
                            setPerro(new PerroS('*'));
    }
    void simular()
    {
        while(true)
        {
            pensar();
            mover();
            finalizar();
            reproducir();
            imprimir();
#ifdef _WIN32
            Sleep(200);
            system("cls");
#else
            usleep(200000);
            system("clear");
#endif
        }
    }
    private:

    //Cómo hago para que la ocupación no pase el 60%
    bool hayEspacio()
    {
        int contador = 0;
        for (int i=0; i<fila; i++)
            for (int j=0; j<columna; j++)
                if (Geo[i][j]==nullptr)
                    contador++;
        float cantidadO = contador*100.0/(fila*columna);

        return cantidadO >= 60;
                
    }
    void cambiar(bool prop, int K, int M, int i, int j, Perro *p)
    {
        if (prop)
            if (Geo[i+K][j+M]==nullptr)
                {
                    Geo[i+K][j+M] = Geo[i][j];
                    p->setPosx(i+K);
                    p->setPosy(j+M);
                    Geo[i][j] = nullptr;
                }
    }

    public:
    void pensar()
    {
         for (int i=0; i<fila; i++)
            for (int j=0; j<columna; j++)
                if (Geo[i][j]!=nullptr)
                    Geo[i][j]->pensar();
    }
    void mover()
    {
        for (int i=0; i<fila; i++)
            for (int j=0; j<columna; j++)
            {
                if (Geo[i][j]!=nullptr)
                {
                    if (Geo[i][j]->procesado == false)
                    {
                        Geo[i][j]->procesado = true;
                        if (Geo[i][j]->getDecision() == 'N')
                            cambiar(i != 0, -1, 0, i, j, Geo[i][j]);
                        else                       
                            if (Geo[i][j]->getDecision() == 'S')
                                cambiar(i != fila-1, 1, 0, i, j, Geo[i][j]);
                            else
                                if (Geo[i][j]->getDecision() == 'E')
                                    cambiar(j != columna-1, 0, 1, i, j, Geo[i][j]);
                                else
                                    if (Geo[i][j]->getDecision() == 'O')
                                        cambiar( j != 0, 0, -1, i, j, Geo[i][j]);      
                    }
                }
            }

        for (int i=0; i<fila; i++)
            for (int j=0; j<columna; j++)
                if (Geo[i][j]!=nullptr)
                    Geo[i][j]->procesado = false;
    }

    void imprimir()
    {
        for (int i=0; i<fila; i++)
        {
            for (int j=0; j<columna; j++)
            {
                if (Geo[i][j]!=nullptr)
                    Geo[i][j]->imprimir();
                else    
                    cout << "_ ";   
            }
            cout << endl;
        }
            
    }
};