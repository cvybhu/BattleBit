#ifndef grafika_h
#define grafika_h

#include <allegro.h>
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <sstream>

FONT *troika;

BITMAP *porusz_tut;
BITMAP *skoki_tut;
BITMAP *strzal_tut;
BITMAP *zmiana_tut;
BITMAP *skup_tut;

BITMAP *bufor;
BITMAP *blok1;
BITMAP *blok2;
BITMAP *tlo;

BITMAP *prtl;
BITMAP *wyjsc;
BITMAP *wyjsc_pods;

BITMAP *boh_stoi_L;
BITMAP *boh_stoi_P;
BITMAP *boh_idzie_L;
BITMAP *boh_idzie_P;
BITMAP *boh_skacze_L;
BITMAP *boh_skacze_P;

BITMAP *celownik;
BITMAP *hitbox;
BITMAP *takicus;


BITMAP *wrg_stoi;
BITMAP *wrg_idzie_L;
BITMAP *wrg_idzie_P;
BITMAP *wrg_skacze;

BITMAP *wrg_bron;
BITMAP *wrg_bron_strzal;
BITMAP *wrg_bron_odw;
BITMAP *wrg_bron_strzal_odw;

BITMAP *menu_tlo;
BITMAP *graj_prz;
BITMAP *graj_prz_prz;
BITMAP *wyjscie_prz;
BITMAP *wyjscie_prz_prz;
BITMAP *ustawienia_prz;
BITMAP *ustawienia_prz_prz;

BITMAP* logo;



BITMAP *karabin;
BITMAP *karabin_odw;
BITMAP *karabin_strzal;
BITMAP *karabin_odw_strzal;
BITMAP *bazooka;
BITMAP *bazooka_odw;
BITMAP *bazooka_strzal;
BITMAP *bazooka_odw_strzal;
BITMAP *nawalarka;
BITMAP *nawalarka_odw;

BITMAP* boom;

BITMAP *pocisk1;
BITMAP *pocisk2;

BITMAP *pocisk200;

BITMAP *karabin_sam;
BITMAP *karabin_sam_podsw;
BITMAP *bazooka_sam;
BITMAP *bazooka_sam_podsw;

BITMAP *ramka;
BITMAP *ramka2;

BITMAP *ukonczony;

BITMAP *dalej;
BITMAP *dalej_prz;
BITMAP *menu_guz;
BITMAP *menu_guz_prz;

BITMAP *guz_tutorial;
BITMAP *guz_tutorial_prz;
BITMAP *guz_poziom1;
BITMAP *guz_poziom1_prz;
BITMAP *guz_wlasny;
BITMAP *guz_wlasny_prz;

BITMAP *pasek;


BITMAP *zapisywanie;


BITMAP* skaluj_bitmape(BITMAP *bitmapa,int doc_szer,int doc_wys)
{
    BITMAP *tmp = create_bitmap(doc_szer,doc_wys);
    rectfill(tmp,0,0,doc_szer,doc_wys,makecol(255,0,255));

    stretch_blit(bitmapa, tmp, 0, 0, bitmapa->w, bitmapa->h, 0, 0, tmp->w, tmp->h);

    return tmp;
}

int kameruj_x(int x,int y,bool kamruch)
{
    int kamx;

    if(kamruch)
        {
        kamx = x-szer/2 + (mouse_x-szer/2)/2;

        if(mouse_x == szer/2)kamx = x-szer/2;
        }
        else
        {
	    kamx = x-szer/2;
        }

    if (kamx < 0)kamx = 0;

    return(kamx);
}

int kameruj_y(int x,int y,bool kamruch)
{
    int kamy;
    if(kamruch)
        {
        kamy = y-wys/2+(mouse_y-wys/2)/2;

        if(mouse_y == wys/2)kamy = y-wys/2;
        }
        else
        {
	    kamy = y-wys/2;
        }

    if (kamy < 0)kamy = 0;

    return(kamy);
}

void rysuj_pociski(pocisk pociski[ilepoc],int kamx,int kamy)
{
    for(int i = 0;i < ilepoc;i++)
    {

        double kat = pociski[i].kat*180/M_PI;
        kat = 90-kat;
        //if(pociski[i].typ != 0)circlefill(bufor,pociski[i].x-kamx,pociski[i].y-kamy,4,makecol(234,100,34));
        if(pociski[i].typ == 1)rotate_sprite(bufor,pocisk1,pociski[i].x-kamx-25,pociski[i].y-kamy-10,ftofix(kat/360.0*255.0));
        if(pociski[i].typ == 2)rotate_sprite(bufor,pocisk2,pociski[i].x-kamx-30,pociski[i].y-kamy-15,ftofix(kat/360.0*255.0));

        if(pociski[i].typ == 200)rotate_sprite(bufor,pocisk200,pociski[i].x-kamx-30,pociski[i].y-kamy-15,ftofix(kat/360.0*255.0));
    }
}

