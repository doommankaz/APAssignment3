#ifndef AP3_SAVINGSACCOUNT_H
#define AP3_SAVINGSACCOUNT_H
#include "Account.h"

class SavingsAccount : public Account{
public:
    SavingsAccount();

    explicit SavingsAccount(const std::string &name);

    void deposit(const std::string& currency, double amount) override;

    void withdraw(const std::string& currency, double amount) override;

    void showBalance() const override;

    double getInterestRateUsd() const;

    double getInterestRateEur() const;

    double getInterestRateKzt() const;

    const std::string &getName() const override;

    double getBalance() const override;

    double getDollars() const override;

    double getEuros() const override;

    double getTenges() const override;

    void setBalance(double balance) override;

    void setDollars(double dollars) override;

    void setEuros(double euros) override;

    void setTenges(double tenges) override;

private:
    std::string name;
    double balance;
    double dollars;
    double euros;
    double tenges;
    double interestRateUSD;
    double interestRateEUR;
    double interestRateKZT;
};


#endif //AP3_SAVINGSACCOUNT_H
