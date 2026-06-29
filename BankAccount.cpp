/*
 * BankAccount.cpp
 *
 *  Created on: Jun 28, 2026
 *      Author: scott
 */
#include <string>
#include "BankAccount.h"

BankAccount::BankAccount(int i, std::string un, std::string f, std::string l, std::string pswd, long checking, long savings)
{
	this->id = i;
	this->username = un;
	this->first = f;
	this->last = l;
	this->password = pswd;
	this->checkingBal = checking;
	this->savingsBal = savings;
}
bool BankAccount::checkPassword(std::string attempt) {
	return password == attempt;
}

BankAccount::~BankAccount() {
	// TODO Auto-generated destructor stub
}

