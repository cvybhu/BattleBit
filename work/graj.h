#ifndef graj_h
#define graj_h

#include <allegro.h>
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

postac bohateruch (postac bohater,char **mapa,double speed,int kamx);

postac boha_strzel(postac bohater,pocisk pociski[ilepoc],int kamx,int kamy);

void graj(char* scie,int poziom)
{
    set_mouse_speed(2,2);

    postac bohater;

    portal wyjscie;

    bohater.x = 16*50;
    bohater.y = 16*50;
    bohater.rozx = 170;
    bohater.rozy = 200-1;
    bohater.ky = 0;

    bohater.zycie = 100;
    bohater.skupienie = skup;

    bohater.bron = 1;

    wczytaj_animacje(bohater.animacje);

    bohater.pasek_broni[0].nazwa = "Karabin";
    bohater.pasek_broni[0].typ = 1;
    bohater.pasek_broni[0].damage = 5;
    bohater.pasek_broni[0].pred_poc = 25;
    bohater.pasek_broni[0].reload = 0;
    bohater.pasek_broni[0].rozrzut = 2;
    bohater.pasek_broni[0].boom = true;
    bohater.pasek_broni[0].amunicja = 1234;


    bohater.pasek_broni[1].nazwa = "Bazooka";
    bohater.pasek_broni[1].typ = 2;
    bohater.pasek_broni[1].damage = 100;
    bohater.pasek_broni[1].pred_poc = 16;
    bohater.pasek_broni[1].reload = 0;
    bohater.pasek_broni[1].rozrzut = 1;
    bohater.pasek_broni[1].boom = true;
    bohater.pasek_broni[1].boom_r = 150;
    bohater.pasek_broni[1].amunicja = 10;

    int kamx = 0;
    int kamy = 0;
    int wympoz = (szer-szer%50)/50+2;
    int wympion = (wys-wys%50)/50+2;
    int przesy = 0;     //wartosc, o ktora kazdy blok jest przesuniety wzgledem siatki 50x50

    int koniec = SZYBKOSC*0.5;

    bool kamruch = true;
    int odst = 0;

    pocisk pociski[ilepoc];
    wrg wrogowie[ilewrog];
    explz explozja[ileexpl];

    double speed = 1.0;

    for(int i = 0;i < ilepoc;i++)pociski[i].typ = 0;
    for(int i = 0;i < ileexpl;i++)explozja[i].typ = 0;
    for(int i = 0;i < ilewrog;i++)wrogowie[i].typ = 0;

    int rozy;       //wymiary tablicy zawierajacej cala mape
    int rozx;       //

    string s = scie;

    if(poziom != 1234)
    {
    s = s + "\\pliki\\mapy\\lvl"+in_2_str(poziom)+"\\mapa.txt";
    }
    else
    {
    s = s + "\\poziom wlasny\\lvl"+in_2_str(poziom)+"\\mapa.txt";
    }
    char *sciezka = &s[0u];

    string linijka;     // \/
    ifstream level;

    level.open(sciezka);
    if(level.is_open() == 1)
        {
            rozy = 0;
            rozx = 0;
            while(level.good())     //otwiera plik z mapa, aby okreslic rozmiary tablicy zawierajacej cala mape
            {
                getline(level,linijka);
                if(linijka.size() > rozx)rozx = linijka.size();
                rozy++;
            }
        }
    level.close();  // /\

    char ** mapa = new char * [rozy];

    for(int i = 0;i < rozy;i++)     //deklaruje dynamiczna tablice, zawierajaca cala mape
    {
     mapa[i] = new char[rozx];
    }

    for(int c = 0;c < rozy;c++)for(int k = 0;k < rozx;k++)mapa[c][k] = 'z';     //zapelnia ta tablice blokami(literkami 'z')

    int spawn[] = {0,0};

    wyjscie = wczytaj_poziom(sciezka, mapa,wrogowie,wyjscie,spawn);      //wczytuje mape z pliku do tablicy

    bohater.x = spawn[0];
    bohater.y = spawn[1];


	bufor = create_bitmap(szer,wys);

	takicus = create_bitmap(600,400);

	bohater.sytuacja = 0;
	//bohater = animuj_bohatera(bohater);
	bohater.obrazek = create_bitmap(170,200);

    long int npw = 0;


	while (!key[KEY_ESC])       ////////////////////////////////////////////////////////////////////
	{
       while(tajmer > 0)
       {

        bohater = bohateruch(bohater,mapa,speed,kamx);

        bohater = animuj_bohatera(bohater,npw);

        bohater = boha_strzel(bohater,pociski,kamx,kamy);

        speed = 1;

        if(key[KEY_F12])
        {
            draw_sprite(screen,zapisywanie,szer/2-400,wys/2-100);
            save_bmp(cz_p_st(scie,"\\screenshoty\\"+in_2_str(npw*(rand()%3+1))+".bmp"),bufor,default_palette);

        }

        if(key[KEY_LCONTROL] && bohater.skupienie > 0)
        {
            bohater.skupienie -= 2;

            speed = 0.3;     //slow-mo
        }

        /*if((mouse_b & 2)&&(odst < 1))
        {
            dodaj_wroga(1,kamx+mouse_x,kamy+mouse_y,wrogowie);
            odst = 30;
        }*/

        kamx = kameruj_x(bohater.x,bohater.y,kamruch);
        kamy = kameruj_y(bohater.x,bohater.y,kamruch);

        lataj_pociski(pociski,explozja,mapa,speed);
        bohater = kolizjuj_pociski(bohater,wrogowie,pociski,explozja,uproszcz_kol);
        exploduj(explozja,wrogowie,speed);
        AI (bohater.x,bohater.y,mapa,wrogowie,pociski,speed,npw);

        prtl = wyjsc;
        if(bohater.x > wyjscie.x && bohater.x < wyjscie.x+140 && bohater.y > wyjscie.y && bohater.y < wyjscie.y+240)
        {
            prtl = wyjsc_pods;
           if(koniec != 0)koniec--;
        }

        if(bohater.skupienie < skup)bohater.skupienie++;

        tajmer--;

        if(odst > 0)odst--;

        for(int i = 0;i < ilebron;i++)bohater.pasek_broni[i].reload -= 1.0*speed;
       }

        draw_sprite(bufor,tlo,0,0);

        if(poziom == 1)
        {
            draw_sprite(bufor,porusz_tut,19*50-kamx,13*50-kamy);
            draw_sprite(bufor,skoki_tut,60*50-kamx,31*50-kamy);
            draw_sprite(bufor,strzal_tut,78*50-kamx,19*50-kamy);
            draw_sprite(bufor,zmiana_tut,126*50-kamx,20*50-kamy);
            draw_sprite(bufor,skup_tut,157*50-kamx,24*50-kamy);
        }


        rysuj_plansze(mapa,wympoz,wympion,kamx,kamy);

        draw_sprite(bufor,prtl,wyjscie.x-kamx,wyjscie.y-kamy);

        //for(int e = 0;e < ilewrog;e++)if(wrogowie[e].typ != 0)draw_sprite(wrogowie[e].obrazek,wrg_stoi,0,0);//animuj_wroga(wrogowie[e],npw);

        rysuj_pociski(pociski,kamx,kamy);

        rysuj_wrogow(wrogowie,kamx,kamy,bufor);

        rysuj_bohatera(bohater.x,bohater.y,bohater.rozx,bohater.rozy,kamx,kamy,bohater.obrazek);
        rysuj_bron(bohater.x-kamx,bohater.y-kamy-20,mouse_x,mouse_y,bohater.bron,bohater.pasek_broni[bohater.bron-1].reload);
        rysuj_explozje(explozja,kamx,kamy);

        rysuj_miedzymordzie(bohater);        //interface = miedzymordzie :D

        draw_sprite(bufor,celownik,mouse_x-35,mouse_y-25);

	    draw_sprite(screen,bufor,0,0);


        npw++;
        if(npw > 123456)npw = 0;

        if(bohater.zycie < 1)koniec = -1;

        if(koniec < 1)break;

	}

	for(int i = 0;i < rozy;i++)delete [] mapa[i]; //zwalnianie pamieci po tablicy mapa
    delete [] mapa;

    if(koniec == 0)
    {
        draw_sprite(bufor,ukonczony,szer/2-350,wys/2-250);
        BITMAP *tylo = create_bitmap(szer,wys);
        draw_sprite(tylo,bufor,0,0);

        while(!key[KEY_ESC])
        {
        draw_sprite(bufor,tylo,0,0);

        if(poziom == 1)draw_sprite(bufor,dalej,szer/2-185,wys/2-30);
        draw_sprite(bufor,menu_guz,szer/2-185,wys/2-30+120);

        if(poziom == 1 && mouse_x > szer/2-185 && mouse_x < szer/2+185 && mouse_y > wys/2-30 && mouse_y < wys/2-30+90)
        {
        draw_sprite(bufor,dalej_prz,szer/2-185,wys/2-30);
        if(mouse_b & 1)graj(scie,poziom+1);
        }

        if(mouse_x > szer/2-185 && mouse_x < szer/2+185 && mouse_y > wys/2-30+120 && mouse_y < wys/2-30+90+120)
        {
        draw_sprite(bufor,menu_guz_prz,szer/2-185,wys/2-30+120);
        if(mouse_b & 1)break;
        }

        draw_sprite(bufor,celownik,mouse_x-35,mouse_y-25);

        draw_sprite(screen,bufor,0,0);
        }
    }
}

