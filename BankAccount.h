/*
 * BankAccount.h
 *
 *  Created on: Jun 28, 2026
 *      Author: scott
 */

#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_
#include <string>

class BankAccount {
private:
	int id;
	std::string username;
	std::string first;
	std::string last;
	std::string password;
	long checkingBal;
	long savingsBal;
	// TODO Auto-generated constructor stub
public:
	BankAccount();
	BankAccount(int i, std::string un, std::string f, std::string l, std::string pswd, long checking, long savings);
	bool checkPassword(std::string attempt);
	virtual ~BankAccount();
};

#endif /* BANKACCOUNT_H_ */
