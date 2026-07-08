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

//	std::string piece;

//	This first value is an integer and needs std::stoi (pretty simple)
//	getline(ss, piece, '|');
//	this->id = std::stoi(piece);

//	The next four values are strings and do not need conversion
//	getline(ss, piece, '|');
//	this->username = piece;
//	getline(ss, piece, '|');
//	this->first = piece;
//	getline(ss, piece, '|');
//	this->last = piece;
//	getline(ss, piece, '|');
//	this->password = piece;
//
//	The last two values are longs and need std::stol (still simple)
//	getline(ss, piece, '|');
//	this->checkingBal = std::stol(piece);
//	getline(ss, piece, '|');
//	this->savingsBal = std::stol(piece);

	// Wrap the string in a stream so we can read from it sequentially

	// Intermediate string buffers to hold raw text pieces
	std::string raw_id; // id is already a short variable name, so I came up with this
	std::string usnm, fn, ln, pswd;
	std::string cbal, sbal;

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

			// 3. Output to verify the variables are correct
			std::cout << "ID: " << this->id << "\n"
					  << "Strings: " << this->username << ", " << this->first << ", " << this->last << ", " << this->password << "\n"
					  << "Long 1:  " << this->checkingBal << "\n"
					  << "Long 2:  " << this->savingsBal << "\n";
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

bool BankAccount::checkPassword(std::string attempt) {
	return password == attempt;
}

BankAccount::~BankAccount() {
	// TODO Auto-generated destructor stub
}

