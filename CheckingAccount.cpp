#include "CheckingAccount.h"

#include <utility>

CheckingAccount::CheckingAccount() {
    name = "Unnamed Account";
    balance = 0.0;
    dollars = 0.0;
    euros = 0.0;
    tenges = 0.0;

    //07.10.2021
    tengeUsd = 0.0023;
    euroUsd = 1.16;
    fee = 0.015;
}

CheckingAccount::CheckingAccount(const std::string &name) : CheckingAccount() {
    this->name = name;
}

const std::string &CheckingAccount::getName() const {
    return name;
}

double CheckingAccount::getBalance() const {
    return balance;
}

double CheckingAccount::getDollars() const {
    return dollars;
}

double CheckingAccount::getEuros() const {
    return euros;
}

double CheckingAccount::getTenges() const {
    return tenges;
}

double CheckingAccount::getTengeUsd() const {
    return tengeUsd;
}

double CheckingAccount::getEuroUsd() const {
    return euroUsd;
}

void CheckingAccount::setBalance(double blnc) {
    CheckingAccount::balance = blnc;
}

void CheckingAccount::setDollars(double usd) {
    CheckingAccount::dollars = usd;
}

void CheckingAccount::setEuros(double eur) {
    CheckingAccount::euros = eur;
}

void CheckingAccount::setTenges(double kzt) {
    CheckingAccount::tenges = kzt;
}

void CheckingAccount::showBalance() const{
    std::cout << "===========================\n";
    std::cout << getName() << "\n";
    std::cout << "Your Balance: " << getBalance() << "$\n" << "Dollar Wallet: " << getDollars() << "$\n"
              << "Euro Wallet: " << getEuros() << "€\n" << "Tenge Wallet: " << getTenges() << "₸\n";
    std::cout << "===========================\n";
}

void CheckingAccount::updateBalance(){
    setBalance((getTenges() * getTengeUsd()) + (getEuros() * getEuroUsd()) + getDollars());
}

double CheckingAccount::getFee() const {
    return fee;
}

void CheckingAccount::withdraw(const std::string &currency, double amount) {
    Account::withdraw(currency, amount);
    if(currency == "dollar")
        setDollars(getDollars() - amount * getFee());
    else if(currency == "euro")
        setEuros(getEuros() - amount * getFee());
    else
        setTenges(getTenges() - amount * getFee());
    updateBalance();
}

void CheckingAccount::deposit(const std::string &currency, double amount) {
    Account::deposit(currency, amount);
}


