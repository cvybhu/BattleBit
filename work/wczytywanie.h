#ifndef wczytywanie_h
#define wczytywanie_h

#include <allegro.h>
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <sstream>

std::string in_2_str(int ienti)
{
     std::ostringstream cus;
     cus << ienti;
     return cus.str();
}

char* cz_p_st(char* czar,std::string sztring)  //dodaje char do str
{
    std::string s = czar;
    s = s + sztring;
    char *efekt = &s[0u];
    return(efekt);
}

void wczytaj_bitmapy(char* scie)
{
    bufor = create_bitmap(szer,wys);

    graj_prz = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\menu\\graj_guzik.bmp"),0);
    graj_prz_prz = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\menu\\graj_guzik_prz.bmp"),0);
    wyjscie_prz = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\menu\\wyjscie.bmp"),0);
    wyjscie_prz_prz = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\menu\\wyjscie_wcis.bmp"),0);
    ustawienia_prz = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\menu\\ustawienia_guzik.bmp"),0);
    ustawienia_prz_prz = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\menu\\ustawienia_guzik_prz.bmp"),0);

    logo = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\menu\\logo.bmp"),0);

    if(szer == 1920)
    {
    menu_tlo = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\menu\\menu_tlo.bmp"),0);
    }
    else
    {
    menu_tlo = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\menu\\menu_tlo_male.bmp"),0);
    }

    ukonczony = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\menu\\ukonczony.bmp"),0);

    dalej = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\menu\\dalej.bmp"),0);
    dalej_prz = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\menu\\dalej_wcis.bmp"),0);
    menu_guz = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\menu\\menu_guz.bmp"),0);
    menu_guz_prz = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\menu\\menu_guz_wcis.bmp"),0);

    porusz_tut = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\tla\\poruszanie.bmp"),0);
    skoki_tut = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\tla\\skoki.bmp"),0);
    strzal_tut = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\tla\\strzal.bmp"),0);
    zmiana_tut = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\tla\\zmian_bron.bmp"),0);
    skup_tut = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\tla\\spowol.bmp"),0);


    celownik = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\bron\\celow.bmp"),0);

    tlo = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\tla\\tlo1.bmp"),0);

    wyjsc = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\tla\\portal.bmp"),0);
    wyjsc_pods = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\tla\\portal_podsw.bmp"),0);

	boh_stoi_L = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\ludziowie\\bohater\\tulow_stoi_L.bmp"),0);
	boh_stoi_P = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\ludziowie\\bohater\\tulow_stoi_P.bmp"),0);
	boh_idzie_L = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\ludziowie\\bohater\\chodzenie_L.bmp"),0);
	boh_idzie_P = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\ludziowie\\bohater\\chodzenie_P.bmp"),0);
	boh_skacze_L = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\ludziowie\\bohater\\skok_L.bmp"),0);
	boh_skacze_P = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\ludziowie\\bohater\\skok_P.bmp"),0);

	blok1 = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\bloki\\z.bmp"),0);
	blok2 = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\bloki\\m.bmp"),0);

	wrg_stoi = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\ludziowie\\wrogowie\\wrog_stoi.bmp"),0);
	wrg_idzie_L = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\ludziowie\\wrogowie\\wrog_chodz_L.bmp"),0);
	wrg_idzie_P = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\ludziowie\\wrogowie\\wrog_chodz_P.bmp"),0);
	wrg_skacze = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\ludziowie\\wrogowie\\wrog_skok.bmp"),0);

	wrg_bron = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\ludziowie\\wrogowie\\wrog1_bron.bmp"),0);
	wrg_bron_strzal = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\ludziowie\\wrogowie\\wrog1_bron_strzal.bmp"),0);
	wrg_bron_odw = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\ludziowie\\wrogowie\\wrog1_bron_odw.bmp"),0);
	wrg_bron_strzal = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\ludziowie\\wrogowie\\wrog1_bron_strzal_odw.bmp"),0);

	karabin = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\ludziowie\\bohater\\rece_karabin_P.bmp"),0);
	karabin_odw = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\ludziowie\\bohater\\rece_karabin_L.bmp"),0);
	karabin_strzal = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\ludziowie\\bohater\\rece_karabin_P_strzal.bmp"),0);
	karabin_odw_strzal = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\ludziowie\\bohater\\rece_karabin_L_strzal.bmp"),0);

	bazooka = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\ludziowie\\bohater\\rece_bazooka_P.bmp"),0);
	bazooka_odw = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\ludziowie\\bohater\\rece_bazooka_L.bmp"),0);
	bazooka_strzal = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\ludziowie\\bohater\\rece_bazooka_P_strzal.bmp"),0);
	bazooka_odw_strzal = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\ludziowie\\bohater\\rece_bazooka_L_strzal.bmp"),0);

    bazooka_sam = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\bron\\bazooka.bmp"),0);
    karabin_sam = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\bron\\karabin.bmp"),0);

    ramka = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\tla\\ramka.bmp"),0);
    ramka2 = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\tla\\ramka2.bmp"),0);

    pasek = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\tla\\pasek.bmp"),0);

    boom = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\bron\\explozja.bmp"),0);

	pocisk1 = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\bron\\pocisk1.bmp"),0);
	pocisk2 = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\bron\\pocisk2.bmp"),0);

	pocisk200 = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\bron\\pocisk200.bmp"),0);

	guz_tutorial = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\menu\\tutorial.bmp"),0);
    guz_tutorial_prz = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\menu\\tutorial_prz.bmp"),0);
    guz_poziom1 = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\menu\\poziom_1.bmp"),0);
    guz_poziom1_prz = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\menu\\poziom_1_prz.bmp"),0);
    guz_wlasny = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\menu\\poziom_wlasny.bmp"),0);
    guz_wlasny_prz = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\menu\\poziom_wlasny_prz.bmp"),0);


	zapisywanie = load_bmp(cz_p_st(scie,"\\pliki\\grafika\\tla\\zapisywanie.bmp"),0);
}