postac boha_strzel(postac bohater,pocisk pociski[ilepoc],int kamx,int kamy)
{

        if(key[KEY_1])bohater.bron = bohater.pasek_broni[0].typ;
        if(key[KEY_2])bohater.bron = bohater.pasek_broni[1].typ;
        //if(key[KEY_3])bohater.bron = bohater.pasek_broni[2].typ;
        //if(key[KEY_4])bohater.bron = bohater.pasek_broni[3].typ;

    if((mouse_b & 1) && bohater.pasek_broni[bohater.bron-1].amunicja > 0)
        {
            if(bohater.pasek_broni[bohater.bron-1].reload < 1)
            {
                bohater.pasek_broni[bohater.bron-1].amunicja--;

                if(bohater.bron == 1)strzelaj(bohater.bron,pociski,bohater.x,bohater.y-45,kamx+mouse_x,kamy+mouse_y);
                if(bohater.bron == 2)strzelaj(bohater.bron,pociski,bohater.x,bohater.y-55,kamx+mouse_x,kamy+mouse_y);


                if(bohater.bron == 1)bohater.pasek_broni[0].reload = karab_reload;
                if(bohater.bron == 2)bohater.pasek_broni[1].reload = bazook_reload;
            }
        }

        return bohater;
}

postac bohateruch (postac bohater,char **mapa,double speed,int kamx)
{
        int dopraw = iledo(1,mapa,bohater.x,bohater.y,50,bohater.rozy,speed);
        int dolew = iledo(3,mapa,bohater.x,bohater.y,50,bohater.rozy,speed);
        int dogor = iledo(0,mapa,bohater.x,bohater.y,50,bohater.rozy,speed);        //wykrywanie kolizji
        int dodol = iledo(2,mapa,bohater.x,bohater.y,50,bohater.rozy,speed);

        if((bohater.x-kamx) > mouse_x)
        {
            bohater.sytuacja = 0;
        }
        else
        {
            bohater.sytuacja = 1;
        }

        if(key[KEY_A])
        {
            bohater.x -= dolew;
            bohater.sytuacja = 200;
        }

        if(key[KEY_D])
        {
            bohater.x += dopraw;                //poruszanie
            bohater.sytuacja = 200;
        }

        if(bohater.sytuacja == 200)
        {
            if((bohater.x-kamx) > mouse_x)
                {
                    bohater.sytuacja = 2;       //chodzenie w lewo
                }
                else
                {
                    bohater.sytuacja = 3;     //chodzenie w prawo
                }
        }

        if((key[KEY_W] || key[KEY_SPACE]) && dodol < 5 && dogor > 30)
        {
            bohater.ky = -15;
            bohater.y -= 3;
            dodol = 6;
        }

        if(dodol > 5)
        {
            if((bohater.x-kamx) > mouse_x)
                {
                    bohater.sytuacja = 4;       //skok w lewo
                }
                else
                {
                    bohater.sytuacja = 5;     //skok w prawo
                }
        }

        if(dodol <= 5)bohater.ky = 0,bohater.y += dodol;       // \|/

        if(dodol > 5)bohater.ky += 0.3 * speed;

        if(dogor < 3*speed/2)               //skoki
        {
           bohater.y -= dogor;
           bohater.ky = 3*speed;
        }

        if(bohater.ky > 0 && dodol < bohater.ky)bohater.ky = dodol;

        bohater.y += bohater.ky*speed;

        return bohater;
}


#endif
