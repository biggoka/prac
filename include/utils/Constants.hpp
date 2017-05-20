#pragma once

namespace Constants {
    enum : int {
        DAYS_IN_WEEK = 7,
        LECTURES_IN_DAY = 7,
    };
};

namespace Relation {
    enum : int {
        MORE, MORE_EQUAL, LESS, LESS_EQUAL, EQUAL,
    };
};

namespace Logical {
    enum : int {
        AND, OR, IMPLICATION, NOT,
    };
};
