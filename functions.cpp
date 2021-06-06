/** @file */
/*
PODSTAWY PROGRAMOWANIA KOMPUTEROW
Projekt: Mapa
*/
#include "functions.h"

void findSummits(map< pair < string, string>,double>& paths, map < string, pair<int,pair < float, string >>>& summits,map < string, pair <int,pair < float, string >>> :: iterator& itSummits,map < pair < string, string>,double>:: iterator& itPaths)
{
    itPaths=paths.begin();
    auto itS2=itSummits;
    summits.emplace(make_pair(itPaths->first.first, make_pair(0, make_pair(0, "0"))));
    for(const auto& elem : paths)
    {
        itSummits= itS2=summits.begin();
        for(const auto& elementS : summits)
        {
            if(elementS.first != elem.first.first)
            {
                itSummits++;
            }
            if(elementS.first != elem.first.second)
            {
                itS2++;
            }
        }
        if(itSummits == summits.end())
        {
            summits.emplace(make_pair(elem.first.first, make_pair(0, make_pair(0, "0"))));
            itS2++;
        }
        if(itS2 == summits.end())
        {
            summits.emplace(make_pair(elem.first.second, make_pair(0, make_pair(0, "0"))));
        }
    }
}
void dijkstra(map< pair < string, string>,double>& paths,queue < pair < string, string>>& routes, map < string, pair<int,pair < float, string >>>& summits,map < string, pair <int,pair < float, string >>> :: iterator& itSummits)
{
    for (auto &elementS : summits)
    {
        if (elementS.first == routes.front().first)
        {
            elementS.second.second.first=0;
        }
        else
        {
            elementS.second.second.first=numeric_limits<float>::infinity();
        }
        elementS.second.second.second="0";
    }
    int checkSum = 0;
    float tmp;
    auto itS2=itSummits;
    while(checkSum != summits.size())
    {
        tmp=numeric_limits<float>::infinity();
        for (itSummits = summits.begin(); itSummits != summits.end(); itSummits++)
        {
            if (itSummits->second.first == 0 && itSummits->second.second.first <= tmp)
            {
                itS2 = itSummits;
                tmp=itSummits->second.second.first;
            }
        }
        for (const auto& elem : paths)
        {
            if(elem.first.first == itS2->first)
            {
                for (auto& elementS : summits)
                {
                    if(elementS.first == elem.first.second)
                    {
                        if (elementS.second.first != 1 && (itS2->second.second.first + elem.second < elementS.second.second.first))
                        {
                            elementS.second.second.first = elem.second;//itS2->second.second.first +
                            elementS.second.second.second = itS2->first;
                        }
                    }
                }
            }
        }
        itS2->second.first=1;
        checkSum++;
    }
    for(auto& elementW : summits)
    {
        elementW.second.first=0;
    }
}
bool rewriteResult(map < string, pair<int,pair < float, string >>>& summits, queue < pair < string, string>>& routes, deque<pair<string,pair<string,float>>>& result, map < string, pair <int,pair < float, string >>> :: iterator& itSummits)
{
    string city;
    for (itSummits = summits.begin(); itSummits->first != routes.front().second; itSummits++){}
    result.push_front(make_pair(itSummits->second.second.second, make_pair(itSummits->first, itSummits->second.second.first)));
    city=itSummits->second.second.second;
    while(city != routes.front().first)
    {
        if(itSummits->second.second.second == "0")
        {
            return false;
        }
        for (itSummits = summits.begin(); itSummits->first != city; itSummits++){}
        result.push_front(make_pair(itSummits->second.second.second, make_pair(itSummits->first, itSummits->second.second.first)));
        city=itSummits->second.second.second;
    }
    return true;
}
void deleteStructures(map< pair < string, string>,double>& paths, map < string, pair<int,pair < float, string >>>& summits)
{
    paths.clear();
    summits.clear();
}
void testPrinting(map< pair < string, string>,double>& paths,queue < pair < string, string>>& routes,map < string, pair<int,pair < float, string >>>& summits)
{
    for(const auto& elem : paths)
    {
        cout << elem.first.first << " " << elem.first.second << " " << elem.second << "\n";
    }
    cout << routes.front().first << " " << routes.front().second << endl;
    for(const auto& elementS : summits)
    {
        cout << elementS.first << " " << elementS.second.first << " " << elementS.second.second.first << " " << elementS.second.second.second << endl;
    }
}