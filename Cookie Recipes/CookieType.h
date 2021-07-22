/*
    OMG it ran?
    Ho, Adam
    Luu, Goldar

    May 19, 2021

    CS A250
    Project 2
*/

#ifndef COOKIETYPE_H
#define COOKIETYPE_H

#include <string> 
class CookieType
{
public: 
	CookieType() : calories(0) {}; 
	CookieType(const std::string& newCookieName, size_t calories); 

	std::string getCookieName() const;
	size_t getCalories() const; 

	void setCookieName(const std::string& newCookieName); 
	void setCalories(size_t calories); 

	~CookieType() {}; 
	
private: 
	std::string cookieName; 
	size_t calories; 
};


#endif


