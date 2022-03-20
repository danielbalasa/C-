//
// This function will validate a number using Luhn Algorithm
//	
// The Luhn algorithm or Luhn formula, also known as the "modulus 10" or "mod 10" algorithm, named after its creator, IBM scientist Hans Peter Luhn
// This algorithm is used in credit card number validators and not only
// 
// The number is passed as text string to the function
// The function has a validation and verification portion where the text passed is cleaned up. All the non-digit characters are removed as well as all the zeroes at the begining of the number
// 
// The function will return 0 if the Luhn Sum is 0 and will return 1 otherwise
// 
// by Daniel Balasa
// (C) 2021

#include <iostream>


int ValidateLuhnNumber(std::string text) {

	// the digits allowed in a numeric value
	const std::string DIGITS{ "0123456789" };

	// this code portion will erase all characters leaving only the digits in the string passed to the function if any
	for (int i = text.size() - 1; i > -1; i--) {
		if (DIGITS.find(text[i]) == DIGITS.npos) {
			text.erase(i, 1);
		}
	}

	// this code line will remove all the zeroes at the begining of the number if any
	text.erase(0, std::min(text.find_first_not_of('0'), text.size() - 1));			

	int sum{ 0 };	// this variable will hold the Luhn sum
	int temp{ 0 };	
	for (int i = 0; i < text.size(); i++) {
		temp = (DIGITS.find(text[i])) * (2 - (i % 2));
		sum = sum + ((temp < 10) ? (temp) : (1 + temp % 10));
		}
	return ((sum%10==0)?0:1);	// if the last digit of the sum is 0 return 0 otherwise return 1

}


int main(int argc, const char* argv[]) {	// argc (arguments count) argv (arguments vector)
	
	std::string TEST{ "5167950201302837" };
	
	std::cout << ValidateLuhnNumber(TEST) << std::endl;

	system("pause");
	return 0;	
}
