/*
 * Bank.cpp
 *
 *  Created on: Jun 28, 2026
 *      Author: scott
 */

#include "Bank.h"
#include "BankAccount.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

Bank::Bank() {
	this->bankName = "My public bank";
}

Bank::Bank(std::string bn) {
	this->bankName = bn;
}

void Bank::initialize() {
	this->listOfAccs;
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



