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
	BankAccount(std::string data);
	bool checkPassword( std::string& attempt) const;
	virtual ~BankAccount();

	// It's bad practice to implement in header files...
	// But most of these are generic getters and setters from eclipse
	long getCheckingBal() const {
		return checkingBal;
	}

	void setCheckingBal(long checkingBal) {
		this->checkingBal = checkingBal;
	}
	long changeCheckingBal(long change) {
		this->checkingBal = this->checkingBal + change;
		return this->checkingBal;
	}

	std::string getFirst() const {
		return first;
	}

	void setFirst(std::string first) {
		this->first = first;
	}

	int getId() const {
		return id;
	}

	std::string getLast() const {
		return last;
	}

	void setLast(std::string last) {
		this->last = last;
	}

	std::string getPassword() const {
		return password;
	}

	void setPassword(std::string password) {
		this->password = password;
	}

	long getSavingsBal() const {
		return savingsBal;
	}

	void setSavingsBal(long savingsBal) {
		this->savingsBal = savingsBal;
	}
	long changeSavingsBal(long change) {
		this->savingsBal = this->savingsBal + change;
		return this->savingsBal;
	}

	std::string getUsername() const {
		return username;
	}

	void setUsername(std::string username) {
		this->username = username;
	}
	std::string compactData();

};

#endif /* BANKACCOUNT_H_ */
