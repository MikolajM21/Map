/** @file */
#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <utility>
using namespace std;

/** map paths - struktura przechowujaca sciezki miedzy wierzcholkami grafu. Kluczem jest para miast a wartosc to odleglosc miedzy nimi */
map < pair < string, string>,double> paths;
/** queue routes - struktura przechowujaca routes do wyznaczenia w formie kolejki FIFO */
queue < pair < string, string>> routes;
/** map summits - struktura przechowujaca dane wierzcholkow. Kluczem jest nazwa miasta (wierzcholek), wartosci to pomocnicza zmienna
 * do sprawdzania (w dijkstrze) czy wierzcholek zostal juz odwiedzony, nastepnie odleglosc od porzednika i jego nazwe */
map < string, pair<int,pair < float, string >>> summits;
/** deque result - struktura przechowujaca wyznaczona trase */
deque<pair<string,pair<string,float>>> result;
/** iterator do poruszania sie po elementach mapy drog */
map < pair < string, string>,double>:: iterator itPaths;
/** iterator do poruszania sie po elementach mapy wierzcholkow */
map < string, pair <int,pair < float, string >>> :: iterator itSummits;
