/*
    OMG it ran?
    Ho, Adam
    Luu, Goldar

    May 19, 2021

    CS A250
    Project 2
*/
#include "Cookie.h"

using namespace std;

// Constructors 
Cookie::Cookie()
{
    servings = 0;
}

Cookie::Cookie(const string& newName, size_t newCalories,
    const set<string>& newIngredients, size_t newServings)
    : CookieType(newName, newCalories)
{
    ingredients = newIngredients;
    servings = newServings;
}

// Accessors 
size_t Cookie::getServings() const
{
    return servings;
}

set<std::string> Cookie::getIngredients() const
{
    return ingredients;
}

const Cookie& Cookie::getCookie() const
{
    return *this;
}

// Mutators
void Cookie::setServings(size_t newServings)
{
    servings = newServings;
}

void Cookie::setIngredients(const vector<string>& newIngredients)
{
    ingredients.clear();
    ingredients.insert(newIngredients.begin(), newIngredients.end());
}

// Printers
void Cookie::printRecipe() const
{
    cout << "    Recipe for " << getCookieName() << endl <<
        "        " << "Servings: " << servings << endl;
    printIngredients();
}

void Cookie::printIngredients() const
{
    cout << "        Ingredients: ";
    auto lastElement = ingredients.crbegin();
    for (const string& element : ingredients)
    {
        cout << element;
        if (element != *lastElement)
            cout << ", ";
    }
    cout << endl;
}

void Cookie::printCalories() const
{
    cout << "        " << getCookieName() << " (calories: " 
    << getCalories() << ")" << endl;
}
