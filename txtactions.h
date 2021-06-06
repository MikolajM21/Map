/** @file */
#ifndef MAIN_CPP_TXTACTIONS_H
#define MAIN_CPP_TXTACTIONS_H
#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <utility>
#include "functions.h"
using namespace std;

/** Funkcja pobiera sciezki miedzy wierzcholkami grafu
@param filePaths nazwa pliku wejsciowego z drogami
@return true or false
 */
bool loadPaths(string& filePaths,map< pair < string, string>,double>& paths);
/** Funkcja pobiera trasy do wyznaczenia
@param fileRoads nazwa pliku wejsciowego z trasami
@return true or false
 */
bool loadRoutes(string& fileRoads,queue < pair < string, string>>& routes);
/** Funkcja sprawdza czy podany plik wynikowy istnieje
@param fileResults nazwa pliku wynikowego
@return true or false
 */
bool checkResultsFile(string& fileResults);
/** Funkcja zapisuje wynik do pliku txt oraz wyswietla go w oknie konsoli
 @param fileResults nazwa pliku wynikowego
 */
void saveResult(string& fileResults,map < string, pair<int,pair < float, string >>>& summits, queue < pair < string, string>>& routes, deque<pair<string,pair<string,float>>>& result,map < string, pair <int,pair < float, string >>> :: iterator& itSummits);
#endif
