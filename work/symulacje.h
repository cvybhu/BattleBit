#ifndef symulacje_h
#define symulacje_h

#include <allegro.h>
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <sstream>

int wyzn (int z)       //wyznacza, ktory element tablicy wysw odpowiada danemu y-grekowi
{
    int wynik = (z-z%50)/50;
    return(wynik);
}

int iledo(int kier,char **mapa,int x,int y,int rozmx,int rozmy,double speed)     //wyznacza odleglosc do danej sciany
{
    double wynik = 7.0;

    if(kier == 1)
    {
    wynik *= speed;

    for(int j = 0;j < wynik*speed;j += 1)
        {
            if(mapa[wyzn(y-(rozmy/2-10))][wyzn(x+rozmx/2+j)] != ' ' || mapa[wyzn(y)][wyzn(x+rozmx/2+j)] != ' ' || mapa[wyzn(y+(rozmy/2-10))][wyzn(x+rozmx/2+j)] != ' ')
            {
                return(j);
            }
        }
    }

    if(kier == 3)
    {
    wynik *= speed;

    for(int i = 0;i < wynik*speed;i += 1)
        {
            if(mapa[wyzn(y-(rozmy/2-10))][wyzn(x-rozmx/2-i)] != ' ' || mapa[wyzn(y)][wyzn(x-rozmx/2-i)] != ' ' || mapa[wyzn(y+(rozmy/2-10))][wyzn(x-rozmx/2-i)] != ' ')
            {
                return(i);
            }
        }
    }

    if(kier == 2)
    {
    for(int k = 0;k < wynik+1000;k += 1)
        {
            if(mapa[wyzn(y+rozmy/2+k)][wyzn(x-(rozmx/2-10))] != ' ' || mapa[wyzn(y+rozmy/2+k)][wyzn(x+(rozmx/2-10))] != ' ')
            {
                return(k);
            }
        }
    }

    if(kier == 0)
    {
    for(int h = 0;h < wynik+1000;h += 1)
        {
            if(mapa[wyzn(y-rozmy/2-h)][wyzn(x-(rozmx/2-10))] != ' ' || mapa[wyzn(y-rozmy/2-h)][wyzn(x+(rozmx/2-10))] != ' ')
            {
                return(h);
            }
        }
    }

return(wynik);

}

