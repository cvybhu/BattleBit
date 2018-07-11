#ifndef menu_h
#define menu_h

#include <allegro.h>
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

void menu(char* scie)
{
    set_mouse_speed(1,1);

    int wybor = 0;

    int odczekacz = 0;

    while(!key[KEY_ESC])
    {

        odczekacz ++;

        wybor = -1;

        draw_sprite(bufor,menu_tlo,0,0);
        draw_sprite(bufor,logo,szer/2-400,0);
        draw_sprite(bufor,graj_prz,szer/2-225,350);
        draw_sprite(bufor,wyjscie_prz,szer/2-194,388+200);
        //draw_sprite(bufor,ustawienia_prz,szer/2-250,650);


        if(odczekacz > 200)
        {

        for(int i = 0;i < 4;i++)
        {
            //if(mouse_x > szer/2-250 && mouse_x < szer/2+250 && mouse_y > i*200 && mouse_y < i*200)wybor = i;
        }

        if(mouse_x > szer/2-225 && mouse_x < szer/2+225 && mouse_y > 350 && mouse_y < 350+155)
        {
            draw_sprite(bufor,graj_prz_prz,szer/2-225,350);
            if(mouse_b & 1)
            {
            odczekacz = 0;
            while(!key[KEY_ESC])
            {
                int wybor = -1;

                draw_sprite(bufor,menu_tlo,0,0);
                draw_sprite(bufor,logo,szer/2-400,0);

                draw_sprite(bufor,guz_tutorial,szer/2-225,300);
                draw_sprite(bufor,guz_poziom1,szer/2-225,300+210);
                draw_sprite(bufor,guz_wlasny,szer/2-225,300+210+210);


                if(odczekacz > 200)
                {
                for(int i = 0;i < 3;i++)
                {
                    if(mouse_x > szer/2-255 && mouse_x < szer/2+255 && mouse_y > 300+210*i && mouse_y < 300+200+210*i)
                    {
                        wybor = i;
                        break;
                    }
                }

                if(wybor == 0)
                {
                    draw_sprite(bufor,guz_tutorial_prz,szer/2-225,300);
                    if(mouse_b & 1)
                    {
                        graj(scie,1);

                        odczekacz = 0;
                        break;
                    }

                }

                if(wybor == 1)
                {
                    draw_sprite(bufor,guz_poziom1_prz,szer/2-225,300+210);
                    if(mouse_b & 1)
                    {
                        graj(scie,2);

                        odczekacz = 0;
                        break;
                    }
                }

                if(wybor == 2)
                {
                    draw_sprite(bufor,guz_wlasny_prz,szer/2-225,300+210+210);
                    if(mouse_b & 1)
                    {
                        graj(scie,1234);

                        odczekacz = 0;
                        break;
                    }
                }

                }

                draw_sprite(bufor,celownik,mouse_x-35,mouse_y-25);

                textprintf_ex(bufor, troika, 0,wys-30, makecol(100, 100, 100),-1,"%Jan Ciolek");

                draw_sprite(screen,bufor,0,0);

                odczekacz++;
            }
            odczekacz = 0;
            }
        }

        if(odczekacz > 200 && mouse_x > szer/2-194 && mouse_x < szer/2+194 && mouse_y > 388+200 && mouse_y < 388+200+107)
        {
            draw_sprite(bufor,wyjscie_prz_prz,szer/2-194,388+200);
            if(mouse_b & 1)
            {
            break;
            odczekacz = 0;
            }
        }


        /*if(wybor == 1)
        {
            draw_sprite(bufor,edytor_prz_prz,szer/2-250,450);
            if(mouse_b & 1)
            {
            graj(scie,1);
            odczekacz = 0;
            }
        }

        if(wybor == 2)
        {
            draw_sprite(bufor,ustawienia_prz_prz,szer/2-250,650);
            if(mouse_b & 1)
            {
            graj(scie,1);
            odczekacz = 0;
            }
        }*/

        }



        draw_sprite(bufor,celownik,mouse_x-25,mouse_y-25);

        textprintf_ex(bufor, troika, 0,wys-30, makecol(100, 100, 100),-1,"%Jan Ciolek");

        draw_sprite(screen,bufor,0,0);
}
}

void ustawienia(char* scie)
{
    uproszcz_kol = true;
}


#endif
