/** @file */
/*
PODSTAWY PROGRAMOWANIA KOMPUTEROW
Projekt: Mapa
*/
#include "functions.h"
#include "instruction.h"
#include "txtactions.h"
#include "switches.h"

int main(int argc, char* argv[])
{
map < pair < string, string>,double> paths;
queue < pair < string, string>> routes;
map < string, pair<int,pair < float, string >>> summits;
deque<pair<string,pair<string,float>>> result;
map < pair < string, string>,double>:: iterator itPaths;
map < string, pair <int,pair < float, string >>> :: iterator itSummits;
    string filePaths,fileRoutes,fileResults;
    if(switches(argc, argv, filePaths, fileRoutes, fileResults))
    {
        if(loadPaths(filePaths,paths) && loadRoutes(fileRoutes,routes) && checkResultsFile(fileResults))
        {
            findSummits(paths,summits,itSummits, itPaths);
            while(!routes.empty())
           {
               dijkstra(paths,routes,summits,itSummits);
               saveResult(fileResults,summits,routes,result,itSummits);
           }
        }
    }
    else
        {
        instruction();
        }
    deleteStructures(paths,summits);
    return 0;
}
