#include "stdfax.h"



int main() {

std::string filename = "addressBook.txt";
    std::ifstream path(filename, std::ios::binary);
    PhoneBook book(path);
    std::cout << book;

    std::cout << "--------Sort by Name---------" << std::endl;

    book.sortByName();
    std::cout << book;

    std::cout << "--------Sort by Phone---------" << std::endl;

    book.sortByPhone();
    std::cout << book;

    std::cout << "--------GetPhoneNumber---------" << std::endl;

    auto print_phone_number = [&book](const std::string& surname) {
        std::cout << surname << "\t";
        auto answer = book.getPhoneNumber(surname);
        if (std::get<0>(answer).empty()) {
            std::cout << std::get<1>(answer);
        }
        else {
            std::cout << std::get<0>(answer);
            std::cout << std::endl;
        }
    };
    print_phone_number("Ivanov");
    print_phone_number("Petrov");

    std::cout << "--------ChangePhoneNumber-------" << std::endl;
    book.changePhoneNumber(Person {"Vasilii", "Kotov", "Eliseevich"},
                           PhoneNumber{7, 123, "15344458", std::nullopt});
    book.changePhoneNumber(Person{"Mironova", "Margarita", "Vladimirovna"},
                           PhoneNumber{16, 465, "9155448", 13});
    std::cout << book;


    return 0;
}









































