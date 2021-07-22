/*
    OMG it ran?
    Ho, Adam
    Luu, Goldar

    May 19, 2021

    CS A250
    Project 2
*/

#ifndef COOKIELIST_H
#define COOKIELIST_H

#include "Cookie.h"
#include <list>

class CookieList
{
public:
	// Constructors
	CookieList();

	// Function addCookie
	void addCookie(const Cookie& aCookie);
	void addCookie(const std::string& newName, size_t newCalories,
		const std::set<std::string>& newIngredients, size_t newServings);

	// Accessor function
	size_t getCount() const;

	// Boolean functions
	bool isEmpty() const;

	// Print functions
	void printAllCookies() const;

	// Function clearList
	void clearList();

	// The Big Three
	CookieList(const CookieList& otherCookieList);
	CookieList& operator=(const CookieList& otherCookieList);
	~CookieList();

	// Part C function delcarations
	void printCookiesSelection() const;
	void printRecipe(std::size_t selection) const;
	void printCalories(size_t selection) const;
	void printLimitedCalories(size_t maxCalories) const;

	// Choice E
	void calorieBasedCookieCounter(const size_t selection, const double maxCalories) const;
	
private:
	std::list<Cookie>* cookieList;
};

#endif