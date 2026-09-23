#include "perro.h"

class PerroE: public Perro
{
    char decisiones[4];
    int iterador;

    public:
    PerroE(char c):Perro(c)
    {
        decisiones[0] = 'N';
        decisiones[1] = 'O';
        decisiones[2] = 'S';
        decisiones[3] = 'E';
        iterador = 0;
        decision = decisiones[0];
    }

    void decidir()
    {
        switch (decision)
        {
            case 'N':
                if (posx == 0)
                {
                    iterador++;
                    iterador = iterador % 4;
                    decision = decisiones[iterador];
                }   
           break;
           case 'E':
                if (posy == columna-1)
                {
                    iterador++;
                    iterador = iterador % 4;
                    decision = decisiones[iterador];
                }   
            break;
            case 'O':
                if (posy == 0)
                {
                    iterador++;
                    iterador = iterador % 4;
                    decision = decisiones[iterador];
                }
            break;
            case 'S':
                if (posx == fila-1)
                {
                    iterador++;
                    iterador = iterador % 4;
                    decision = decisiones[iterador];
                }
                    
            break;
    }
}

    void pensar()
    {
        edad++;
        if (edad>=15)
        {
            if (sexo == false)
                raza = 'O';
            else    
                raza = 'L';
        }
        decidir();  
        
    }


};