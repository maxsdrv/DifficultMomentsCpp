#include <iostream>
#include <array>
#include "PhoneNumber.h"
#include "UnitTest.h"
#include "PhoneBook.h"


#include <gtest/gtest.h>


template<typename T, typename U>
void AssertEqual(const T &t, const U &u, const std::string &hint) {
    if (t != u) {
        std::ostringstream os;
        os << "Assertion failed: " << t << " != " << u << " hint: " << hint;
        throw std::runtime_error(os.str());
    }
}

template<typename T, typename U>
void AssertEqual2(const T &reg, const U &val, const std::string &hint) {
    int length = 0;
    std::array<int, 5> len{};
    int s = val;
//Поразрядно определяем кол-во чисел, если кол-во чисел не соответсвует требованию бросаем исключение.
    while (s % 10 != 0) {
        len[length] = s % 10;
        s /= 10;
        ++length;
    }

    if (length != reg) {
        std::ostringstream os;
        os << "Assertion failed: " << reg << " != ";
        for (const auto& i : len) {
            if (i == 0) {
                continue; // Чтобы не выводить нули
            }
            os << i << " ";
        }
        os << hint;
        throw std::runtime_error(os.str());
    }
}


void TestCountryCode() {
    PhoneNumber pn(2, 929, "");
    AssertEqual(7, pn.getCountryCode(), "Test Country code ");
}

void TestTownCode() {
    PhoneNumber pn(7, 4955, "");
    AssertEqual2(3, pn.getTownCode(), "Test Town code");
}

void TestPhoneNumber() {
    PhoneNumber pn(7, 498, "555334");
    AssertEqual(7, pn.getNumber().size(), "Test Phone Number");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    std::string filename = "../addressBook.txt";
    std::ifstream path(filename, std::ios::binary);
    PhoneBook book(path);
//Tests start:
    UnitTest ut;
    ut.RunTest(TestCountryCode, "Test Country Code");
    ut.RunTest(TestTownCode, "Test Town Code");
    ut.RunTest(TestPhoneNumber, "Test Number Phone");

    return RUN_ALL_TESTS();
}