void rysuj_explozje(explz explozja[ileexpl],int kamx,int kamy)
{
    for(int i = 0;i < ileexpl;i++)
    {
        if(explozja[i].typ == 1)draw_sprite(bufor,boom,explozja[i].x-kamx-150,explozja[i].y-kamy-150);
    }
}

void rysuj_bron(int x,int y,int celx,int cely,int bron,int reload)
{
    double kat = 0.0;
    double doatana = M_PI;
    if(x != celx && y != cely)doatana = double(cely-y)/double(celx-x);
    kat = atan(doatana);
    kat = kat*180/M_PI;

    if(bron == 1)
    {
    if(reload > karab_reload-19)
    {
        nawalarka = karabin_strzal;
        nawalarka_odw = karabin_odw_strzal;
    }
    else
    {
        nawalarka = karabin;
        nawalarka_odw = karabin_odw;
    }
    }

    if(bron == 2)
    {
    if(reload > bazook_reload-30)
    {
        nawalarka = bazooka_strzal;
        nawalarka_odw = bazooka_odw_strzal;
    }
    else
    {
        nawalarka = bazooka;
        nawalarka_odw = bazooka_odw;
    }
    }

    if(celx <= x)rotate_sprite(bufor,nawalarka_odw,x-95+10,y-35-30,ftofix(kat/360*225));
    if(celx > x)rotate_sprite(bufor,nawalarka,x-95-10,y-35-30,ftofix(kat/360*255));
}

void rysuj_bohatera(int x, int y,int rozbohx,int rozbohy,int kamx,int kamy,BITMAP *bitmapa)
{
    draw_sprite(bufor,bitmapa,x-kamx-(rozbohx/2),(y-kamy)-(rozbohy/2)+5);
}

void rysuj_plansze(char **mapa,int wympoz,int wympion,int kamx,int kamy)
{
int dzielx = (kamx-kamx%50)/50;       //wyznacza o ile "piedziesiatek" (bo tyle zwiera jeden blok) plansza jest przesunieta
int dziely = (kamy-kamy%50)/50;

for(int i = wympion;i >= 0;i--)
        {
            for(int j = wympoz;j >= 0;j--)
            {
                if(mapa[i+dziely][j+dzielx] != ' ')
                {
                    if(mapa[i+dziely][j+dzielx] == 'z')draw_sprite(bufor,blok1,j*50-kamx%50-5,i*50-kamy%50-5);
                    if(mapa[i+dziely][j+dzielx] == 'm')draw_sprite(bufor,blok2,j*50-kamx%50-5,i*50-kamy%50-5);
                }
            }
        }
}

void rysuj_miedzymordzie(postac bohater)        //interface = miedzymordzie :D
{
    //draw_sprite(bufor,pasek,0,wys-125);

    int przes = wys-120;
    int przesx = szer/2-155;

    int przesx2 = szer/2-200;

    if(szer == szer)
    {
        przes = 0;
        przesx = 0;
        przesx2 = 0;

    }

    rectfill(bufor,20+przesx2-10,wys-120-przes-10,20+200+przesx2+200+10,wys-110-przes+200+10,makecol(100,100,120));

    draw_sprite(bufor,ramka,20+200*(bohater.bron-1)+przesx2,wys-110-przes);

    draw_sprite(bufor,karabin_sam,20+przesx2,wys-120-przes);
    draw_sprite(bufor,bazooka_sam,20+200+przesx2,wys-110-przes);

    textprintf_ex(bufor, troika, 84+przesx2,wys-75+40-przes, makecol(255, 100, 56),-1,"%d",bohater.pasek_broni[0].amunicja);
    textprintf_ex(bufor, troika, 200+98+przesx2,wys-73+40-przes, makecol(255, 100, 56),-1,"%d",bohater.pasek_broni[1].amunicja);


    rectfill(bufor,szer-15-300-10-przesx,wys-110,szer-10-przesx,wys-19,makecol(100,100,100));

    rectfill(bufor,szer-300-17-przesx,wys-101,szer-15-przesx,wys-69,makecol(0,0,0));
    rectfill(bufor,szer-300-16-przesx,wys-100,szer-300-16+int(bohater.zycie/100.0*300.0)-przesx,wys-70,makecol(200,0,0));

    rectfill(bufor,szer-300-17-przesx,wys-61,szer-15-przesx,wys-29,makecol(0,0,0));
    rectfill(bufor,szer-300-16-przesx,wys-60,szer-300-16+int(bohater.skupienie/double(skup)*300.0)-przesx,wys-30,makecol(0,0,200));


}

