/** @file */
/*
PODSTAWY PROGRAMOWANIA KOMPUTEROW
Projekt: Mapa
*/
#include "switches.h"

bool switches(int argc, char **argv, string& filePaths, string& fileRoads, string& fileResults)
{
    if(argc<=7)
    {
        string assistance;
        int checkSum = 0;
        for (int i = 0; i < argc; i++)
        {
            assistance = argv[i];
            if (assistance == "-d")
            {
                filePaths = argv[i + 1];
                checkSum++;
            }
            if (assistance == "-t")
            {
                fileRoads = argv[i + 1];
                checkSum++;
            }
            if (assistance == "-o")
            {
                fileResults = argv[i + 1];
                checkSum++;
            }
            if (assistance == "-h")
            {
                checkSum=5;
            }
        }
        if(checkSum == 3) return true;
        else return false;
    }
    else return false;
}

