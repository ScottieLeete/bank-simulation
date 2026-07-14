/*
 * bank1.cpp
 *
 *  Created on: Jul 12, 2026
 *      Author: scott
 *  Created to replace the previous bank1.cpp (now stored as "oldmain.cpp")
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <optional>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "config.h"
#include "FileBank.h"
#include "Bank.h"
#include "BankAccount.h"

namespace bhf {
	#include "bankhelperfuncs.h"
}

std::optional<BankAccount> getAccount(Bank &b) {
	/*
	 * Either login or create an account here, then
	 * return what account was just accessed by whichever action taken.
	 * If we want to exit instead, this function returns nothing
	 * for the purpose of useBank to know when we're done.
	 * If we return a BankAccount, we instead will use that
	 * BankAccount instance for our simulation.
	 */
	std::string response;
	std::vector<std::string> keywords = { // valid responses
//			"login", "log in", "log on", "sign in",
//			"create", "make", "register", "sign up",
//			"exit", "leave", "quit", "stop",
			"login", "create", "exit" // only these three are active just to keep it simple
	};
	while (std::find(keywords.begin(), keywords.end(), response) == keywords.end()) {
		std::cout << "Would you like to (\"login\") to an account or (\"create\") one now?" << std::endl;
		std::cin >> response;
	}
	if (response == "login") {
		auto ba = loginAttempt(b);
		if (ba.has_value()) {
			// Use the same anti-null trick as we did accessing this method
			return ba;
		}
	} else if (response == "create") {
		if (auto ba = accCreationAttempt(b)) {
			// Again, to insure we don't come back empty handed, or be ready for it
			return ba;
		}
	} else if (response == "exit") {
		// Here we come back empty handed because we're leaving
		return std::nullopt;
	}
	return std::nullopt;
}

void performAccountActions(BankAccount &ba) { // we want to modify the actual value passed
	std::cout << "Now performing account actions" << std::endl;
	return;
}

std::optional<BankAccount> loginAttempt(Bank &b) {
	std::string un, pw;
	std::cout << "Please enter username or type (\"exit\") to leave: " << std::endl;
	std::cin >> un;
	if (un == "exit") {
		return std::nullopt;
	}
	// password legally can be "exit"
	// but we won't tell the user if the username didn't exist
	std::cout << "Please enter password: " << std::endl;
	std::cin >> pw;
	return std::nullopt;

}

std::optional<BankAccount> accCreationAttempt(Bank &b) {
	std::string un, fn, ln, pw;
	std::cout << "Please come up with a username or type (\"exit\") to leave: " << std::endl;
	std::cin >> un;
	if (un == "exit") {
		return std::nullopt;
	}
	return std::nullopt;
}

void performAccountFunctions(Bank &b, BankAccount &ba) {
	return;
}

Bank getBank() {
	std::string name = "Darth Vader's Bank";
	std::string dataFile = "./data/dv.bank";
	FileBank fb = FileBank(name, dataFile);
	return fb;
}

void useBank(Bank &b) {
	std::string response;
//	BankAccount* ba = getAccount(); // write this in BHF; try login, create,
	// but if we get exit anywhere here, the loop is over
	// also this has to be a pointer for the sake of testing if it's null
	std::optional<BankAccount> baOpt;

	while (baOpt = getAccount(b)) { // assignment operand (=) returns value that was assigned. we have anti-null insurance here
		if (baOpt.has_value()) {
			BankAccount ba = baOpt.value();
			performAccountActions(b, ba); // dont account for "exit" response until we leave this loop
		}
	}
	// test if BankAccount ba is null, if not, then go to this loop.
	// else, try again until we get a proper BankAccount ba that isn't null
}

void saveBank(Bank &b) {
	return;
}

int main(int argc, char **argv) {
	FileBank b = getBank(); // we should write this in bankhelperfuncs

	useBank(b); // we're fine writing this here
	// this will have the WHOLE loop inside of it

	saveBank(b); // realistically, after account creation/login, we are just changing
	// one account each time. but still we should write this in bankhelperfuncs

	// continue this loop until it's time to leave
}
