#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(){
    name = "Unnamed Account";
    balance = 0.0;
    dollars = 0.0;
    euros = 0.0;
    tenges = 0.0;
    interestRateKZT = 0.015;
    interestRateUSD = 0.005;
    interestRateEUR = 0.007;
}

SavingsAccount::SavingsAccount(const std::string &name) : SavingsAccount(){
    this->name = name;
}

const std::string &SavingsAccount::getName() const {
    return name;
}

double SavingsAccount::getBalance() const {
    return balance;
}

double SavingsAccount::getDollars() const {
    return dollars;
}

double SavingsAccount::getEuros() const {
    return euros;
}

double SavingsAccount::getTenges() const {
    return tenges;
}

void SavingsAccount::setBalance(double blnc) {
    SavingsAccount::balance = blnc;
}

void SavingsAccount::setDollars(double usd) {
    SavingsAccount::dollars = usd;
}

void SavingsAccount::setEuros(double eur) {
    SavingsAccount::euros = eur;
}

void SavingsAccount::setTenges(double kzt) {
    SavingsAccount::tenges = kzt;
}

double SavingsAccount::getInterestRateUsd() const {
    return interestRateUSD;
}

double SavingsAccount::getInterestRateEur() const {
    return interestRateEUR;
}

double SavingsAccount::getInterestRateKzt() const {
    return interestRateKZT;
}

void SavingsAccount::deposit(const std::string &currency, double amount) {
    Account::deposit(currency, amount);
    if(currency == "dollar")
        setDollars(getDollars() + amount * getInterestRateUsd());
    else if(currency == "euro")
        setEuros(getEuros() + amount * getInterestRateEur());
    else
        setTenges(getTenges() + amount * getInterestRateKzt());
    Account::updateBalance();
}

void SavingsAccount::withdraw(const std::string &currency, double amount) {
    Account::withdraw(currency, amount);
}

void SavingsAccount::showBalance() const {
    std::cout << "===========================\n";
    std::cout << getName() << "\n";
    std::cout << "Your Balance: " << getBalance() << "$\n" << "Dollar Wallet: " << getDollars() << "$\n"
              << "Euro Wallet: " << getEuros() << "€\n" << "Tenge Wallet: " << getTenges() << "₸\n";
    std::cout << "===========================\n";
}


