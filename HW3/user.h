#include "transaction.cpp"
#include <vector>
#include <string>
using std::string;


class User{
private:
    static int num;
    string name;
    int id;
    Account accu;
    std::vector<Transaction> trans;
    
public:
    User(string);
    ~User();
    string get_username();
    int get_id();
    Account& get_account();
    void show_transaction_log();
};
