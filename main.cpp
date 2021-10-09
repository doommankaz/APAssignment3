#include <iostream>
#include <vector>
#include "Account.cpp"
#include "SavingsAccount.cpp"
#include "TrustAccount.cpp"
#include "CheckingAccount.cpp"
#include "I_Printable.cpp"
#include "Redistribution.cpp"


int main() {
    SavingsAccount s("My Savings Account");
    s.deposit("dollar", 20);
    std::cout << s;
    s.deposit("dollar", 20000);
    s.withdraw("dollar", 15000);
    std::cout << s;

    TrustAccount t("My Trust Account");
    t.deposit("tenge", 70000);
    t.withdraw("tenge", 15000);
    t.withdraw("tenge", 1000);
    std::cout << t;

    CheckingAccount c("My Checking Account");
    c.deposit("euro", 5000);
    c.withdraw("euro", 2000);
    std::cout << c;
    Account* accounts[3] = {&s, &t, &c};
    Redistribution r;
    r.redistribute(15000, accounts);
    //std::vector<Account> accounts = {t};
    return 0;
}
