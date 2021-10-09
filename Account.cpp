#include <string>
#include "Account.h"

Account::Account() {
    name = "Unnamed Account";
    balance = 0.0;
    dollars = 0.0;
    euros = 0.0;
    tenges = 0.0;

    //07.10.2021
    tengeUsd = 0.0023;
    euroUsd = 1.16;
}

Account::Account(const std::string &name) : Account() {
    this->name = name;
}

const std::string &Account::getName() const {
    return name;
}

double Account::getDollars() const {
    return dollars;
}

double Account::getEuros() const {
    return euros;
}

double Account::getTenges() const {
    return tenges;
}

double Account::getBalance() const {
    return balance;
}

double Account::getTengeUsd() const {
    return tengeUsd;
}

double Account::getEuroUsd() const {
    return euroUsd;
}

void Account::setBalance(double blnc) {
    Account::balance = blnc;
}

void Account::setDollars(double usd) {
    Account::dollars = usd;
}

void Account::setEuros(double eur) {
    Account::euros = eur;
}

void Account::setTenges(double kzt) {
    Account::tenges = kzt;
}

void Account::showBalance() const{
    std::cout << "===========================\n";
    std::cout << getName() << "\n";
    std::cout << "Your Balance: " << getBalance() << "$\n" << "Dollar Wallet: " << getDollars() << "$\n"
    << "Euro Wallet: " << getEuros() << "€\n" << "Tenge Wallet: " << getTenges() << "₸\n";
    std::cout << "===========================\n";
}

void Account::updateBalance(){
    setBalance((getTenges() * getTengeUsd()) + (getEuros() * getEuroUsd()) + getDollars());
}

void Account::deposit(const std::string& currency, double amount) {
    if(currency == "dollar"){
        setDollars(getDollars() + amount);
        }
    else if(currency == "euro"){
        setEuros(getEuros() + amount);
        }
    else if(currency == "tenge"){
        setTenges(getTenges() + amount);
        }
    else
        std::cout << "Type your currency again\n";
    updateBalance();
    std::cout << "Deposited!\n";
}

void Account::withdraw(const std::string& currency, double amount) {
    if(currency == "dollar"){
        if(getDollars() == 0.0)
            std::cout << "You do not have that currency in your account!\n";
        else if(getDollars() - amount < 0)
            std::cout << "Insufficient funds!\n";
        else{
            setDollars(getDollars() - amount);
            std::cout << "Withdrawn!\n";
        }
    }
    else if(currency == "euro") {
        if (getEuros() == 0.0)
            std::cout << "You do not have that currency in your account!\n";
        if (getEuros() - amount < 0)
            std::cout << "You cannot withdraw that amount!\n";
        else {
            setEuros(getEuros() - amount);
            std::cout << "Withdrawn!\n";
        }
    }
    else if(currency == "tenge"){
        if(getTenges() == 0.0)
            std::cout << "You do not have that currency in your account!\n";
        if(getTenges() - amount < 0)
            std::cout << "You cannot withdraw that amount!\n";
        else{
            setTenges(getTenges() - amount);
            std::cout << "Withdrawn!\n";
        }
    }
    updateBalance();
}
