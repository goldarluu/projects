/*
    OMG it ran?
    Ho, Adam
    Luu, Goldar

    May 19, 2021

    CS A250
    Project 2
*/

#include "Testing.h"
#include "Interface.h"
#include "CookieDB.h"
#include <iomanip>

using namespace std;

int main()
{
    CookieList myCookieList;
    createCookieList(myCookieList);
    displayMenu();
    processChoice(myCookieList);
    cout << "\n";
    return 0;
}