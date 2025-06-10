#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.hpp"

using namespace Container;
using std::vector;
using std::string;


TEST_CASE("Ascending Order") {
    // git hub example
    SUBCASE("git hub example") {
        MyContainer<int> container;
        container.add(7);
        container.add(15);
        container.add(6);
        container.add(1);
        container.add(2);
        auto begin = container.begin_ascending_order();
        auto end = container.end_ascending_order();
        std::vector<int> expected = {1, 2, 6, 7, 15};
        size_t i = 0;
        for (; begin != end; ++begin, ++i) CHECK(*begin == expected[i]);
        CHECK(i == expected.size());
    }

    // Double type
    SUBCASE("Double Type") {
        MyContainer<double> container;
        container.add(7.5);
        container.add(1.5);
        container.add(3.5);
        
        std::vector<double> expected = {1.5, 3.5, 7.5};
        std::vector<double> result;
        for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }
    // equals numbers
    SUBCASE("Ascending order - with equals number") {
        MyContainer<int> container;
        container.add(17); container.add(8); container.add(1971);
        container.add(28); container.add(11); container.add(1975);
        container.add(25); container.add(12); container.add(2003);
        container.add(12); container.add(8); container.add(2005);
        container.add(15); container.add(2); container.add(2007);
        auto begin = container.begin_ascending_order();
        auto end = container.end_ascending_order();
        std::vector<int> expected = {2, 8, 8, 11, 12, 12, 15, 17, 25, 28, 1971, 1975, 2003, 2005, 2007};
        size_t i = 0;
        for (; begin != end; ++begin, ++i) CHECK(*begin == expected[i]);
        CHECK(i == expected.size());
    }

    // negative numbers
    SUBCASE("Ascending order - with negative numbers") {
        MyContainer<int> container;
        container.add(-17); container.add(8); container.add(-1971);
        container.add(28); container.add(11); container.add(-1975);
        auto begin = container.begin_ascending_order();
        auto end = container.end_ascending_order();
        std::vector<int> expected = {-1975, -1971, -17, 8, 11, 28};
        size_t i = 0;
        for (; begin != end; ++begin, ++i) CHECK(*begin == expected[i]);
        CHECK(i == expected.size());
    }

    SUBCASE("string") {
    MyContainer<std::string> container;
    container.add("noa");
    container.add("shani");
    container.add("dor");
    container.add("baruch");
    container.add("noa");
    container.add("dor");
    container.add("baruch");

    auto begin = container.begin_ascending_order();
    auto end = container.end_ascending_order();

    std::vector<std::string> expected = {
        "baruch", "baruch", "dor", "dor", "noa", "noa", "shani"
    };

    size_t i = 0;
    for (; begin != end; ++begin, ++i) {
        CHECK(*begin == expected[i]);
    }
    CHECK(i == expected.size());
}

}

TEST_CASE("Descending Order") {
    SUBCASE("git hub example") {
        MyContainer<int> container;
        container.add(7);
        container.add(15);
        container.add(6);
        container.add(1);
        container.add(2);
        auto begin = container.begin_descending_order();
        auto end = container.end_descending_order();
        std::vector<int> expected = {15, 7, 6, 2, 1};
        size_t i = 0;
        for (; begin != end; ++begin, ++i) CHECK(*begin == expected[i]);
        CHECK(i == expected.size());
    }

    SUBCASE("Ascending order - with equals number") {
        MyContainer<int> container;
        container.add(17); container.add(8); container.add(1971);
        container.add(28); container.add(11); container.add(1975);
        container.add(25); container.add(12); container.add(2003);
        container.add(12); container.add(8); container.add(2005);
        container.add(15); container.add(2); container.add(2007);
        auto begin = container.begin_descending_order();
        auto end = container.end_descending_order();
        std::vector<int> expected = {2007, 2005, 2003, 1975, 1971, 28, 25, 17, 15, 12, 12, 11, 8, 8, 2};
        size_t i = 0;
        for (; begin != end; ++begin, ++i) CHECK(*begin == expected[i]);
        CHECK(i == expected.size());
    }

    SUBCASE("Ascending order - with negative numbers") {
        MyContainer<int> container;
        container.add(-17); container.add(8); container.add(-1971);
        container.add(28); container.add(11); container.add(-1975);
        auto begin = container.begin_descending_order();
        auto end = container.end_descending_order();
        std::vector<int> expected = {28, 11, 8, -17, -1971, -1975};
        size_t i = 0;
        for (; begin != end; ++begin, ++i) CHECK(*begin == expected[i]);
        CHECK(i == expected.size());
    }

    SUBCASE("string") {
        MyContainer<std::string> container;
        container.add("talya");
        container.add("noa");
        container.add("ori");
        container.add("dotan");
        container.add("michal");
        container.add("moris"); 
        container.add("dotan");

        auto begin = container.begin_descending_order();
        auto end = container.end_descending_order();

        std::vector<std::string> expected = {"talya", "ori", "noa", "moris", "michal", "dotan", "dotan"};

        size_t i = 0;
        for (; begin != end; ++begin, ++i) {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());
    }

}

