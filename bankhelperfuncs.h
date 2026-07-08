/*
 * bank2.cpp
 *
 *  Created on: Jul 3, 2026
 *      Author: scott
 *
 *  Created to replace bank1.cpp, not be used in conjunction.
 */

#ifndef BANKHELPERFUNCS_H_
#define BANKHELPERFUNCS_H_
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "config.h"
#include "Bank.h"
#include "BankAccount.h"

bool testForCorrectUserAndPass(std::string filename, std::string u, std::string p);

bool testIfUserExists(std::string filename, std::string u);

int getNumLinesInData(std::string filename);

BankAccount createBankAccInstance(std::string rawdataline);}

BankAccount bankloop(std::string bankfilename);

BankAccount logIntoAccount (std::string bankfilename);

BankAccount createAccount (std::string bankfilename);

#endif /* BANKHELPERFUNCS_H_ */


