#include "account.h"

Account::Account(){
    return ;
}

Account::Account(int amount, int id){
    std::cout<<"\t\t\t\t\tAccount class constructed"<<std::endl;
    this->id = id;
    this-> amount = amount;
}

Account::~Account(){
    std::cout << "\t\t\t\t\tAccount class destructed" << std::endl;
}

int Account::get_amount(){
    return amount;
}

int Account::get_id(){
    return id;
}

bool Account::withdraw(int money){
    if(amount - money < 0){
        trans.push_back(Transaction(*this, "Withdraw failed"));
        trans[trans.size()-1].set_amonut(money);
        return false;
    }
    amount -= money;
    trans.push_back(Transaction(*this, "Withdraw"));
    trans[trans.size()-1].set_amonut(money);
    return true;
}

bool Account::deposit(int money){
    if(money <= 0) return false;
    amount += money;
    trans.push_back(Transaction(*this, "Deposit"));

    trans[trans.size()-1].set_amonut(money);
    return true;
}

void Account::transer_to_me(Account &b, int money){
    amount += money;
    trans.push_back(Transaction(*this, "transfer to me", b));
    trans[trans.size()-1].set_amonut(money);
}

bool Account::transfer_money(Account &b, int money){
    if(amount - money < 0){
        trans.push_back(Transaction(*this, "Transfer to other failed"));
        trans[trans.size()-1].set_amonut(money);
        return false;
    }

    amount -= money;
    b.transer_to_me(*this, money);
    trans.push_back(Transaction(*this, "Transfer to", b));
    trans[trans.size()-1].set_amonut(money);
    return true;
}

std::vector<Transaction> Account::get_trans(){
    return trans;
}