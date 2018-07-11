#ifndef struktury_h
#define struktury_h

#include <allegro.h>
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <sstream>

struct animacja
{
    BITMAP *obrazek;
    int ile;
    int czas;
    int klatka;
};

struct gun
{
    std::string nazwa;
    int typ;
    int damage;
    int amunicja;
    double reload;
    int rozrzut;
    int pred_poc;
    bool boom;
    int boom_r;
    bool strzal;
};

struct postac
{
    int x;
    double y;
    double ky;
    int rozx;
    int rozy;
    int bron;
    gun pasek_broni[ilebron];
    int sytuacja;
    BITMAP *obrazek;
    animacja animacje[8];
    int zycie;
    int skupienie;
};

struct pocisk
{
    int typ;
    double x;
    double y;
    double kat;
    int pred;
    int rozrzut;
    bool boom;
};

struct wrg
{
    int typ;
    double x;
    double y;
    double ky;
    int rozmx;
    int rozmy;
    int zycie;

    int celx;
    int cely;

    int stan;

    double reload;

    int odst;

    int sytuacja;
    animacja animacje[4];
    BITMAP *obrazek;
};

struct explz
{
    int typ;
    int x;
    int y;
    int r;
    int damage;
    double czas;
};

struct portal
{
    int x;
    int y;
};
#endif
