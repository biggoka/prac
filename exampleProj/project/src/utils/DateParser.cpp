#include "DateParser.hpp"
#include <vector>
#include <stdexcept>
#include "Date.hpp"
#include "Splitter.hpp"

Date DateParser::parse(const std::string & str) {
    Splitter splitter(':');
    std::vector<std::string> splitted = splitter.split(str);
    if (splitted.size() != 3) {
        throw std::invalid_argument("Date parsing error: wrong number of positions");
    }
    size_t idx;
    int d = std::stoi(splitted[0], &idx);
    if (splitted[0].length() != idx) {
        throw std::invalid_argument("Date parsing error: not only digits");
    }
    int m = std::stoi(splitted[1], &idx);
    if (splitted[1].length() != idx) {
        throw std::invalid_argument("Date parsing error: not only digits");
    }
    int y = std::stoi(splitted[2], &idx);
        if (splitted[2].length() != idx) {
        throw std::invalid_argument("Date parsing error: not only digits");
    }

    return Date(d, m, y);
}