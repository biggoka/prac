#include <fstream>
#include <vector>
#include <string>

enum {ACCOUNT_OFFSET = 1001};

std::vector<std::string> get_names() {
    std::vector<std::string> res;
    res.push_back("Jack");
    res.push_back("Jim");
    res.push_back("Den");
    res.push_back("Alexander");
    res.push_back("Brian");
    res.push_back("Felix");
    res.push_back("Eric");
    res.push_back("Kevin");
    res.push_back("Mark");
    res.push_back("Patrick");
    res.push_back("Richard");
    res.push_back("Sam");
    res.push_back("Ted");
    res.push_back("Steve");
    res.push_back("William");

    res.push_back("Alice");
    res.push_back("Anna");
    res.push_back("Catherine");
    res.push_back("Christine");
    res.push_back("Dana");
    res.push_back("Emily");
    res.push_back("Fiona");
    res.push_back("Jenna");
    res.push_back("Laura");
    res.push_back("Lydia");
    res.push_back("Mary");
    res.push_back("Rebecca");
    res.push_back("Stephanie");
    res.push_back("Veronica");
    res.push_back("Wendy");
    return res;
}

struct FromTo {
    FromTo(int num_users) {
        do {
            from = rand() % num_users;
            to = rand() % num_users;
        } while (from == to);
    }
    int from;
    int to;
};

void gen_transactions(int num_users, int num_transactions) {
    std::ofstream out("transactions.txt");
    std::vector<std::string> names = get_names();
    int names_len = names.size();
    for (int i = 0; i < num_transactions; i++) {
        out << rand() % 28 + 1 << ":" << rand() % 12 + 1 << ":" << rand() % 2 + 2015 << "|";
        FromTo from_to(num_users);
        out << from_to.from + ACCOUNT_OFFSET << "|" << from_to.to + ACCOUNT_OFFSET << "|";
        out << (rand() % 100 + 1) * 10 << "|";
        int comment = rand() % 6;
        if (comment == 1) {
            out << "Hi :)";
        }
        if (comment == 2) {
            out << "Your money";
        }
        if (comment == 3) {
            out << "For " << names[rand() % names_len] << " birthday";
        }
        out << std::endl;
    }

    out.close();
}



void gen_users(int num_users) {
    std::ofstream out("users.txt");
    std::vector<std::string> names = get_names();
    int names_len = names.size();
    for (int i = 0; i < num_users; i++) {
        out << names[rand() % names_len] << ",";
        out << "user" << i << ",";
        out << (ACCOUNT_OFFSET + i) << ",";
        out << rand() % 10000;
        out << std::endl;
    }
    out.close();
}

int main() {
    gen_users(10);
    gen_transactions(10, 1000);
}