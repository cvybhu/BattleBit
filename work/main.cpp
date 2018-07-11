#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd       //do funkcji wyznaczajacej sciezke
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
 #endif


#include <allegro.h>
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <sstream>

#define wys 1080   //rozdzielczosc
#define szer 1920


#define ilepoc 1000
#define ileexpl 150
#define ilewrog 100     //ustawienia
#define ilebron 2

#define wrg_zyc 30;

#define skup 900

#define SZYBKOSC 140       //szybkosc gry

int karab_reload = 20;
int bazook_reload = 160;
int wrg_reload = 100;

bool uproszcz_kol = true;

#include "tajmer.h"
#include "struktury.h"
#include "grafika.h"
#include "symulacje.h"
#include "wczytywanie.h"
#include "AI.h"
#include "graj.h"
#include "edytor.h"
#include "menu.h"

using namespace std;

inline void init();

inline void deinit();

int main()
{
    init();

    ////////////////////////////////////
    char sciezka_do[FILENAME_MAX];

     if (!GetCurrentDir(sciezka_do, sizeof(sciezka_do)))    //wyznacza sicezke do exe
        {
        return errno;
        }
        sciezka_do[sizeof(sciezka_do) - 1] = '\0';
    ////////////////////////////////////

    wczytaj_bitmapy(sciezka_do);
    wczytaj_fonty(sciezka_do);


        menu(sciezka_do);

    deinit();

	return 0;
}

inline void init()
{
	allegro_init();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, szer, wys, 0, 0);

	install_timer();
	install_int_ex(increment_speed, BPS_TO_TIMER(SZYBKOSC));

	install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,0);

	install_keyboard();
	install_mouse();
}

inline void deinit()
{
	clear_keybuf();
	allegro_exit();
}

END_OF_MAIN()
