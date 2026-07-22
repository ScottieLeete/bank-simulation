/*
 * Bank.cpp
 *
 *  Created on: Jun 28, 2026
 *      Author: scott
 */

#include "Bank.h"
#include "BankAccount.h"
#include <vector>
#include <optional>
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

bool Bank::usernameExists(std::string username) {
	/*
	 * Check if the specified username exists in any account stored in the bank.
	 * Return true if it does, false if it does not.
	 */
    for (const BankAccount& acc : this->listOfAccs) {
        if (acc.getUsername() == username) {
            return true;
        }
    }
    return false;
}

std::optional<BankAccount> Bank::attemptLogin(std::string un, std::string pw) {
	//TODO delete all printing lines
	for (const BankAccount& acc : this->listOfAccs) {
	        if (acc.getUsername() == un) {
	            if (acc.checkPassword(pw)) {
	            	return acc;
	            } else {
	            	return std::nullopt;
	            	// No harm in saving processing after
	            	// the ONE account we are looking for gives us
	            	// notice that the password was wrong.
	            }
	        }
	    }
	return std::nullopt;
}

int Bank::numAccounts() const {
	return this->listOfAccs.size();
}

void Bank::storeNewEntry(const BankAccount& ba) {
	/*
	 * Add a BankAccount to listOfAccs internally.
	 * Because this is not FileBank [we wrote it there first], we're not checking a file.
	 * Thankfully, in FileBank, this method gets overridden and improved upon.
	 * We still check for a matching username though.
	 */
	if(this->usernameExists(ba.getUsername())) {
		std::cerr << "A bank account with this user already exists here." << std::endl;;
	}
	this->listOfAccs.push_back(ba);
}
