#pragma once

#include <string>

namespace Constants {
    enum : int {
        DAYS_IN_WEEK = 5,
        LECTURES_IN_DAY = 7,
    };
};

namespace Files {
    static const std::string REQUESTS_FILE = "persist/requests.txt";
    static const std::string INFO_BANK_FILE = "persist/info_bank.txt";
}

namespace Field {
    enum : int {
        LECTURE_NUMBER, WEEK_DAY, ROOM, // ln, wd, room
    };
};

namespace Relation {
    enum : int {
        MORE, MORE_EQUAL, LESS, LESS_EQUAL, EQUAL,
    };
};

namespace Logic {
    enum : int {
        AND, OR, IMPLICATION, NOT,
    };
};
