#ifndef AP3_TRUSTACCOUNT_H
#define AP3_TRUSTACCOUNT_H
#include "SavingsAccount.h"

class TrustAccount : public SavingsAccount{
public:
    TrustAccount();

    explicit TrustAccount(const std::string &name);

    void deposit(const std::string& currency, double amount) override;

    void withdraw(const std::string& currency, double amount) override;

    void showBalance() const override;

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

private:
    std::string name;
    double balance;
    double dollars;
    double euros;
    double tenges;
    double tengeUsd;
    double euroUsd;

    void updateBalance() override;
};


#endif //AP3_TRUSTACCOUNT_H
