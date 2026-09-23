#include "perro.h"


class PerroS: public Perro
{
    PerroS *lider;
    public:
    PerroS(char t): Perro(t)
    {
        lider = nullptr;
    }

    void setLider(Perro *p) override
    {
        lider = (PerroS*)p;
    }
    Perro* getLider() override
    {
        Perro *L = lider;
        return lider;
    }

    void pensar() override
    {
   
        if (lider == nullptr)
            Perro::pensar();
        else
        {
            //SE
            if (posx < lider->getposx() && posy < lider->getposy())
            {
                if (rand()%100 < 50)
                    decision = 'S';
                else
                    decision = 'E';
            }
            else
            {
                //SO
                               
                if (posx < lider->getposx() && posy > lider->getposy())
                {
                    if (rand()%100 < 50)
                        decision = 'S';
                    else
                        decision = 'O';
                }
                else
                {
                    //NO
                                    
                    if (posx > lider->getposx() && posy > lider->getposy())
                    {
                        if (rand()%100 < 50)
                            decision = 'N';
                        else
                            decision = 'O';
                    }
                    else
                    {
                        //NE
                                        
                        if (posx > lider->getposx() && posy < lider->getposy())
                        {
                            if (rand()%100 < 50)
                                decision = 'N';
                            else
                                decision = 'E';

                        }
                        else
                            decision = 'p';
                    }
                }
            }
        }
  
    }
};