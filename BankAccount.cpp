/*
 * BankAccount.cpp
 *
 *  Created on: Jun 28, 2026
 *      Author: scott
 */
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "BankAccount.h"

BankAccount::BankAccount()
// generic default constructor.
// do not use this in actual implementation
{
	this->id = 9999;
	this->username = "AnonymousUser";
	this->first = "John";
	this->last = "Doe";
	this->password = "password";
	this->checkingBal = 300;
	this->savingsBal = 500;
}

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

BankAccount::BankAccount(std::string data)
{
	/*
	 * Alternate constructor that takes in a data line and makes the account
	 * based on it being fed through a stringstream.
	 */
	std::stringstream ss(data);

	// Intermediate string buffers to hold raw text pieces
	// C++ threw a hissy fit when we tried to declare these types for what they were supposed to be
	std::string raw_id; // id is already a short variable name, so I came up with this
	std::string usnm, fn, ln, pswd;
	std::string cbal, sbal;

	// Most of the following code in this function is AI-generated, prominently the errors.
	// 1. Extract each piece using '|' as the delimiter
	if (std::getline(ss, raw_id, '|') &&
		std::getline(ss, usnm, '|') &&
		std::getline(ss, fn, '|') &&
		std::getline(ss, ln, '|') &&
		std::getline(ss, pswd, '|') &&
		std::getline(ss, cbal, '|') &&
		std::getline(ss, sbal)) // The last element doesn't have a trailing '|'
	{
		try {
			// 2. Instantiate your struct and convert types
			this->id = std::stoi(raw_id);     // Convert string to int
			this->username = usnm;
			this->first = fn;
			this->last = ln;
			this->password = pswd;
			this->checkingBal = std::stol(cbal);
			this->savingsBal = std::stol(sbal);

		}
		catch (const std::invalid_argument& e) {
			std::cerr << "Error: One of the numeric fields contains non-numeric characters.\n";
		}
		catch (const std::out_of_range& e) {
			std::cerr << "Error: Number is too large for int or long type.\n";
		}
	} else {
		std::cerr << "Error: Line format is invalid or missing columns.\n";
	}
}

bool BankAccount::checkPassword (std::string& attempt) const {
	/*
	 * Securely checks if password matches the attempt.
	 * Returns true if it does, false if it does not.
	 */
	return password == attempt;
}

std::string BankAccount::compactData() {
	/*
	 * Method to create a string that can be written back into a data file.
	 * Intended for use after the data inside a BankAccount instance has changed and
	 * it's time to put it back.
	 * Returns the compacted data string.
	 */
	return std::to_string(this->id) + "|" + this->username + "|"
			+ this->first + "|" + this->last + "|"
			+ this->password + "|" + std::to_string(this->checkingBal)
			+ "|" + std::to_string(this->savingsBal);
}

BankAccount::~BankAccount() {
	// TODO Auto-generated destructor stub
}

