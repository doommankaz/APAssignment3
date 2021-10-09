#include "I_Printable.h"

std::ostream &operator<<(std::ostream &os, const Account &acc) {
    os << "===========================\n";
    os << acc.getName() << "\n";
    os << "Your Balance: " << acc.getBalance() << "$\n" << "Dollar Wallet: " << acc.getDollars() << "$\n"
              << "Euro Wallet: " << acc.getEuros() << "€\n" << "Tenge Wallet: " << acc.getTenges() << "₸\n";
    os << "===========================\n";
    return os;
}
