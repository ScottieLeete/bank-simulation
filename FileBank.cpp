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

FileBank::FileBank(std::string& bn, std::string& dfn) : Bank(bn) {
	/*
	 * Unlike a regular Bank, there will only exist a two-parameter
	 * constructor for this class because filename is basically
	 * mandatory for this class to do anything useful.
	 * Bank Name comes first because it was part of the original
	 * class, file name comes second.
	 */
	this->dataFileName = dfn;
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
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        // 2. Attempt to open the file inside the try block
        file.open(this->dataFileName);

        // Read file contents here...

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

