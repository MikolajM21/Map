/** @file */
/*
PODSTAWY PROGRAMOWANIA KOMPUTEROW
Projekt: Mapa
*/
#include "txtactions.h"

bool loadPaths(string& filePaths,map< pair < string, string>,double>& paths)
{
    fstream file1;
    file1.open(filePaths, ios::in);
    if(file1.good())
    {
        string city1,city2;
        double distance;
        while(!file1.eof())
        {
            file1 >> city1 >> city2 >> distance;
            paths.insert(make_pair(make_pair(city1, city2), distance));
        }
        file1.close();
        return true;
    }
    else
    {
        cout << endl << " Nie znaleziono pliku z drogami o podanej nazwie!" << endl;
        return false;
    }
}
bool loadRoutes(string& fileRoads,queue < pair < string, string>>& routes)
{
    fstream file1;
    file1.open(fileRoads, ios::in);
    if(file1.good())
    {
        string startCity,finalCity;
        while(!file1.eof())
        {
            file1 >> startCity >> finalCity;
            routes.push(make_pair(startCity, finalCity));
        }
        file1.close();
        return true;
    }
    else
    {
        cout << endl << " Nie znaleziono pliku z trasami o podanej nazwie!" << endl;
        return false;
    }
}
bool checkResultsFile(string& fileResults)
{
    ofstream file1;
    file1.open(fileResults);
    if(file1.good())
    {
        file1.close();
        return true;
    }
    else
    {
        cout << endl << " Nie znaleziono pliku wynikowego o podanej nazwie!" << endl;
        return false;
    }
}
void saveResult(string& fileResults,map < string, pair<int,pair < float, string >>>& summits, queue < pair < string, string>>& routes, deque<pair<string,pair<string,float>>>& result,map < string, pair <int,pair < float, string >>> :: iterator& itSummits)
{
    ofstream file1;
    file1.open(fileResults, ios_base::app);
    cout << endl << "Trasa: " << routes.front().first << " --> " << routes.front().second;
    file1 << endl << "Trasa: " << routes.front().first << " --> " << routes.front().second;
    if(rewriteResult(summits,routes,result,itSummits))
    {
        double sum = 0;
        for (const auto &elem : result)
        {
            sum += elem.second.second;
        }
        cout << " (" << sum << "km):" << endl;
        file1 << " (" << sum << "km):" << endl;
        for (const auto &elem : result)
        {
            cout << elem.first << " --> " << elem.second.first << " " << elem.second.second << endl;
            file1 << elem.first << " --> " << elem.second.first << " " << elem.second.second << endl;
        }
    }
    else
    {
        cout <<endl << "TRASA NIEMOZLIWA DO WYZNACZENIA" << endl;
        file1 << endl << "TRASA NIEMOZLIWA DO WYZNACZENIA" << endl;
    }
    file1.close();
    result.clear();
    routes.pop();
}