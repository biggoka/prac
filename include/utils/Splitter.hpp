#pragma once

#include <string>
#include <vector>

class Splitter {
public:
    static std::vector<std::string> split(const std::string &str, const char &splt);
};