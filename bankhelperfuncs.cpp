/*
 * bank2.cpp
 *
 *  Created on: Jul 3, 2026
 *      Author: scott
 *
 *  Created to replace bank1.cpp, not be used in conjunction.
 */

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
	bool testForCorrectUserAndPass(std::string filename, std::string u, std::string p) {
		/*
		 * Look through the file to test if the username and password are right.
		 * If user does not exist, return false.
		 * If user exists but the password doesn't match, return false.
		 * If user and password are correctly provided, return true.
		 * For now, this has boilerplate implementation, only returning true if username and password are equal strings.
		 */
		std::ifstream file(filename);
		if (!file.is_open()) {
			std::cerr << "File error: \n" << std::endl;
			std::cerr << "The file likely does not exist or cannot be accessed." << std::endl;
			return false; // user cannot exist if the file also does not exist
		}
		return u == p;
	}

	bool testIfUserExists(std::string filename, std::string u) {
		/*
		 * Look through the file to test if the username
		 * already exists.
		 * Return true if it does, false if it does not.
		 */
		std::cerr << "Implementation error: \n" << std::endl;
		std::cerr << "This function is not implemented properly." << std::endl;
		return false;
	}

	int getNumLinesInData(std::string filename) {
		// This function's code is AI-generated.
		std::ifstream file(filename);

		// Check if the file opened successfully
		if (!file.is_open()) {
			std::cerr << "File error: \n" << std::endl;
			std::cerr << "The file likely does not exist or cannot be accessed." << std::endl;
			return -1;
		}

		std::string line;
		int line_count = 0;

		// Loop until the end of the file, incrementing for each line found
		while (std::getline(file, line)) {
			line_count++;

			// TODO remove code below (for security reason)
			std::cout << line << std::endl;
		}
		// Close the file stream
		file.close();

		std::cout << "Found " << line_count << " line(s)" << std::endl;
		return line_count;
	}

	BankAccount createBankAccInstance(std::string rawdataline) {
		/*
		 * Create a new instance of a BankAccount using
		 * a line of data, passed in as "rawdataline".
		 * Format is: id|username|first name|last name|password|checking balance|savings balance
		 * (yes, the pipes are necessary)
		 * Return that new instance.
		 */
		BankAccount temp = BankAccount(0, "un", "first", "last", "pswd", long(0), long(0));
		return temp;
	}

	BankAccount bankloop(std::string bankfilename) {
		std::string myBankName = "Darth Vader's Bank";
		std::cout << "Welcome to " << myBankName << std::endl;

		while (true) {
			std::string userCommand;
			std::cout << "Please choose action: (\'login\') to an account, (\'create\') account, or (\'leave\')" << std::endl;
			std::cin >> userCommand;
			if (userCommand == "leave" || userCommand == "exit" || userCommand == "quit" || userCommand == "stop") {
				return nullptr;
			}
			else if (userCommand == "login" || userCommand == "log in" || userCommand == "sign in" || userCommand == "log on") {
				BankAccount ba = logIntoAccount(bankfilename);
				// return function value of logIntoAccount after that function finishes
			}
			else if (userCommand == "create" || userCommand == "make" || userCommand == "new" || userCommand == "register") {
				BankAccount ba = createAccount(bankfilename);
				// return function value of createAccount after that fnction finishes
			}
			else {
				std::cout << "Unknown command: " << userCommand << std::endl;
			}
		}
	}

	BankAccount logIntoAccount (std::string bankfilename) {
		std::string username, password;
		std::cout << "Please provide the username: " << std::endl;
		std::cin >> username;
		std::cout << "Please provide the password: " << std::endl;
		std::cin >> password;
		if (not testForCorrectUserAndPass(bankfilename, username, password)) {
			std::cout << "Invalid username or password." << std::endl;
		}
		throw std::runtime_error("No implementation");
	}

	BankAccount createAccount (std::string bankfilename) {
		std::string username, password, firstname, lastname;
		std::cout << "Please come up with a username: " << std::endl;
		std::cin >> username;
		if (username == "cancel") {
			throw std::runtime_error("Cancelled out of account creation.");
		}
		if (testIfUserExists(username)) {
			std::cout << "An account with this username already exists, please try again." << std::endl;
			std::cout << "Alternatively, type 'cancel' at the username prompt to cancel account creation." << std::endl;
			continue;
		}
		std::cout << "Please come up with a secure password: " << std::endl;
		std::cin >> password;
		std::cout << "Please type your first name: " << std::endl;
		std::cin >> firstname;
		std::cout << "Please type your first name: " << std::endl;
		std::cin >> lastname;
		if (firstname.empty() or lastname.empty() or username.empty() or password.empty()) {
			std::cout << "At least one parameter is empty. Please try again." << std::endl;
			continue;
		}
		std::string newAccId = std::to_string(getNumLinesInData("./data/dv.bank"));

		std::string primaryData = newAccId + "|" +
				username + "|" + firstname + "|" +
				lastname + "|" + password + "|" +
				"0|0";
	}
}
