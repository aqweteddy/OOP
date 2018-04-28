#include <string>
#include <iostream>

#ifndef T_H
#define T_H

class Account;
using std::string;

class Transaction{
public:
    Transaction(Account&, string);
    Transaction(Account&, string, Account&);
    ~Transaction();
    void print();
    void set_amonut(int);
    string get_type();
    int get_amount();
    Account get_account_b();

private:
    string type;
    Account* accu;
    Account* accu_b;
    int amount;
};
#endif