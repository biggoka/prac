#include <iostream>
#include <sstream>
#include <string>

void bad_input() {
    throw "bad input";
}

int main() {

    std::string str = "   10 m 1  ma tan kaledin 1 (ln > 1) | ln > 3  ";

    std::stringstream stream(str);

    int group_id;
    std::string subject;
    std::string professor;
    int count;
    std::string logic_expression;

    stream >> group_id;
    stream >> subject;
    stream >> professor;
    stream >> count;

    if (stream.eof() or group_id == 0 or count == 0) {
        bad_input();
    }

    std::getline(stream, logic_expression);

    std::cout << group_id << std::endl;
    std::cout << subject << std::endl;
    std::cout << professor << std::endl;
    std::cout << count << std::endl;
    std::cout << logic_expression << std::endl;
}