/*
 * FileBank.cpp
 *
 *  Created on: Jul 8, 2026
 *      Author: scott
 */

#include "FileBank.h"
#include "Bank.h"
#include "BankAccount.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

FileBank::FileBank(std::string bankName, std::string dataFileName) : Bank(bankName) {
	/*
	 * Unlike a regular Bank, there will only exist a two-parameter
	 * constructor for this class because filename is basically
	 * mandatory for this class to do anything useful.
	 * Bank Name comes first because it was part of the original
	 * class, file name comes second.
	 */
	this->dataFileName = dataFileName;
}

void FileBank::initialize() {
	/*
	 * In the original Bank, all this function did was initialize the
	 * vector. Here, now the dataFileName variable gets involved after
	 * first calling the superclass initialize() method, for the purpose
	 * of reading in data.
	 */
	Bank::initialize();
	// This code is AI-generated.
    std::ifstream file;

    // 1. Tell the stream to throw exceptions when a failure occurs
//    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        // 2. Attempt to open the file inside the try block
        file.open(this->dataFileName);
        if (!file.is_open()) {
        	std::cerr << "Failure to read file: " << this->dataFileName << std::endl;
        }
        // Read file contents here...
        std::string line;
        while (std::getline(file, line)) {
            BankAccount ba = BankAccount(line);
            this->listOfAccs.push_back(ba);
        }

        file.close();
    }
    // 3. Catch the specific iostream failure
    catch (const std::ios_base::failure& e) {
        std::cerr << "File Error: " << e.what() << "\n";
        std::cerr << "The file likely does not exist or cannot be accessed.\n";
    }
    // 4. Catch-all for any other unforeseen standard exceptions
    catch (const std::exception& e) {
        std::cerr << "General Error: " << e.what() << "\n";
    }
    // End of AI-generated code.

}

FileBank::~FileBank() {
	this->listOfAccs.clear();
}

void FileBank::storeNewEntry(const BankAccount& ba) {
	/*
	 * Write a brand new entry to the data file associated with this FileBank.
	 * Uses a BankAccount parameter, and uses that BankAccount's compactData() function.
	 * Returns nothing, but can throw exceptions.
	 */
	std::cout << "Saving new account: " << ba.getUsername() << std::endl;
	if (usernameExists(ba.getUsername())) {
		throw std::invalid_argument("Bank Account with this username exists already");
	}

//  file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        std::ofstream file(this->dataFileName, std::ios::app);

        if (!file.is_open()) {
        	throw std::invalid_argument("Failure to read file: " + this->dataFileName);
        }

    	std::cout << "File accessed: " << this->dataFileName << std::endl;

        std::string entry = ba.compactData();

        std::cout << "Storing entry: " << entry << std::endl;
        // Read file contents here...
        file << entry << std::endl;

        file.close();
        listOfAccs.push_back(ba);
    }
    // 3. Catch the specific iostream failure
    catch (const std::ios_base::failure& e) {
        std::cerr << "File Error: " << e.what() << "\n";
        std::cerr << "The file likely does not exist or cannot be accessed.\n";
    }
    // 4. Catch-all for any other unforeseen standard exceptions
    catch (const std::exception& e) {
        std::cerr << "General Error: " << e.what() << "\n";
    }
}
