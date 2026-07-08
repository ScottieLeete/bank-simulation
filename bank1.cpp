#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "config.h"
#include "Bank.h"
#include "BankAccount.h"

namespace bhf {
	#include "bankhelperfuncs.h"
}

/*
 * The main file of this project, has the main(___) function.
 */

int main(int argc, char **argv) {
	std::string myBankName = "Darth Vader's Bank";
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
	while (response == "create") {
			std::cout << "Please come up with a username: " << std::endl;
			std::cin >> response;
			if (response == "cancel") {
				break;
			}
			if (testIfUserExists(response)) {
				std::cout << "An account with this username already exists, please try again." << std::endl;
				std::cout << "Alternatively, type 'cancel' at the username prompt to cancel account creation." << std::endl;
				continue;
			}
			std::cout << "Please come up with a secure password: " << std::endl;
			std::cin >> other_response;
			std::string firstName;
			std::cout << "Please type your first name: " << std::endl;
			std::cin >> firstName;
			std::string lastName;
			std::cout << "Please type your first name: " << std::endl;
			std::cin >> lastName;
			if (firstName.empty() or lastName.empty() or other_response.empty() or response.empty()) {
				std::cout << "At least one parameter is empty. Please try again." << std::endl;
				continue;
			}
			std::string newAccId = std::to_string(getNumLinesInData("./data/dv.bank"));

			std::string primaryData = newAccId + "|" +
					response + "|" + firstName + "|" +
					lastName + "|" + other_response + "|" +
					"0|0";
		}
//		further code goes here, past here you should be in an account until you log out

/*
 * LAST TIME: We pushed this to github. And also got
 * started on data holding and processing. w3schools
 * and AI are kind of carrying us right now.
 *
 * THIS TIME: [continue to] Figure out how to read in a
 * Bank from a file.
 * Use the terminal to verify that this is working,
 * because eclipse doesn't do so well.
 *
 * FUTURE: Extend scope to more banks with more datasets.
 *
 * And put a cancel option at the first step
 */

	return 0;
}
