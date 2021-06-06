/** @file */
#ifndef FUNKCJE_H
#define FUNKCJE_H
#include <iostream>
#include <map>
#include <queue>
#include <deque>
#include <string>
using namespace std;

/** Funkcja znajduje wierzcholki grafu na podstawie drog miedzy miastami
 */
void findSummits(map< pair < string, string>,double>& paths,map < string, pair<int,pair < float, string >>>& summits,map < string, pair <int,pair < float, string >>> :: iterator& itSummits,map < pair < string, string>,double>:: iterator& itPaths);
/** Funkcja wykonuje algorytm dijkstry oraz relaksacje lukow grafu
 */
void dijkstra(map< pair < string, string>,double>& paths, queue < pair < string, string>>& routes, map < string, pair<int,pair < float, string >>>& summits,map < string, pair <int,pair < float, string >>> :: iterator& itSummits);
/** Funkcja znajduje wyznaczona trase w mapie wierzcholkow i przekazuje kolejne odcinki do kolejki
 @return true or false
 */
bool rewriteResult(map < string, pair<int,pair < float, string >>>& summits, queue < pair < string, string>>& routes, deque<pair<string,pair<string,float>>>& result,map < string, pair <int,pair < float, string >>> :: iterator& itSummits);
/** Funkcja usuwa struktury uzywane w programie
 */
void deleteStructures(map< pair < string, string>,double>& paths,map < string, pair<int,pair < float, string >>>& summits);
/** Funkcja do pomocniczego wyswietlania aktualnej zawartosci struktur
 */
void testPrinting(map< pair < string, string>,double>& paths,queue < pair < string, string>>& routes,map < string, pair<int,pair < float, string >>>& summits);
#endif