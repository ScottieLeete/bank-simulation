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
#include <typeinfo>
#include "config.h"
#include "FileBank.h"
#include "Bank.h"
#include "bank1.h"
#include "BankAccount.h"

//namespace bhf {
//	#include "bankhelperfuncs.h"
//}

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
	while (true) {
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
			auto ba = accCreationAttempt(b);
			if (ba.has_value()) {
				// Again, to insure we don't come back empty handed, or be ready for it
				return ba;
			}
		} else if (response == "exit") {
			// Here we come back empty handed because we're leaving
			return std::nullopt;
		}
		response = "";
	}
	return std::nullopt;
}



std::optional<BankAccount> loginAttempt(Bank &b) {
	/*
	 * Try to log into an account.
	 * If you succeed, return that account.
	 * If you fail, return nullopt. (to signal you cancelled the action)
	 */
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
	auto ba = b.attemptLogin(un, pw);
	if (ba.has_value()) {
		std::cout << "Welcome, " << ba.value().getFirst() << " " << ba.value().getLast() << "!" << std::endl;
		return ba;
	} else {
		std::cout << "Invalid credentials" << std::endl;
	}
	return std::nullopt;
}

std::optional<BankAccount> accCreationAttempt(Bank &b) {
	/*
	 * Try to create a new BankAccount.
	 * If you succeed, return that account, and probably write its existence
	 * into the corresponding Bank.
	 * If you fail, return nullopt. (to signal you cancelled the action)
	 */
	std::string un, fn, ln, pw;
	std::cout << "Please come up with a username or type (\"exit\") to leave: " << std::endl;
	std::cin >> un;
	if (un == "exit") {
		return std::nullopt;
	}

	std::cout << "Please enter your first name: " << std::endl;
	std::cin >> fn;
	std::cout << "Please enter your last name: " << std::endl;
	std::cin >> ln;
	std::cout << "Please come up with a password: " << std::endl;
	std::cin >> pw;
	std::cout << "Thanks for telling us your password dork " << std::endl;
	if (b.usernameExists(un)) {
		std::cout << "This username is already taken." << std::endl;
		return std::nullopt;
	} // technically, our implementation checks username twice, but that is probably not a bad thing
	std::cout << "Preparing account creation" << std::endl;
	int s = b.numAccounts() + 1; // to be ahead of the previous accounts
	std::cout << "Registering new user #" << s << std::endl;
	BankAccount ba = BankAccount(s, un, fn, ln, pw, 0, 0); // by default, everyone is broke
	b.storeNewEntry(ba);

	return ba;
}

void performAccountActions(BankAccount &ba) { // we want to modify the actual value passed
	/*
	 * Perform actions such as adding and removing money to the checking and savings
	 * balances that are associated with one BankAccount instance.
	 * Then, we will write the new BankAccount data back (somehow, either
	 * inside or outside of this function), with hopefully no need
	 * to return anything else.
	 */
	std::cout << "Now performing account actions" << std::endl;
	return;
}

long getAmountToChange(std::string prompt) {
	/*
	 * Ask the user for a numeric value, with the given prompt.
	 * Rejects a negative value and returns 0 in that case.
	 * Otherwise, returns the amount the user enters as a 'long' variable.
	 */
	long answer;
	std::cout << prompt << std::endl;
	if (std::cin >> answer && answer >= 0) {
		/*
		 * Lazy evaluation strikes back - if the first condition fails
		 * the second condition is not checked. Also, the first condition
		 * IS a valid way to check if your answer was allowed by the 'long' type
		 */
		return answer;
	} else {
		std::cout << "That input is not allowed" << std::endl;
		return 0;
		// probably not good practice of us to return 0 after only 1 failure, but
		// it's not killing anybody
	}
}

void performAccountActions(Bank &b, BankAccount &ba) {
	/*
	 * We already have this function up above, just
	 * without the Bank &b parameter.
	 * Neither this nor that are implemented yet.
	 *
	 * IMPORTANT: By the time we finish, we should probably
	 * update the account data before we are fully out of this function.
	 */
	std::string response;
	while (true) {
		std::cout << "Would you like to (\"deposit\") or (\"withdraw\") money? (or \"logout\"): " << std::endl;
		std::cin >> response;
		if (response == "logout" || response == "exit") {
			// this was "return" until we realized
			// we should just skip to after-loop code instead of getting out entirely
			break;
		}
		else if (response == "deposit") {
			std::cout << "Would you like to deposit to (\"checking\") or (\"savings\")?" << std::endl;
			std::cin >> response;
			if (response == "checking" || response == "savings") {
				long howmuch;
				howmuch = getAmountToChange("How much would you like to deposit?");
				if (howmuch > 0) {
					std::cout << "Adding " << howmuch << " to your " <<
							response << " balance" << std::endl;
					if (response == "checking") {
						ba.changeCheckingBal(howmuch);
					}
					if (response == "savings") {
						ba.changeSavingsBal(howmuch);
					}
				}
			}
			else if (response == "exit" || response == "cancel") {
				continue;
			}
			else {
				std::cout << "That is not a valid location" << std::endl;
			}
		}
		else if (response == "withdraw") {
			std::cout << "Too bad, withdrawal is disabled" << std::endl;
		}
		else {
			std::cout << "Invalid command, please try again" << std::endl;
		}
	}
	// TODO: Save to file
	return;
}

Bank getBank() {
	/*
	 * Now all we need is just one bank. Oh look, there's one!
	 * (Instances and returns a manually-set bank)
	 */
	std::string name = "Darth Vader's Bank";
	std::string dataFile = "./data/dv.bank";
	FileBank fb = FileBank(name, dataFile);
	fb.initialize();
	return fb;
}

FileBank& getGlobalFileBank() {
	/*
	 * Because FileBank is used throughout Main, it's probably fair
	 * to give it the honor of being 'static' (it will stick around
	 * so long as the program is running, by virtue of us not
	 * needing any other banks)
	 */
	std::string name = "Darth Vader's Empirical Bank";
	std::string dataFile = "./data/dv.bank";
	static FileBank fb(name, dataFile);
	fb.initialize();
	return fb;
	// We will have to stop using this when we involve multiple banks...
	// But today is not that day
}

void useBank(Bank &b) {
	/*
	 * The overall loop of using a bank, that will go into other functions to change
	 * phases of usage. (Lobby, Login/Creation, Usage; and finally exiting which ends the loop)
	 */
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
	/*
	 * Probably will not be used, but this method was created
	 * with the intention of saving data that belongs to a bank
	 * by passing in that bank. No return is needed.
	 */
	return;
}

int main(int argc, char **argv) {
	/*
	 * The main method. It comes last in implementation.
	 */
//	Bank b = getBank(); // we should write this in bankhelperfuncs
	Bank& b = getGlobalFileBank(); // bankhelperfuncs is gone. this is bank1.cpp
	std::cout << "Our bank is of type " << typeid(b).name() << std::endl;
	useBank(b); // we're fine writing this here
	// this will have the WHOLE loop inside of it

	saveBank(b); // realistically, after account creation/login, we are just changing
	// one account each time. but still we should write this in bankhelperfuncs

	// continue this loop until it's time to leave
}