void wczytaj_fonty(char *sciezka)
{
 troika = load_font(cz_p_st(sciezka,"\\pliki\\czcionki\\troika.pcx"),0,0);
}

portal wczytaj_poziom(char* sciezka,char **tablica,wrg wrogowie[ilewrog], portal wyjscie,int spawn[2])       //wczytuje plansze z pliku do tablicy
{
    std::string linia;
    std::ifstream lewel;
    int lin = 0;
    lewel.open(sciezka);
    if(lewel.is_open() == 1)
    {
        while(lewel.good())
        {
            getline(lewel,linia);
            for(int y = 0;y < linia.size();y++)
            {
                if(linia[y] == 'w')
                {
                    dodaj_wroga(1,y*50,lin*50,wrogowie);
                    linia[y] = ' ';
                }

                if(linia[y] == 'p')
                {
                    wyjscie.x = y*50-35;
                    wyjscie.y = lin*50-180;
                    linia[y] = ' ';
                }

                if(linia[y] == 's')
                {
                    spawn[0] = y*50-35;
                    spawn[1] = lin*50-180;
                    linia[y] = ' ';
                }

                tablica[lin][y] = linia[y];

            }
            lin++;
        }
    }
    lewel.close();

    return wyjscie;

}

void wczytaj_animacje(animacja animacje[8])
{
    for(int i = 0; i < 8;i++)
    {
        animacje[i].klatka = 0;
    }

    animacje[0].ile = 1;
    animacje[0].czas = 100000;
    animacje[0].obrazek = boh_stoi_L;

    animacje[1].ile = 1;
    animacje[1].czas = 100000;
    animacje[1].obrazek = boh_stoi_P;

    animacje[2].ile = 10;
    animacje[2].czas = int(2.5/60.0*double(SZYBKOSC));
    animacje[2].obrazek = boh_idzie_L;

    animacje[3].ile = 10;
    animacje[3].czas = int(2.5/60.0*double(SZYBKOSC));
    animacje[3].obrazek = boh_idzie_P;

    animacje[4].ile = 0;
    animacje[4].czas = int(10.0/60.0*double(SZYBKOSC));
    animacje[4].obrazek = boh_skacze_L;

    animacje[5].ile = 0;
    animacje[5].czas = int(10.0/60.0*double(SZYBKOSC));
    animacje[5].obrazek = boh_skacze_P;

    animacje[6].ile = 1;
    animacje[6].czas = 100000;
    animacje[6].obrazek = create_bitmap(170,200);

    animacje[7].ile = 1;
    animacje[7].czas = 100000;
    animacje[7].obrazek = create_bitmap(170,200);

    /*

    animacje[8].ile = 1;
    animacje[8].czas = 100000;
    animacje[8].obrazek = boh_stoi_P;
    */
}
#endif
