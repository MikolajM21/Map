/** @file */
#ifndef MAIN_CPP_SWITCHES_H
#define MAIN_CPP_SWITCHES_H
#include <string>
using namespace std;

/** Funkcja pobiera parametry uruchomienia programu i sprawdza poprawnosc danych
@param  arqc liczba parametrow uruchomienia programu
@param  argv tablica wskaznikow na parametry uruchomienia programu
@param filePaths nazwa pliku wejsciowego z drogami
@param fileRoads nazwa pliku wejsciowego z trasami
@param fileResults nazwa pliku wynikowego
@return true or false
 */
bool switches(int argc, char **argv, string& filePaths, string& fileRoads, string& fileResults);
#endif
