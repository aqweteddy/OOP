#include "transaction.h"
#include "account.cpp"

Transaction :: Transaction(Account &accu, std::string type){
    std::cout<<"\t\t\t\t\tTransaction Class Constructed"<<std::endl;
    this->accu = &accu;
    this->type = type;
    accu_b = NULL;
}

Transaction :: ~Transaction(){
    std::cout << "\t\t\t\t\tTransaction class destructed" << std::endl;
}

Transaction :: Transaction(Account &accu, std::string type, Account &b){
    std::cout<< "\t\t\t\t\tTransaction Class Constructed" << std::endl;
    this->accu = &accu;
    this->accu_b = &b;
    this->type = type;
}

void Transaction::set_amonut(int money){
    amount = money;
}

int Transaction::get_amount(){
    return amount;
}

string Transaction::get_type(){
    return type;
}

Account Transaction::get_account_b(){
    return *accu_b;
}

void Transaction::print(){
    if(type == "transfer to me"){
        std::cout << "#ID:" << accu_b->get_id() << " " << type << " " 
            << amount <<std::endl;
    }
    else if(type == "Transfer to"){
        std::cout << type << " #ID:" << accu_b->get_id() << 
            " " << amount << std::endl;
    } else {
        std::cout << type << " " << amount << std::endl;
    }
}