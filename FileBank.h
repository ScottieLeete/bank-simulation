/*
 * FileBank.h
 *
 *  Created on: Jul 8, 2026
 *      Author: scott
 */

#ifndef FILEBANK_H_
#define FILEBANK_H_
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "BankAccount.h"

#include "Bank.h"

class FileBank: public Bank {
protected:
	std::string dataFileName;
public:
	FileBank(std::string filename);
//	void initialize();
	virtual ~FileBank();
};

#endif /* FILEBANK_H_ */
