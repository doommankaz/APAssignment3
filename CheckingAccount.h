#ifndef AP3_CHECKINGACCOUNT_H
#define AP3_CHECKINGACCOUNT_H

#include <string>
#include "Account.h"

class CheckingAccount : public Account{
public:
    CheckingAccount();

    explicit CheckingAccount(const std::string &name);

    void showBalance() const override;

    void withdraw(const std::string& currency, double amount) override;

    void deposit(const std::string& currency, double amount) override;

protected:
    const std::string &getName() const override;

    double getBalance() const override;

    double getDollars() const override;

    double getEuros() const override;

    double getTenges() const override;

    double getTengeUsd() const override;

    double getEuroUsd() const override;

    void setBalance(double balance) override;

    void setDollars(double dollars) override;

    void setEuros(double euros) override;

    void setTenges(double tenges) override;

    double getFee() const;

private:
    std::string name;
    double balance;
    double dollars;
    double euros;
    double tenges;
    double tengeUsd;
    double euroUsd;
    void updateBalance() override;
    double fee;
};


#endif //AP3_CHECKINGACCOUNT_H
