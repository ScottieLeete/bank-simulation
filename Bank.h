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

	std::string getName();
};



#endif /* BANK_H_ */
