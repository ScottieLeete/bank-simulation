/*
 * Bank.h
 *
 *  Created on: Jun 28, 2026
 *      Author: scott
 */

#ifndef BANK_H_
#define BANK_H_
#include <string>
#include <vector>
#include <optional>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "BankAccount.h"

class Bank {
protected:
	std::string bankName;
	std::vector<BankAccount> listOfAccs;
public:
	Bank();
	Bank(std::string bn);
	void initialize();
	~Bank();
	bool usernameExists(std::string un);
	std::string getName();
	std::optional<BankAccount> attemptLogin(std::string un, std::string pw);
};



#endif /* BANK_H_ */
