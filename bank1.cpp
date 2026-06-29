#include <iostream>
#include <string>
#include <vector>
#include "config.h"
#include "Bank.h"
#include "BankAccount.h"

int main(int argc, char **argv) {
	std::string myBankName = "Darth Vader's Bank";
//	Bank banksy = Bank();
//	banksy.bankName = myBankName;
	Bank banksy = Bank(myBankName);
	std::cout << "Welcome to " << myBankName;


/*
 * LAST TIME: We got error-free building after
 * putting {}'s after the constructor declarations
 * in Bank.h. But, running did not give anything
 * to print or see as a variable.
 *
 * THIS TIME: Figure out how to read in a
 * Bank from a file. And possibly get
 * the print working so we know that our
 * code is working.
 */

	return 0;
}
