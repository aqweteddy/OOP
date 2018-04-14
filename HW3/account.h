#include <string>
#include <iostream>
#include <vector>

#ifndef A_H
#define A_H

#include "transaction.h"

class Account{
public:
    Account();
    Account(int, int);
    ~Account();
    bool withdraw(int);
    bool deposit(int);
    bool transfer_money(Account&, int);
    int get_amount();
    int get_id();
    std::vector<Transaction> get_trans();
    
    

private:
    int id;
    int amount;
    std::vector<Transaction> trans;

    void transer_to_me(Account&, int);
};
#endif