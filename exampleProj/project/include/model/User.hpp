#include<string>

class User {
public:
    User(std::string name, std::string login, int account, int balance);

    std::string get_name() const;
    std::string get_login() const;
    int get_account() const;
    int get_balance() const;

private:
    std::string name;
    std::string login;
    int account;
    int balance;
};
