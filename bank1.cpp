#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "config.h"
#include "Bank.h"
#include "BankAccount.h"

int main(int argc, char **argv) {
	std::string myBankName = "Darth Vader's Bank";
//	Bank banksy = Bank();
//	banksy.bankName = myBankName;
	Bank banksy = Bank(myBankName);
	std::string response;
	std::cout << "Welcome to " << myBankName << std::endl;

	// Potential While-loop of user interaction begins here

	while (response != "login" && response != "create") {
		std::cout << "Would you like to log in (\"login\") to an account or create one now (\"create\")?" << std::endl;
		std::cin >> response;
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
