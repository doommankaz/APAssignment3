#include "Redistribution.h"

void Redistribution::redistribute(double tenge, Account **accounts) {
    accounts[0]->deposit("tenge", tenge);
    accounts[1]->deposit("tenge", tenge);
    accounts[2]->deposit("tenge", tenge);
}
