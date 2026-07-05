/*
 * BankAccount.cpp
 *
 *  Created on: Jun 28, 2026
 *      Author: scott
 */
#include <string>
#include <vector>
#include <sstream>
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

	std::string piece;

	// This first value is an integer and needs std::stoi (pretty simple)
	getline(ss, piece, '|');
	this->id = std::stoi(piece);

	// The next four values are strings and do not need conversion
	getline(ss, piece, '|');
	this->username = piece;
	getline(ss, piece, '|');
	this->first = piece;
	getline(ss, piece, '|');
	this->last = piece;
	getline(ss, piece, '|');
	this->password = piece;

	// The last two values are longs and need std::stol (still simple)
	getline(ss, piece, '|');
	this->checkingBal = std::stol(piece);
	getline(ss, piece, '|');
	this->savingsBal = std::stol(piece);

//	ss >> this->id >> this->username >> this->first >>
//		this->last >> this->password >> this->checkingBal >> this->savingsBal;

}

bool BankAccount::checkPassword(std::string attempt) {
	return password == attempt;
}

BankAccount::~BankAccount() {
	// TODO Auto-generated destructor stub
}

