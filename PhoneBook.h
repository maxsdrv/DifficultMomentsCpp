#ifndef DIFFICULTMOMENTSCPP_PHONEBOOK_H
#define DIFFICULTMOMENTSCPP_PHONEBOOK_H

#include <iostream>
#include <utility>
#include <vector>
#include <tuple>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <map>
#include "Person.h"
#include "PhoneNumber.h"


class PhoneBook {
public:
    explicit PhoneBook(std::ifstream& path);
    friend std::ostream& operator<<(std::ostream& os, const PhoneBook& pB);

    void sortByName();
    void sortByPhone();
    std::tuple<std::string, PhoneNumber> getPhoneNumber(const std::string& _lastName);
    void changePhoneNumber(const Person& person, const PhoneNumber& pN);
private:

    std::vector<std::pair<Person, PhoneNumber>> m_addressBook;
};


#endif //DIFFICULTMOMENTSCPP_PHONEBOOK_H
