/*
    OMG it ran?
    Ho, Adam
    Luu, Goldar

    May 19, 2021

    CS A250
    Project 2
*/

#include "CookieList.h"
#include <algorithm>
#include <iomanip> 


using namespace std;

// Constructor
CookieList::CookieList()
{
    cookieList = new list<Cookie>;
}

// addCookie and overloaded addCookie
void CookieList::addCookie(const Cookie& aCookie)
{
    cookieList->push_back(aCookie);
}

void CookieList::addCookie(const std::string& newName,
    size_t newCalories, const std::set<std::string>& newIngredients,
    size_t newServings)
{
    Cookie newCookie(newName, newCalories, newIngredients,
        newServings);
    cookieList->push_back(newCookie);
}

// Accessor
size_t CookieList::getCount() const
{
    return cookieList->size();
}

bool CookieList::isEmpty() const
{
    return (cookieList->size() == 0);
}

void CookieList::printAllCookies() const
{
    cout << string(62, '-') << '\n'
    << "     COOKIE RECIPES                   " << '\n'
    << string(62, '-') << '\n'
    << '\n';

    for (const auto& currentCookie : *cookieList)
    {
        cout << "    " << currentCookie.getCookieName() 
        << '\n';
    }
}

void CookieList::clearList()
{
    cookieList->clear();
}

CookieList::CookieList(const CookieList& otherCookieList)
{
    cookieList = new list<Cookie>;
    *(this->cookieList) = *(otherCookieList.cookieList);
}

CookieList& CookieList::operator=(const CookieList& rightSide)
{
    if (&rightSide ==  this)
    {
        cerr << "Attempted assignment to itself.";
    }
    else
    {
        *(this->cookieList) = *(rightSide.cookieList);
    }
    return *this;
}

CookieList::~CookieList()
{
    delete cookieList;
    cookieList = nullptr; 
}

// Part C functions
void CookieList::printCookiesSelection() const
{
    int selectionNumber = 1;
    for (const auto& currentCookie : *cookieList)
    {
        cout << "    " << selectionNumber << ": "
            << currentCookie.getCookieName() << '\n';
        selectionNumber++;
    }

}

void CookieList::printRecipe(size_t selection) const
{
    auto listElement = cookieList->begin();
    for (size_t i = 1; i != selection; i++)
        listElement++;
    listElement->printRecipe();
}

// Selection c 
void CookieList::printCalories(size_t selection) const
{
    auto listElement = cookieList->begin();
    size_t i = 1; 
    while (i != selection) {
        listElement++;
        i++;
    }
    listElement->printCalories();
}

// Selection d 
void CookieList::printLimitedCalories(size_t maxCalories) const
{
    for (const Cookie& currentCookie : *cookieList)
    {
        if (currentCookie.getCalories() < maxCalories)
            currentCookie.printCalories();
    }
}

// Selection e
void CookieList::calorieBasedCookieCounter(size_t selection, double maxDailyCalories) const
{
    auto listElement = cookieList->begin();
    size_t i = 1;
    while (i != selection) {
        listElement++;
        i++;
    }
    cout << "You can eat "
         << fixed << setprecision(1) << (maxDailyCalories / static_cast<double>(listElement->getCalories())) << " "
         << listElement->getCookieName() << " cookie(s).\n";
}
