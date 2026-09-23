#include"preliminares.h"

class Perro
{    
    protected:
    char raza;
    int edad;
    int edadFin;
    bool sexo;
    

    
    char decision;
    int posx;
    int posy;

    public:
    bool procesado;
    Perro(char r)
    {
        sexo = rand()%2;
        edadFin = rand()%30 + 80;
        edad = 0;
        raza = r;
        procesado = false;
    }
   //interfaz
    void virtual pensar()
    {
        
        edad++;
        /*if (edad>=15)
        {
            if (sexo == false)
                raza = '0';
            else    
                raza = '1';
        }*/
            
        switch (rand()%4)
        {
            case 0:
                decision = 'N';
            break;
            case 1:
                decision = 'S';
            break;
            case 2:
                decision = 'E';
            break;
            case 3:
                decision = 'O';
            break;
            default:
                decision = 'P';
            break;
        }
     
    }
    void imprimir()
    {
        cout << raza<< " ";
    }

    //no tiene metodos de funcionamiento interno
    char getRaza()
    {
        return raza;
    }

    void setRaza(char r)
    {
        raza = r;
    }

    char getDecision()
    {
        return decision;
    }

    int getEdad()
    {
        return edad;
    }
    int getEdadFin()
    {
        return edadFin;
    }
    int getSexo()
    {
        return sexo;
    }
    void setPosx(int xx){ posx = xx; }
    void setPosy(int xx){ posy = xx; }
    int getposx(){return posx;}
    int getposy(){return posy;}



     void virtual setLider(Perro *p){}
    virtual Perro* getLider(){return nullptr;}

};