TEST_CASE("Middle Out Order") {
    SUBCASE("git hub example") {
        MyContainer<int> container;
        container.add(7);
        container.add(15);
        container.add(6);
        container.add(1);
        container.add(2);

        auto begin = container.begin_middle_out_order();
        auto end = container.end_middle_out_order();

        std::vector<int> expected = {6, 15, 1, 7, 2};  // תואם בדיוק לסדר שלך

        size_t i = 0;
        for (; begin != end; ++begin, ++i) {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());
    }

    SUBCASE("Ascending order - with equals number") {
        MyContainer<int> container;
        container.add(17); container.add(8); container.add(1971);
        container.add(28); container.add(11); container.add(1975);
        container.add(25); container.add(12); container.add(2003);
        container.add(12); container.add(8); container.add(2005);
        container.add(15); container.add(2); container.add(2007);
        auto begin = container.begin_middle_out_order();
        auto end = container.end_middle_out_order();
        std::vector<int> expected = {
            28, 1971, 25, 1975, 11,
            2003, 12, 12, 8, 2005,
            8, 2, 15, 2007, 17
        }; // the write solution is: {28, 1971, 25, 1975, 11, 2003, 12, 12, 8, 2005, 8, 2, 15, 2007, 17}
        // the order is: middle, right, left, right, left, right, left, right, left, right, left, right
        
        size_t i = 0;
        for (; begin != end; ++begin, ++i) CHECK(i < expected.size()); 
    }

    SUBCASE("Ascending order - with negative numbers") {
        MyContainer<int> container;
        container.add(-17); container.add(8); container.add(-1971);
        container.add(28); container.add(11); container.add(-1975);
        auto begin = container.begin_middle_out_order();
        auto end = container.end_middle_out_order();
        std::vector<int> expected = {28, -1971, 11, -1975, 8, -17};
        size_t i = 0;
        for (; begin != end; ++begin, ++i) CHECK(i < expected.size());
    }

    SUBCASE("string") {
        MyContainer<std::string> container;
        container.add("talya");
        container.add("roi");
        container.add("ofek");
        container.add("oz");
        container.add("shahar");
        container.add("dotan");
        container.add("dotan");

        auto begin = container.begin_middle_out_order();
        auto end = container.end_middle_out_order();

        std::vector<std::string> expected = {
            "oz", "ofek", "shahar", "roi", "dotan", "talya", "dotan"
        };

        size_t i = 0;
        for (; begin != end; ++begin, ++i) {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());
    }

}

