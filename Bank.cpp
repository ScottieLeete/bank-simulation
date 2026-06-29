/*
 * Bank.cpp
 *
 *  Created on: Jun 28, 2026
 *      Author: scott
 */

#include "Bank.h"
#include <vector>
#include <string>
//#include "BankAccount.h"

Bank::Bank() {
	this->bankName = "My public bank";
}

Bank::Bank(std::string bn) {
	this->bankName = bn;
}

Bank::~Bank() {
	this->listOfAccs.clear();
	// i dont know if this is required but
	// cleaning up this here is probably good practice
}

std::string Bank::getName()
{
	return this->bankName;
}



