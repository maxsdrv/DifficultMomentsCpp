#include "PhoneBook.h"



std::tuple<std::string, std::string> divideString(const std::string& s) {
    std::string::size_type posPlus = s.find('+');
    std::string strPerson;
    std::string strPhone;
    strPerson = s.substr(0, posPlus);
    strPhone = s.substr(posPlus + 1, std::string::npos);
    if (strPerson.empty() || strPhone.empty()) {
        return std::make_tuple(" ", " ");
    }
    else {
        return std::make_tuple((strPerson), std::move(strPhone));
    }
}

std::tuple<std::string, std::string, std::string> getEntirePerson(std::string& s) {
    std::string::size_type pos = s.find(' ');
    std::string nameWord, surWord, patrWord;
    surWord = s.substr(0, pos);
    s = s.substr(pos + 1, std::string::npos);
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] != ' ') {
            nameWord += s[i];
            pos = i;
        }
        else {
            break;
        }
    }
    s = s.substr(pos + 1, std::string::npos);
    s.erase(std::remove_if(s.begin(), s.end(), isspace), s.end());
    patrWord = s;

    return std::make_tuple(std::move(nameWord), std::move(surWord), std::move(patrWord));
}

std::tuple<int, int, std::string, int> getEntirePhoneNumber(std::string& s) {
    std::string number;
    int country_code = 0, town_code = 0, additional = 0;
    if (s.empty()) {
        number = "";
        std::cout << "String is empty" << std::endl;
        return std::make_tuple(country_code, town_code, std::move(number), additional);
    }
    std::string::size_type pos1 = s.find('(');
    std::string::size_type pos2 = s.find(')');
    std::stringstream ss;
    ss << s.substr(0, pos1);
    ss >> country_code;
    s = s.substr(pos1 + 1, std::string::npos);
    ss.clear();
    ss << s.substr(0, pos2);
    ss >> town_code;
    ss.clear();
    pos2 = s.find(')');
    s = s.substr(pos2 + 1, std::string::npos);
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] != ' ') {
            number += s[i];
            pos1 = i;
        }
        else {
            break;
        }
    }
    s = s.substr(pos1 + 1, std::string::npos);
    if (s.empty() || s == " ") {
        return std::make_tuple(country_code, town_code, std::move(number), additional);
    }
    additional = std::stoi(s);

    return std::make_tuple(country_code, town_code, std::move(number), additional);
}


PhoneBook::PhoneBook(std::ifstream &path) {

    if (path.is_open()) {
        std::cout << "File is open successfully" << std::endl;
    }
    else std::cout << "ERROR::FILE IS NOT OPEN!!!" << std::endl;
    std::string line;
    std::vector<std::string> tokens;

    while (path) {
        std::getline(path, line);
        auto myString = divideString(line);
        std::string names = std::get<0>(myString);
        std::string digits = std::get<1>(myString);
        if (names == " " && digits == " ") return;
        std::string firstName, surName, patronymic, number;
        int country_code = 0, town_code = 0, additional = 0;
        std::tie(firstName, surName, patronymic) = getEntirePerson(names);
        std::tie(country_code, town_code, number, additional) = getEntirePhoneNumber(digits);
        std::pair<Person, PhoneNumber> p ({firstName, surName, patronymic},
                                          {country_code, town_code, number, additional});
        m_addressBook.push_back(p);

    }
}

std::ostream &operator<<(std::ostream &os, const PhoneBook &pB) {
    for (const auto& i : pB.m_addressBook) {
        if (i.second.getAddNumber().value() == 0) {
            std::cout << i.first.getLastName() << " " << i.first.getName() << " " << i.first.getPatronymic().value()
                      << "\t" << "+" << i.second.getCountryCode() << "(" << i.second.getTownCode() << ")" <<
                      i.second.getNumber() << std::endl;
        }
        else {
            std::cout << i.first.getLastName() << " " << i.first.getName() << " " << i.first.getPatronymic().value()
                      << "\t" << "+" << i.second.getCountryCode() << "(" << i.second.getTownCode() << ")" <<
                      i.second.getNumber() << " " << i.second.getAddNumber().value() << std::endl;
        }
    }

    return os;
}

void PhoneBook::sortByName() {
    std::vector<Person> names;
    for (const auto& i : m_addressBook) {
        names.push_back(i.first);
    }
    std::sort(names.begin(), names.end(), [](const Person& lhs, const Person& rhs) {
        int compareResult = (lhs.getLastName().compare(rhs.getLastName()));
        if (compareResult == 0) {
            compareResult = (lhs.getName().compare(rhs.getName()));
        }
        return compareResult < 0;
    });

    for (size_t i = 0; i < m_addressBook.size(); ++ i) {
        m_addressBook[i].first = std::move(names[i]);
    }
    names.clear();
}

void PhoneBook::sortByPhone() {
    std::vector<PhoneNumber> numbers;
    for (const auto& i : m_addressBook) {
        numbers.push_back(i.second);
    }
    std::sort(numbers.begin(), numbers.end(), [](const PhoneNumber& lhs, const PhoneNumber& rhs) {
        bool compareResult = (lhs.getCountryCode() < rhs.getCountryCode());
        if (!compareResult) {
            compareResult = (lhs.getTownCode() < rhs.getTownCode());
        }
        return compareResult;
    });

    for (size_t i = 0; i < m_addressBook.size(); ++i) {
        m_addressBook[i].second = std::move(numbers[i]);
    }
}

std::tuple<std::string, PhoneNumber> PhoneBook::getPhoneNumber(const std::string& _lastName) {
    int count = 0;
    PhoneNumber temp (0, 0, "0", 0);
    std::for_each(m_addressBook.begin(), m_addressBook.end(),
                  [&count, &_lastName, &temp](const std::pair<Person, PhoneNumber>& book) {
        if (book.first.getLastName() == _lastName) {
            ++count;
            temp.setCountryCode(book.second.getCountryCode());
            temp.setTownCode(book.second.getTownCode());
            temp.setNumber(book.second.getNumber());
        }
    });
    if (count == 1) {
        return std::make_tuple("", temp);
    }
    else if (count > 1) {
        return std::make_tuple("found more than 1", temp);
    }
    return std::make_tuple("not found", temp);
}

void PhoneBook::changePhoneNumber(const Person &person, const PhoneNumber &pN) {
    auto result = std::find_if(m_addressBook.begin(), m_addressBook.end(),
                               [&person, &pN](std::pair<Person, PhoneNumber>& book) {

        int flag = (person.getLastName() == book.first.getLastName() && person.getName() == book.first.getName()
                    && person.getPatronymic().value() == book.first.getPatronymic().value());

        if (flag) {
            book.second.setCountryCode(pN.getCountryCode());
            book.second.setTownCode(pN.getTownCode());
            book.second.setNumber(pN.getNumber());
        }
        return flag;
    });
}