int w_zasiegu(int xex,int yex,int xo,int yo,int r)
{
    double pitax;
    double pitay;
    double pita;

    if(xex > xo)pitax = xex-xo;
    if(xo >= xex)pitax = xo-xex;
    if(yex > yo)pitay = yex-yo;
    if(yo >= yex)pitay = yo-yex;

    if(sqrt(double((pitax*pitax)+(pitay*pitay))) < r)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

void dodaj_explozje(explz explozja[ileexpl],int typ,int x,int y,int r)
{
    int wolne = 0;

    for(int w = 0;w < ileexpl;w++)
    {
        if(explozja[w].typ == 0)
        {
        wolne = w;
        break;
        }
    }
    explozja[wolne].typ = typ;
    explozja[wolne].x = x;
    explozja[wolne].y = y;
    explozja[wolne].r = r;
    explozja[wolne].czas = 40;
    explozja[wolne].damage = 100;
}

void strzelaj(int bron,pocisk pociski[ilepoc],int x,int y,int celx,int cely)
{
    int i = 0;

    for(int j = 0;j < ilepoc;j++)
    {
    if(pociski[j].typ == 0)
    {
        i = j;
        break;
    }
    }

    pociski[i].typ = bron;
    pociski[i].x = x;
    pociski[i].y = y;

    double doatana = M_PI;
    if(x != celx && y != cely)doatana = double(y-cely)/double(celx-x);
    pociski[i].kat = atan(doatana)+M_PI/2;
    if(celx < x)pociski[i].kat += M_PI;

    if(bron == 1)
    {
    pociski[i].rozrzut = 2;
    pociski[i].pred = 25;
    pociski[i].boom = false;
    }

    if(bron == 2)
    {
    pociski[i].rozrzut = 1;
    pociski[i].pred = 25;
    pociski[i].boom = true;
    }

    if(bron == 200)
    {
        pociski[i].rozrzut = 10;
        pociski[i].pred = 5;
        pociski[i].boom = false;
    }

    pociski[i].kat += (double(rand()%(pociski[i].rozrzut*2)-pociski[i].rozrzut)/180*M_PI);
    }

void lataj_pociski(pocisk pociski[ilepoc],explz explozja[ileexpl],char **mapa,double speed)
{
    for(int i = 0;i < ilepoc;i++)
    {
        if(pociski[i].typ != 0)
        {
            pociski[i].x += sin(pociski[i].kat)*pociski[i].pred*speed;
            pociski[i].y += cos(pociski[i].kat)*pociski[i].pred*speed;


            if(mapa[wyzn(pociski[i].y)][wyzn(pociski[i].x)]!= ' ')
            {
               pociski[i].typ = 0;       //rozbijanie sie pociskow o sciany
               if(pociski[i].boom == true)dodaj_explozje(explozja,1,pociski[i].x,pociski[i].y,200);
            }
        }
    }
}

postac kolizjuj_pociski(postac bohater,wrg wrogowie[ilewrog],pocisk pociski[ilepoc],explz explozja[ileexpl],bool uproszcz)
{
    if(uproszcz)
    {
        for(int i = 0;i < ilepoc;i++)
        {

        if(pociski[i].typ != 0)
        {
            if(
               pociski[i].typ == 200 &&
               pociski[i].x > bohater.x-50 &&
               pociski[i].x < bohater.x+50 &&
               pociski[i].y > bohater.y-100 &&
               pociski[i].y < bohater.y+100)
               {
                   pociski[i].typ = 0;
                   bohater.zycie -= 5;
               }
               else
                {
            for(int j = 0;j < ilewrog;j++)
                    {
                    if(wrogowie[j].typ != 0)
                    {
                        if(pociski[i].x > (wrogowie[j].x-(wrogowie[j].rozmx/2)) &&
                        pociski[i].x < (wrogowie[j].x+(wrogowie[j].rozmx/2)) &&
                        pociski[i].y > (wrogowie[j].y-(wrogowie[j].rozmy/2)) &&
                        pociski[i].y < (wrogowie[j].y+(wrogowie[j].rozmy/2)))
                        {
                            if(pociski[i].typ == 1)wrogowie[j].zycie -= 5;
                            if(pociski[i].boom == true)dodaj_explozje(explozja,1,pociski[i].x,pociski[i].y,200);

                            if(pociski[i].typ != 200)pociski[i].typ = 0;
                        }
                        }
                    }
        }
        }
        }
    }
    else
    {
        for(int i = 0;i < ilepoc;i++)
            {
            if(pociski[i].typ != 0)
            {

            if(
               pociski[i].typ == 200 &&
               pociski[i].x > bohater.x-50 &&
               pociski[i].x < bohater.x+50 &&
               pociski[i].y > bohater.y-100 &&
               pociski[i].y < bohater.y+100)
               {
                   pociski[i].typ = 0;
                   bohater.zycie -= 5;
               }
               else
               {
            int kamx = pociski[i].x-300;
            int kamy = pociski[i].y-200;

            rysuj_wrogow(wrogowie,kamx,kamy,takicus);

            if(getpixel(takicus,pociski[i].x-kamx,pociski[i].y-kamy) != makecol(255,0,254))
                for(int j = 0;j < ilewrog;j++)
                    {
                    if(pociski[i].x > (wrogowie[j].x-(wrogowie[j].rozmx/2)) &&
                    pociski[i].x < (wrogowie[j].x+(wrogowie[j].rozmx/2)) &&
                    pociski[i].y > (wrogowie[j].y-(wrogowie[j].rozmy/2)) &&
                    pociski[i].y < (wrogowie[j].y+(wrogowie[j].rozmy/2)))
                    {
                        if(pociski[i].typ == 1)wrogowie[j].zycie -= 5;
                        if(pociski[i].boom == true)dodaj_explozje(explozja,1,pociski[i].x,pociski[i].y,200);

                            pociski[i].typ = 0;
                    }
                    }
        }
    }
    }
}

return bohater;
}

void exploduj (explz explozja [ileexpl], wrg wrogowie[ilewrog],double speed)
{
 for(int i = 0;i < ileexpl;i++)
 {
  if(explozja[i].typ != 0)
  {
    for(int j = 0;j < ilewrog;j++)
    {
     if(wrogowie[j].typ != 0)
     {
      if(w_zasiegu(explozja[i].x,explozja[i].y,wrogowie[j].x,wrogowie[j].y,explozja[i].r) == 1)
        {
          wrogowie[j].zycie -= explozja[i].damage;
        }
     }
    }
    explozja[i].damage = 0;
     if(explozja[i].typ != 0)
     {
        explozja[i].czas -= speed;
        if(explozja[i].czas < 1)explozja[i].typ = 0;
     }
  }
 }
}

void dodaj_wroga(int typ,double x,double y,wrg wrogowie[ilewrog])
{
    int ktor = 0;

    for(int i = 0;i < ilewrog;i++)
    {
    if(wrogowie[i].typ == 0)
        {
            ktor = i;
            break;
        }
    }

    wrogowie[ktor].x = x;
    wrogowie[ktor].y = y;
    wrogowie[ktor].stan = 0;
    wrogowie[ktor].typ = typ;
    wrogowie[ktor].reload = 100;


    wrogowie[ktor].sytuacja = 0;

    wrogowie[ktor].obrazek = create_bitmap(wrogowie[ktor].rozmx,wrogowie[ktor].rozmy);

    if(typ == 1)
    {
        wrogowie[ktor].zycie = wrg_zyc;
        wrogowie[ktor].rozmx = 230;
        wrogowie[ktor].rozmy = 200;

    wrogowie[ktor].animacje[0].ile = 0;
    wrogowie[ktor].animacje[0].czas = 100000;
    wrogowie[ktor].animacje[0].obrazek = wrg_stoi;

    wrogowie[ktor].animacje[1].ile = 2;
    wrogowie[ktor].animacje[1].czas = int(2.0/60.0*double(SZYBKOSC));
    wrogowie[ktor].animacje[1].obrazek = wrg_idzie_L;

    wrogowie[ktor].animacje[2].ile = 2;
    wrogowie[ktor].animacje[2].czas = int(2.0/60.0*double(SZYBKOSC));
    wrogowie[ktor].animacje[2].obrazek = wrg_idzie_P;

    wrogowie[ktor].animacje[3].ile = 3;
    wrogowie[ktor].animacje[3].czas = 1000;
    wrogowie[ktor].animacje[3].obrazek = wrg_skacze;
    }

    if(typ == 2)
    {
        wrogowie[ktor].zycie = 500;
        wrogowie[ktor].rozmx = 100;
        wrogowie[ktor].rozmy = 200;

    wrogowie[ktor].animacje[0].ile = 1;
    wrogowie[ktor].animacje[0].czas = 100000;
    wrogowie[ktor].animacje[0].obrazek = boh_stoi_L;

    wrogowie[ktor].animacje[1].ile = 1;
    wrogowie[ktor].animacje[1].czas = 100000;
    wrogowie[ktor].animacje[1].obrazek = boh_stoi_P;

    wrogowie[ktor].animacje[2].ile = 10;
    wrogowie[ktor].animacje[2].czas = int(2.5/60.0*double(SZYBKOSC));
    wrogowie[ktor].animacje[2].obrazek = boh_idzie_L;

    wrogowie[ktor].animacje[3].ile = 10;
    wrogowie[ktor].animacje[3].czas = int(2.5/60.0*double(SZYBKOSC));
    wrogowie[ktor].animacje[3].obrazek = boh_idzie_P;
    }

}

bool czy_widzi (int x1,int y1,int x2, int y2,char **mapa)
{
    bool wynik = true;

    double kat = atan(double(y1-y2)/double(x2-x1))+M_PI/2;
    if(x2 < x1)
    {
        double x = x1;
        double y = y1;

        while(x > x2)
        {
        y -= cos(kat)*30;
        x -= sin(kat)*30;
        if(mapa[wyzn(y)][wyzn(x)] != ' ')
        {
            wynik = false;
            break;
        }
        }
    }
    else
    {
        double x = x1;
        double y = y1;

        while(x < x2)
        {
        y += cos(kat)*30;
        x += sin(kat)*30;
        if(mapa[wyzn(y)][wyzn(x)] != ' ')
        {
            wynik = false;
            break;
        }
        }
    }

    return(wynik);
}
#endif
