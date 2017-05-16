#include "Splitter.hpp"

//#include <vector>

std::vector<std::string> Splitter::split(const std::string &str, const char &splt) {
    std::vector<std::string> vec;

    size_t pos = 0;
    size_t find;
    while ( (find = str.find(splt, pos)) != std::string::npos) {
        vec.push_back(str.substr(pos, find - pos));
        pos = find + 1;
    }

    if (str.length() == 0) {
        return vec;
    }
    
    vec.push_back(str.substr(pos));


    return vec;
};