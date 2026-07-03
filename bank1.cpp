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
	/*
	 * Look through the file to test if the username and password are right.
	 * If user does not exist, return false.
	 * If user exists but the password doesn't match, return false.
	 * If user and password are correctly provided, return true.
	 * For now, this has boilerplate implementation, only returning true if username and password are equal strings.
	 */
	return u == p;
}

bool testIfUserExists(std::string u) {
	/*
	 * Look through the file to test if the username
	 * already exists.
	 * Return true if it does, false if it does not.
	 */
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
