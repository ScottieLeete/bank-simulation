/*
 * Bank.cpp
 *
 *  Created on: Jun 28, 2026
 *      Author: scott
 */

#include "Bank.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
//#include "BankAccount.h"

Bank::Bank() {
	this->bankName = "My public bank";
}

Bank::Bank(std::string bn) {
	this->bankName = bn;
}

void Bank::initialize(std::string filename) {
	// This code is AI-generated.
    std::ifstream file;

    // 1. Tell the stream to throw exceptions when a failure occurs
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        // 2. Attempt to open the file inside the try block
        file.open("non_existent_file.txt");

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

Bank::~Bank() {
	this->listOfAccs.clear();
	// i dont know if this is required but
	// cleaning up this here is probably good practice
}

std::string Bank::getName()
{
	return this->bankName;
}