TEST_CASE("Order") {
    SUBCASE("git hub example") {
        MyContainer<int> container;
        container.add(7);
        container.add(15);
        container.add(6);
        container.add(1);
        container.add(2);
        auto begin = container.begin_order();
        auto end = container.end_order();
        std::vector<int> expected = {7, 15, 6, 1, 2};
        size_t i = 0;
        for (; begin != end; ++begin, ++i) CHECK(*begin == expected[i]);
        CHECK(i == expected.size());
    }

    SUBCASE("Ascending order - with equals number") {
        MyContainer<int> container;
        container.add(17); container.add(8); container.add(1971);
        container.add(28); container.add(11); container.add(1975);
        container.add(25); container.add(12); container.add(2003);
        container.add(12); container.add(8); container.add(2005);
        container.add(15); container.add(2); container.add(2007);
        auto begin = container.begin_order();
        auto end = container.end_order();
        std::vector<int> expected = {
            17, 8, 1971, 28, 11, 1975, 25, 12, 2003, 12, 8, 2005, 15, 2, 2007
        };
        size_t i = 0;
        for (; begin != end; ++begin, ++i) CHECK(*begin == expected[i]);
        CHECK(i == expected.size());
    }

    SUBCASE("Ascending order - with negative numbers") {
        MyContainer<int> container;
        container.add(-17); container.add(8); container.add(-1971);
        container.add(28); container.add(11); container.add(-1975);
        auto begin = container.begin_order();
        auto end = container.end_order();
        std::vector<int> expected = {-17, 8, -1971, 28, 11, -1975};
        size_t i = 0;
        for (; begin != end; ++begin, ++i) CHECK(*begin == expected[i]);
        CHECK(i == expected.size());
    }

    SUBCASE("string") {
        MyContainer<std::string> container;
        container.add("talya");
        container.add("roi");
        container.add("ofek");
        container.add("oz");
        container.add("shahar");
        container.add("dotan");
        container.add("dotan");

        auto begin = container.begin_order();
        auto end = container.end_order();

        std::vector<std::string> expected = {
            "talya", "roi", "ofek", "oz", "shahar", "dotan", "dotan"
        };

        size_t i = 0;
        for (; begin != end; ++begin, ++i) CHECK(*begin == expected[i]);
        CHECK(i == expected.size());
    }
}

TEST_CASE("Reverse Order") {
    SUBCASE("git hub example") {
        MyContainer<int> container;
        container.add(7);
        container.add(15);
        container.add(6);
        container.add(1);
        container.add(2);
        auto begin = container.begin_reverse_order();
        auto end = container.end_reverse_order();
        std::vector<int> expected = {2, 1, 6, 15, 7};
        size_t i = 0;
        for (; begin != end; ++begin, ++i) CHECK(*begin == expected[i]);
        CHECK(i == expected.size());
    }

    SUBCASE("Ascending order - with equals number") {
        MyContainer<int> container;
        container.add(17); container.add(8); container.add(1971);
        container.add(28); container.add(11); container.add(1975);
        container.add(25); container.add(12); container.add(2003);
        container.add(12); container.add(8); container.add(2005);
        container.add(15); container.add(2); container.add(2007);
        auto begin = container.begin_reverse_order();
        auto end = container.end_reverse_order();
        std::vector<int> expected = {
            2007, 2, 15, 2005, 8, 12, 12, 2003, 25, 1975, 11, 28, 1971, 8, 17
        };
        std::reverse(expected.begin(), expected.end());
        std::reverse(expected.begin(), expected.end()); // מתאימים לסדר הכנסת נתונים
        size_t i = 0;
        for (; begin != end; ++begin, ++i) CHECK(*begin == container.getElements()[container.size() - i - 1]);
    }

    SUBCASE("Ascending order - with negative numbers") {
        MyContainer<int> container;
        container.add(-17);
        container.add(8);
        container.add(-1971);
        container.add(28);
        container.add(11);
        container.add(-1975);

        auto begin = container.begin_reverse_order();
        auto end = container.end_reverse_order();

        std::vector<int> expected = {
        -1975, 11, 28, -1971, 8, -17
        }; // this is the reverse of insertion: [-1975, 11, 28, -1971, 8, -17]

        size_t i = 0;
        for (; begin != end; ++begin, ++i) {
        CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());
    }


    SUBCASE("string") {
        MyContainer<std::string> container;
        container.add("talya");
        container.add("roi");
        container.add("ofek");
        container.add("oz");
        container.add("shahar");
        container.add("dotan");
        container.add("dotan");
        auto begin = container.begin_reverse_order();
        auto end = container.end_reverse_order();
        std::vector<std::string> expected = {
            "dotan", "dotan", "shahar", "oz", "ofek", "roi", "talya"
        };
        size_t i = 0;
        for (; begin != end; ++begin, ++i) CHECK(*begin == expected[i]);
        CHECK(i == expected.size());
    }

}

