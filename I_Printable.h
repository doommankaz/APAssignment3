#ifndef AP3_I_PRINTABLE_H
#define AP3_I_PRINTABLE_H
#include "Account.h"


class I_Printable {
public:
    friend std::ostream& operator << (std::ostream& os, const Account& acc);
};


#endif //AP3_I_PRINTABLE_H
