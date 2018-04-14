#include "user.h"

int User::num = 1;
User::User(string name){
    std::cout << "\t\t\t\t\tUser Class constructed" << std::endl;
    this->name = name;
    this->id = User::num++;
    accu = Account(0, id);
}

User::~User(){
    std::cout <<"\t\t\t\t\tUser class destructed" << std::endl;
}

string User::get_username(){
    return name;
}

int User::get_id(){
    return id;
}

Account& User::get_account(){
    return accu;
}

void User::show_transaction_log(){
    trans = accu.get_trans();
    std::cout << "\nID#" << id << " Name: " << name << std::endl;

    for(auto tr : trans){
        tr.print();
    }

    std::cout << "Balance: " << get_account().get_amount() << std::endl << std::endl;
}
