#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "config.h"
#include "Bank.h"
#include "BankAccount.h"

bool testForCorrectUserAndPass(std::string u, std::string p) {
	return u == p;
}


int main(int argc, char **argv) {
	std::string myBankName = "Darth Vader's Bank";
//	Bank banksy = Bank();
//	banksy.bankName = myBankName;
	Bank banksy = Bank(myBankName);
	std::string response;
	std::string other_response;
	std::cout << "Welcome to " << myBankName << std::endl;

	// Potential While-loop of user interaction begins here

	while (response != "login" && response != "create") {
		std::cout << "Would you like to log in (\"login\") to an account or create one now (\"create\")?" << std::endl;
		std::cin >> response;
	}
	while (response == "login") {
		std::cout << "Please provide the username: " << std::endl;
		std::cin >> response;
		std::cout << "Please provide the password: " << std::endl;
		std::cin >> other_response;
		if (not testForCorrectUserAndPass(response, other_response)) {
			std::cout << "Invalid username or password." << std::endl;
		}

	}
//		further code goes here

/*
 * LAST TIME: We pushed this to github. And also got
 * started on data holding and processing. w3schools
 * and AI are kind of carrying us right now.
 *
 * THIS TIME: [continue to] Figure out how to read in a
 * Bank from a file.
 * Use the terminal to verify that this is working,
 * because eclipse doesn't do so well.
 */

	return 0;
}
