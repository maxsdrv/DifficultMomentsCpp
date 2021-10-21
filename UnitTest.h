#ifndef DIFFICULTMOMENTSCPP_UNITTEST_H
#define DIFFICULTMOMENTSCPP_UNITTEST_H

#include <iostream>
#include <cassert>


class UnitTest {
public:
    template <typename TestFunc>
    void RunTest(TestFunc func, const std::string& hint) {
       try {
            func();
            std::cerr << hint << " OK" << std::endl;
       }
       catch (std::runtime_error& error) {
            ++fail_count;
            std::cerr << hint << " fail: " << error.what() << std::endl;
       }
   }
   ~UnitTest() {
        if (fail_count > 0) {
            std::cerr << fail_count << " unit tests failed. Terminate";
            exit(1);
        }
   }

private:
    int fail_count = 0;
};

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}" << std::endl;
}

template <typename Vector>
std::ostream& operator<<(std::ostream& os, const std::vector<Vector>& v) {
    os << "[";
    bool first = true;
    for (const auto& i : v) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << i << " ";
    }
    return os << "]" << std::endl;
}




#endif //DIFFICULTMOMENTSCPP_UNITTEST_H
