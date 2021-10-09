#include "TrustAccount.h"

TrustAccount::TrustAccount() {
    name = "Unnamed Account";
    balance = 0.0;
    dollars = 0.0;
    euros = 0.0;
    tenges = 0.0;

    //07.10.2021
    tengeUsd = 0.0023;
    euroUsd = 1.16;
}

TrustAccount::TrustAccount(const std::string &name) : TrustAccount() {
    this->name = name;
}

const std::string &TrustAccount::getName() const {
    return name;
}

double TrustAccount::getBalance() const {
    return balance;
}

double TrustAccount::getDollars() const {
    return dollars;
}

double TrustAccount::getEuros() const {
    return euros;
}

double TrustAccount::getTenges() const {
    return tenges;
}

double TrustAccount::getTengeUsd() const {
    return tengeUsd;
}

double TrustAccount::getEuroUsd() const {
    return euroUsd;
}

void TrustAccount::setBalance(double blnc) {
    TrustAccount::balance = blnc;
}

void TrustAccount::setDollars(double usd) {
    TrustAccount::dollars = usd;
}

void TrustAccount::setEuros(double eur) {
    TrustAccount::euros = eur;
}

void TrustAccount::setTenges(double kzt) {
    TrustAccount::tenges = kzt;
}

void TrustAccount::showBalance() const{
    std::cout << "===========================\n";
    std::cout << getName() << "\n";
    std::cout << "Your Balance: " << getBalance() << "$\n" << "Dollar Wallet: " << getDollars() << "$\n"
              << "Euro Wallet: " << getEuros() << "€\n" << "Tenge Wallet: " << getTenges() << "₸\n";
    std::cout << "===========================\n";
}

void TrustAccount::updateBalance(){
    setBalance((getTenges() * getTengeUsd()) + (getEuros() * getEuroUsd()) + getDollars());
}

void TrustAccount::deposit(const std::string &currency, double amount) {
    SavingsAccount::deposit(currency, amount);
    if(currency == "dollar" && amount > 1000.0)
        setDollars(getDollars() + 10);
    else if(currency == "euro" && amount * getEuroUsd() > 1000.0) {
        setEuros(getEuros() + amount * getEuroUsd());
    }
    else if(currency == "tenge" && amount * getTengeUsd() > 1000.0){
        setTenges(getTenges() + amount * getTengeUsd());
    }
    updateBalance();
}

void TrustAccount::withdraw(const std::string &currency, double amount) {
    if(currency == "dollar" && getBalance() * 0.2 < amount){
        std::cout << "The withdraw is aborted, you cannot withdraw 20% of your balance!\n";
        return;
    }
    else if(currency == "euro" && getBalance() * 0.2 < amount * getEuroUsd()){
        std::cout << "The withdraw is aborted, you cannot withdraw 20% of your balance!\n";
        return;
    }
    else if(currency == "tenge" && getBalance() * 0.2 < amount * getTengeUsd()){
        std::cout << "The withdraw is aborted, you cannot withdraw 20% of your balance!\n";
        return;
    }
    SavingsAccount::withdraw(currency, amount);
}


