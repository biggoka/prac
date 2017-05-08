#pragma once

#include <vector>
#include <string>

class Splitter {
public:
    static std::vector<const std::string> split(const std::string &str, const char &splt);
};