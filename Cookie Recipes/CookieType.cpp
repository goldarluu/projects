/*
    OMG it ran?
    Ho, Adam
    Luu, Goldar

    May 19, 2021

    CS A250
    Project 2
*/

#include "cookieType.h" 
#include <iostream> 

using namespace std; 

CookieType::CookieType(const string& newCookieName, size_t newCalories)
{
	cookieName = newCookieName; 
	calories = newCalories; 
}

size_t CookieType::getCalories() const
{
	return calories; 
}

string CookieType::getCookieName() const
{
	return cookieName; 
}

void CookieType::setCookieName(const string& newCookieName)
{
	cookieName = newCookieName;
}

void CookieType::setCalories(size_t newCalories)
{
	calories = newCalories; 
}

