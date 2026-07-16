/*
 * bank1.h
 *
 *  Created on: Jul 14, 2026
 *      Author: scott
 */

#include <string>
#include <vector>
#include <optional>
#include "config.h"
#include "Bank.h"
#include "BankAccount.h"

#ifndef BANK1_H_
#define BANK1_H_

Bank getBank();
void useBank(Bank &b);
std::optional<BankAccount> getAccount(Bank &b);
void performAccountActions(BankAccount &ba);

void performAccountActions(Bank &b, BankAccount &ba);
std::optional<BankAccount> loginAttempt(Bank &b);
std::optional<BankAccount> accCreationAttempt(Bank &b);

#endif /* BANK1_H_ */
