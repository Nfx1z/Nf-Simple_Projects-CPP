/*
                                THIS CODE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
                                BY : VKEY
*/

// =========================================== PURPOSE OF THIS PROGRAM =================================================
/*
input : 100201 => reverse : 102001 ( Not palindrome )
input : 2606062 => reverse : 2606062 ( Palindrome )
*/

// ================================================ C++ LIBRARY ========================================================
#include <iostream> 	// std::cout, std::cin, std::endl
#include <string> 		// std::string
#include <algorithm> 	// std::reverse

// =========================================== CONSTRUCTORS FUNCTIONS ==================================================
void option(std::string &);
void palindromeInt(int &);
void palindromeStr(std::string &);

// =============================================== MAIN PROGRAM ========================================================
int main(){
	// variables
	std::string options;
	// clear the terminal
	system("cls");
	std::cout << "PALINDROME OR NOT PROGRAM" << std::endl;
	// type of the input
	std::cout << "Options (int/string) : "; std::cin >> options;
	option(options);
	return 0;
}

// ================================================= FUNCTIONS =========================================================

// to know what is the type of the user input
void option(std::string &word){
	if( word == "int"){
		int number;
		std::cout << "Input number : "; std::cin >> number;
		palindromeInt(number);
	}else if( word == "string"){
		std::string word;
		std::cout << "Input string : "; std::cin >> word;
		palindromeStr(word);
	}else
		std::cout << "UNKNOWN !!" << std::endl;
}

// for integer
void palindromeInt(int &number){
	int output = 0, temp = number;
	while(temp != 0){
		output = (output*10) + (temp % 10);
		temp = temp / 10;
	}

	if(number == output)
		std::cout << number << " is a palindrome " << std::endl;
	else
		std::cout << number << " is not a palindrome " << std::endl;
}

// for string
void palindromeStr(std::string &str){
	std::string outputStr = str;
	std::reverse(outputStr.begin(), outputStr.end() );

	if(outputStr == str)
		std::cout << "'" << str << "' is a palindrome " << std::endl;
	else
		std::cout << "'" << str << "' is not a palindrome " << std::endl;
}