postac animuj_bohatera(postac bohater, long int npw)
{
    if(npw%bohater.animacje[bohater.sytuacja].czas == 0)
    {
        bohater.animacje[bohater.sytuacja].klatka++;
        if(bohater.animacje[bohater.sytuacja].klatka > bohater.animacje[bohater.sytuacja].ile)bohater.animacje[bohater.sytuacja].klatka = 0;
    }

    blit(
         bohater.animacje[bohater.sytuacja].obrazek, bohater.obrazek,
         bohater.animacje[bohater.sytuacja].klatka*170, 0,
         0, 0,
         170, 200
         );

    return bohater;
}

wrg animuj_wroga(wrg wrog, long int npw)
{
    if(true)//npw%wrog.animacje[wrog.sytuacja].czas == 0)
    {
        wrog.animacje[wrog.sytuacja].klatka = 1;
        //if(wrog.animacje[wrog.sytuacja].klatka > wrog.animacje[wrog.sytuacja].ile)wrog.animacje[wrog.sytuacja].klatka = 0;
    }

//circlefill(bufor,szer/2,wys/2,35,makecol(0,0,0));

    /*blit(
         wrog.animacje[wrog.sytuacja].obrazek, wrog.obrazek,
         wrog.animacje[wrog.sytuacja].klatka*230, 0,
         0, 0,
         230, 200
         );*/

         draw_sprite(wrog.obrazek,wrg_bron,0,0);

    return wrog;
}

void rysuj_wrg_bron(wrg wrogowie[ilewrog],int kamx, int kamy)
{
    for(int i = 0;i < ilewrog;i++)
    {
    if(wrogowie[i].typ != 0)
    {

    double kat = 0.0;
    double doatana = M_PI;
    if(wrogowie[i].x != wrogowie[i].celx && wrogowie[i].y != wrogowie[i].cely)doatana = double(wrogowie[i].cely-wrogowie[i].y)/double(wrogowie[i].celx-wrogowie[i].x);
    kat = atan(doatana);
    kat = kat*180.0/M_PI;

    if(wrogowie[i].reload > wrg_reload)
    {
        nawalarka = wrg_bron_strzal;
        nawalarka_odw = wrg_bron_strzal_odw;
    }
    else
    {
        nawalarka = wrg_bron;
        nawalarka_odw = wrg_bron_odw;
    }


    if(wrogowie[i].celx <= wrogowie[i].x)rotate_sprite(bufor,nawalarka_odw,(wrogowie[i].x-115)-kamx,(wrogowie[i].y-80)-kamy,ftofix(kat/360*225));
    if(wrogowie[i].celx > wrogowie[i].x)rotate_sprite(bufor,nawalarka,(wrogowie[i].x-115)-kamx,(wrogowie[i].y-80)-kamy,ftofix(kat/360*255));
    }
    }
}

void rysuj_wrogow(wrg wrogowie[ilewrog],int kamx,int kamy,BITMAP* ekran)
{
    circlefill(takicus,300,200,600,makecol(255,0,254));

    for(int i = 0;i < ilewrog;i++)
    {
        if(wrogowie[i].typ != 0)
        {

            int zyycie = wrg_zyc;

            rectfill(ekran,(wrogowie[i].x-kamx)-50,(wrogowie[i].y-kamy)-(wrogowie[i].rozmy/2)-30,(wrogowie[i].x-kamx)+50,(wrogowie[i].y-kamy)-(wrogowie[i].rozmy/2)-10,makecol(0,0,0));
            rectfill(ekran,(wrogowie[i].x-kamx)-49,(wrogowie[i].y-kamy)-(wrogowie[i].rozmy/2)-29,(wrogowie[i].x-kamx)-49+(wrogowie[i].zycie/double(zyycie)*98.0),(wrogowie[i].y-kamy)-(wrogowie[i].rozmy/2)-11,makecol(200,0,0));
            //textprintf_ex(ekran, troika, (wrogowie[i].x-kamx)-20, (wrogowie[i].y-kamy)-(wrogowie[i].rozmy/2)-30, makecol(255, 100, 56),-1, "%d - %d",wrogowie[i].animacje[wrogowie[i].sytuacja].klatka,wrogowie[i].animacje[wrogowie[i].sytuacja].czas);
            draw_sprite(ekran,wrg_stoi,(wrogowie[i].x-kamx)-(wrogowie[i].rozmx/2),(wrogowie[i].y-kamy)-(wrogowie[i].rozmy/2)+14);
            circlefill(ekran,wrogowie[i].x-kamx,wrogowie[i].y-kamy,3,makecol(0,0,0));
            //textprintf_ex(ekran,font,(wrogowie[i].x-kamx)-20,(wrogowie[i].y-kamy)-(wrogowie[i].rozmy/2)-30,makecol(255,100,56),"%d",wrogowie[i].zycie,-1);

        }
    }

    rysuj_wrg_bron(wrogowie,kamx,kamy);
}
#endif
