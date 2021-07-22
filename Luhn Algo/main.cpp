#include <iostream> 
#include <cmath> 
#include <string>

using namespace std; 


bool isValidCardNumber(const string& cc, int len); 

int main()
{
	cout << "Welcome to Luhn Algorithm, which verifies if a card number is valid or not. " << endl; 

	string cc; 
	bool exit = false; 

	cout << "Please type your credit card number: "; 
	cin >> cc;  
	while (!exit)
	{
		int len = cc.length(); 
		if (cc == "exit")
			break; 
		else if (!isValidCardNumber(cc, len))
		{
			cout << "Bad input, please try again. ";
			continue; 
		}
		int doubleEvenSum = 0; 

		for (int i = len - 2; i >= 0; i = i - 2) {
			int dbl = (cc[i] - 48) * 2; // 48 converts into num 
			if (dbl > 9) {
				dbl = (dbl / 10) + (dbl % 10); 
			}
			doubleEvenSum += dbl; 
		}

		for (int i = len - 1; i >= 0; i = i - 2) {
			doubleEvenSum += (cc[i] - 48);
		}

		cout << (doubleEvenSum % 10 == 0 ? "Valid!" : "Invalid!") << endl;
		break; 

	}
	return 0; 
}

bool isValidCardNumber(const string& cc, int len){
	for (int i = 0; i < len; i++) {
		if (cc[i] < '0' || cc[i] > '9')
			return false;
	}
	return true; 
}