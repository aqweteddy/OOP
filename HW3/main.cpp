#include <iostream>
#include "user.cpp"

using std::cout;
using std::endl;

int main(int argc, const char *argv[]){
    const int user_name_len = 5;
    std::string user_name[] = {"John", "Mary", "Andy", "Amy", "Tom"}; 

    std::vector<User> user;

    for(int i=0; i<user_name_len; i++){
        user.push_back(User(user_name[i]));
    }

//  test for deposit
    const int first_money[] = {100, 2000, 2000, 300, 500};

    cout << "============TEST DEPOSIT============" << endl;
    for(int i=0; i<user_name_len; i++){
        Account &tmp = user[i].get_account();
        tmp.deposit(first_money[i]);
        cout << "Balance of " << user[i].get_username() << "'s account is " << tmp.get_amount() << endl;   
    }

// test for withdraw
    const int withdraw_money = 200;

    cout << "============TEST WITHDRAW============" <<endl;
    for(int i=0; i<user_name_len; i++){
        Account &tmp = user[i].get_account();
        tmp.withdraw(withdraw_money);
        user[i].show_transaction_log();
      //  cout << "Balance of " << user[i].get_username() << "'s account is " << tmp.get_amount() << endl;   
    }

// test for transfer
//      u[0]->u[1] failed
//      u[1]->u[4] ok
    cout << "============TEST TRANSFER============" <<endl;
    user[0].get_account().transfer_money(user[1].get_account(), 200);
    user[1].get_account().transfer_money(user[4].get_account(), 1000);

    user[0].show_transaction_log();
    user[1].show_transaction_log();
    user[4].show_transaction_log();
    
    return 0;
}
