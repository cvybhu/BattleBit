#ifndef AI_h
#define AI_h

#include <allegro.h>
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <sstream>

void AI (int bohx,int bohy,char **mapa,wrg wrogowie[ilewrog],pocisk pociski[ilepoc], double speed,long int npw)
{
    for(int i = 0;i < ilewrog;i++)
    {

    if(wrogowie[i].zycie < 1)
    {
        wrogowie[i].typ = 0;
    }

    if(wrogowie[i].typ != 0)
    {

        int il_do_gr = iledo(0,mapa,wrogowie[i].x,wrogowie[i].y,wrogowie[i].rozmx,wrogowie[i].rozmy,speed);
        int il_do_dl = iledo(2,mapa,wrogowie[i].x,wrogowie[i].y,wrogowie[i].rozmx,wrogowie[i].rozmy,speed);

        int sytuacja = 0;

        if(wrogowie[i].odst > 0)wrogowie[i].odst--;

        if(il_do_dl > 6)
            {
                wrogowie[i].ky += 0.3;

                if(il_do_dl > wrogowie[i].ky)
                {
                    wrogowie[i].y += wrogowie[i].ky;
                }
                else
                {
                    wrogowie[i].y += il_do_dl;
                }
                sytuacja = 3;
            }
            else
            {
                wrogowie[i].ky = 0;
                wrogowie[i].y += il_do_dl;
            }

        if(czy_widzi(wrogowie[i].x,wrogowie[i].y,bohx,bohy-50,mapa) && czy_widzi(wrogowie[i].x,wrogowie[i].y,bohx,bohy+50,mapa))
        {
            if(wrogowie[i].reload < 1)
            {
                strzelaj(200,pociski,wrogowie[i].x,wrogowie[i].y-65,bohx,bohy);
                wrogowie[i].reload = 100;
            }

            wrogowie[i].celx = bohx;
            wrogowie[i].cely = bohy;

            int il_do_pr;
            int il_do_lw;

            if(speed < 0.4)
            {
             il_do_pr = iledo(1,mapa,wrogowie[i].x,wrogowie[i].y,wrogowie[i].rozmx,wrogowie[i].rozmy,speed*0.5);
             il_do_lw = iledo(3,mapa,wrogowie[i].x,wrogowie[i].y,wrogowie[i].rozmx,wrogowie[i].rozmy,speed*0.5);
            }
            else
            {
             il_do_pr = iledo(1,mapa,wrogowie[i].x,wrogowie[i].y,wrogowie[i].rozmx,wrogowie[i].rozmy,speed*0.3);
             il_do_lw = iledo(3,mapa,wrogowie[i].x,wrogowie[i].y,wrogowie[i].rozmx,wrogowie[i].rozmy,speed*0.3);
            }

        if(bohx > wrogowie[i].x)
         {
            wrogowie[i].x += il_do_pr;

            sytuacja = 2;

            if(wrogowie[i].odst < 1 && mapa[wyzn(wrogowie[i].y+(wrogowie[i].rozmy/2-20))][wyzn(wrogowie[i].x+(wrogowie[i].rozmx/2)+il_do_pr)] != ' ' && il_do_dl < 5)
            {
                wrogowie[i].ky = -10;
                wrogowie[i].y -= 7;

                wrogowie[i].odst = 100;

                sytuacja = 3;
            }
         }

         if(bohx < wrogowie[i].x)
         {
            wrogowie[i].x -= il_do_lw;

            sytuacja = 1;

            if(wrogowie[i].odst < 1 && mapa[wyzn(wrogowie[i].y+(wrogowie[i].rozmy/2-20))][wyzn(wrogowie[i].x-(wrogowie[i].rozmx/2)-il_do_lw)] != ' ' && il_do_dl < 5)
            {
                wrogowie[i].ky = -10;
                wrogowie[i].y -= 7;

                wrogowie[i].odst = 100;

                sytuacja = 3;
            }

         }
        }

        wrogowie[i].sytuacja = sytuacja;

        if(wrogowie[i].reload > 0)wrogowie[i].reload -= 1.0*speed;
    }
    }
}

#endif
