/*
    OMG it ran?
    Ho, Adam
    Luu, Goldar

    May 26, 2021

    CS A250
    Project 2
*/

/*
  The name of the new selection is calorieBasedCookieCounter,
  it outputs the amount of cookies you're allowed to eat given
  a caloric limit. The expected output for 400 Calories of both
  Lemon Square Bars and Snickerdoodles is 2.9 and 3.3 respectively
  This assumes the user does not enter a negative amount of
  calories.
*/

#include "Interface.h" 
using namespace std;

void displayMenu()
{
    cout << string(62, '*') << '\n'
        << "                        Cookie Recipes" << '\n'
        << string(62, '*') << '\n'
        << '\n'

        << "Select one of the following: " << '\n'
        << '\n'
        << "    a. Print all recipes" << '\n'
        << "    b. Print cookie recipe" << '\n'
        << "    c. Print cookie calories" << '\n'
        << "    d. Print limited calories" << '\n'
        // May 25th 1:29 AM 
        // Changed "Exit" to "To exit"
        << "    e. Calculate amount of cookies able to be eaten with given calories" << "\n"
        << "    F. To Exit" << "\n\n";
}

void processChoice(CookieList& cookieList)
{
    bool exit = false;
    while (!exit)
    {
        size_t selection = 0;
        char choice = ' ';
        char menuAns = ' ';
        size_t maxDailyCalories = 0;
        size_t maxCalories = 0;
        cout << "Enter your Choice: ";
        cin >> menuAns;

        cout << '\n';
        switch (menuAns)
        {
        case 'a':
            if (cookieList.isEmpty())
            {
                // Corrected formatting issue May 25th 12:51 AM
                // Added two spaces in front of =>
                cerr << "  => There are no recipes in the list." << '\n'
                    << '\n'
                    << string(62, '=') << '\n'
                    << '\n'
                    << "Please contact your administrator. "
                    << "Good bye!" << '\n';
                return;
            }
            else
            {
                cookieList.printAllCookies();
                cout << '\n'
                    << string(62, '=') << '\n'
                    << '\n'
                    << "Would you like to continue (y/n)? ";
            }
            break;

        case 'b':
            cout << string(62, '-') << '\n'
                << "    COOKIE RECIPE" << '\n'
                << string(62, '-') << '\n'
                << '\n'
                << "Choose a cookie to view the recipe." << '\n'
                << '\n';
            cookieList.printCookiesSelection();
            cout << '\n'
                << "Your choice: ";
            cin >> selection;
            cout << '\n';
            cookieList.printRecipe(selection);
            cout << '\n'
                << string(62, '=') << '\n'
                << '\n'
                << "Would you like to continue (y/n)? ";
            break;

        case 'c':
            cout << string(62, '-') << '\n'
                << "    COOKIE RECIPE" << '\n'
                << string(62, '-') << '\n'
                << '\n'
                << "Choose a cookie # to view the number of calories."
                << '\n'
                << '\n';
            cookieList.printCookiesSelection();
            cout << '\n'
                << "Your choice: ";
            cin >> selection;
            cout << '\n';
            cookieList.printCalories(selection);
            cout << '\n'
                << string(62, '=') << '\n'
                << '\n'
                << "Would you like to continue (y/n)? ";
            break;

        case 'd':
            cout << string(62, '-') << '\n'
                << "    MAXIMUM CALORIES" << '\n'
                << string(62, '-') << '\n'
                << '\n'
                << "What is the maximum # of calories (100-200)? ";
            cin >> maxCalories;
            cout << '\n';
            cookieList.printLimitedCalories(maxCalories);
            cout << '\n'
                << string(62, '=') << '\n'
                << "\nWould you like to continue (y/n)? ";
            break;

        case 'e':
            cout << string(62, '-') << '\n'
                << "    HOW MANY COOKIES CAN I EAT " << '\n'
                << string(62, '-') << '\n'
                << "\nChoose a cookie" << '\n'
                << '\n';
            cookieList.printCookiesSelection();
            cout << '\n'
                << "Your choice: ";
            cin >> selection;
            cout << "What is the maximum # of calories that you "
                << "can eat today (Greater than 0)? ";
            cin >> maxDailyCalories;
            cout << '\n';
            cookieList.calorieBasedCookieCounter
            (selection, maxDailyCalories);
            cout << '\n'
                << string(62, '=') << '\n'
                << "\nWould you like to continue (y/n)? ";
            break;

        case 'f':
            exit = true;
            break;

        default:
            cout << "  => Sorry. That is not a selection."
                << '\n'
                << '\n'
                << string(62, '=') << '\n'
                << "\nWould you like to try again (y/n)? ";
            break;
        }
        if (!exit)
        {
            cin >> choice;
            // May 25th 12:59 AM
            // Added this line here, attempting to correct priting 
            // Extra line issue, looks like it fixed it
            cout << '\n';
            if (choice == 'y')
            {
                cout << '\n';
                displayMenu();
            }
            else
            {
                exit = true;
            }
        }
    }
    // May 25th 12:57 AM
    // Removed \n in front of Thank you... 
    cout << "Thank you for using our software. "
        << "Good bye!" << '\n';
}
