/*
    OMG it ran?
    Ho, Adam
    Luu, Goldar

    May 19, 2021

    CS A250
    Project 2
*/

#ifndef COOKIE_H
#define COOKIE_H

#include "CookieType.h"
#include <vector>
#include <set>
#include <iostream>

class Cookie : public CookieType
{
public:
    // Constructors
    Cookie();
    Cookie(const std::string& newName,
        std::size_t newCalories,
        const std::set<std::string>& newIngredients,
        std::size_t newServings);

    // Accessors
    std::size_t getServings() const;
    std::set<std::string> getIngredients() const;
    const Cookie& getCookie() const;

    // Mutators
    void setServings(std::size_t newServings);
    void setIngredients
    (const std::vector<std::string>& newIngredients);

    // Print Functions
    void printRecipe() const;
    void printIngredients() const;
    void printCalories() const;

    // Destructor 
    ~Cookie() {};

private:
    // Stores all the ingredients
    std::set<std::string> ingredients;
    // Stores number of servings
    std::size_t servings;

};


#endif