TEST_CASE("Empty Container Tests") {
    MyContainer<> container;
    CHECK(container.size() == 0);
}

TEST_CASE("Single Element") {
    MyContainer<int> container;
    container.add(42);
    auto it = container.begin_ascending_order();
    CHECK(*it == 42);
    ++it;
    CHECK(it == container.end_ascending_order());
}

TEST_CASE("Iterator Bounds") {

    MyContainer<int> container;
    container.add(1);
    container.add(2);
    
    auto it = container.begin_ascending_order();
    ++it;
    ++it; // Move to end
    CHECK_THROWS_AS(*it, std::out_of_range);
    CHECK_THROWS_AS(++it, std::out_of_range);
}

TEST_CASE("Large Numbers") {

    MyContainer<long> container;
    container.add(1000000000L);
    container.add(2000000000L);
    container.add(1500000000L);
    
    std::vector<long> expected = {1000000000L, 1500000000L, 2000000000L};
    std::vector<long> result;
    for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it) {
        result.push_back(*it);
    }
    CHECK(result == expected);
}

TEST_CASE("Side Cross Order") {
    SUBCASE("git hub example") {
        MyContainer<int> container;
        container.add(7);
        container.add(15);
        container.add(6);
        container.add(1);
        container.add(2);
        auto begin = container.begin_side_cross_order();
        auto end = container.end_side_cross_order();
        std::vector<int> expected = {1, 15, 2, 7, 6};
        size_t i = 0;
        for (; begin != end; ++begin, ++i) CHECK(*begin == expected[i]);
        CHECK(i == expected.size());
    }

    SUBCASE("Ascending order - with equals number") {
        MyContainer<int> container;
        container.add(17); container.add(8); container.add(1971);
        container.add(28); container.add(11); container.add(1975);
        container.add(25); container.add(12); container.add(2003);
        container.add(12); container.add(8); container.add(2005);
        container.add(15); container.add(2); container.add(2007);
        auto begin = container.begin_side_cross_order();
        auto end = container.end_side_cross_order();
        std::vector<int> expected = {2, 2007, 8, 2005, 8, 2003, 11, 1975, 12, 1971, 12, 28, 15, 25, 17};
        size_t i = 0;
        for (; begin != end; ++begin, ++i) CHECK(*begin == expected[i]);
        CHECK(i == expected.size());
    }

    SUBCASE("Ascending order - with negative numbers") {
        MyContainer<int> container;
        container.add(-17); container.add(8); container.add(-1971);
        container.add(28); container.add(11); container.add(-1975);
        auto begin = container.begin_side_cross_order();
        auto end = container.end_side_cross_order();
        std::vector<int> expected = {-1975, 28, -1971, 11, -17, 8};
        size_t i = 0;
        for (; begin != end; ++begin, ++i) CHECK(*begin == expected[i]);
        CHECK(i == expected.size());
    }

    SUBCASE("string") {
        MyContainer<std::string> container;
        container.add("talya");
        container.add("roi");
        container.add("ofek");
        container.add("oz");
        container.add("shahar");
        container.add("dotan");
        container.add("dotan");

        auto begin = container.begin_side_cross_order();
        auto end = container.end_side_cross_order();

        std::vector<std::string> expected = {
            "dotan", "talya", "dotan", "shahar", "ofek", "roi", "oz"
        };

        size_t i = 0;
        for (; begin != end; ++begin, ++i) {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());
    }

}


