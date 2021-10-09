#ifndef AP3_ACCOUNT_H
#define AP3_ACCOUNT_H


class Account {
public:
    Account();

    explicit Account(const std::string &name);

    virtual void deposit(const std::string& currency, double amount) = 0;

    virtual void withdraw(const std::string& currency, double amount) = 0;

    virtual double getDollars() const;

    virtual double getEuros() const;

    virtual double getTenges() const;

    virtual void showBalance() const;

    virtual const std::string &getName() const;

    virtual void setBalance(double balance);

    virtual void setDollars(double dollars);

    virtual void setEuros(double euros);

    virtual void setTenges(double tenges);

    virtual double getBalance() const;

private:
    std::string name;
    double balance;
    double dollars;
    double euros;
    double tenges;
    double tengeUsd;
    double euroUsd;

protected:

    virtual void updateBalance();

    virtual double getTengeUsd() const;

    virtual double getEuroUsd() const;
};


#endif //AP3_ACCOUNT_H
