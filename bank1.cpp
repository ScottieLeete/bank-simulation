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
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "config.h"
#include "Bank.h"
#include "BankAccount.h"

namespace bhf {
	#include "bankhelperfuncs.h"
}

int main(int argc, char **argv) {
	FileBank b = getBank(); // we should write this in bankhelperfuncs

	useBank(b); // we're fine writing this here
	// this will have the WHOLE loop inside of it

	saveBank(b); // realistically, after account creation/login, we are just changing
	// one account each time. but still we should write this in bankhelperfuncs

	// continue this loop until it's time to leave
}

void useBank(Bank b) {
	std::string response;
	BankAccount* ba = getAccount(); // write this in BHF; try login, create,
	// but if we get exit anywhere here, the loop is over
	// also this has to be a pointer for the sake of testing if it's null

	while (ba = getAccount()) { // assignment operand (=) returns value that was assigned. we have anti-null insurance here
		performAccountActions(ba); // dont account for exit until we leave this loop

	}
	// test if BankAccount ba is null, if not, then go to this loop.
	// else, try again until we get a proper BankAccount ba that isn't null
}


