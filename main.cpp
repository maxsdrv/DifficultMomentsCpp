#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>


class Person {
public:
    Person(std::string name, std::string lastname, std::string patronymic = "") :
            m_Name(std::move(name)), m_Lastname(std::move(lastname)),
            m_Patronymic(std::move(patronymic)) {}

    friend std::ostream &operator<<(std::ostream &os, const Person &person) {
        if (person.m_Patronymic->empty()) {
            std::cout << person.m_Name << " " << person.m_Lastname <<  " Empty" << '\n';
        }
        else {
            std::cout << person.m_Name << " " << person.m_Lastname << " " << person.m_Patronymic.value() << std::endl;
        }

        return os;
    }

private:
    std::string m_Name;
    std::string m_Lastname;
    std::optional<std::string> m_Patronymic;
};

class PhoneNumber {
public:
    PhoneNumber(int countryCode, int towCode, std::string number, int addNumber = 0) :
                m_countryCode(countryCode), m_townCode(towCode), m_Number(std::move(number)), m_addNumber(addNumber) {}

    friend std::ostream& operator<<(std::ostream& os, const PhoneNumber& pN) {
        if (pN.m_addNumber.value() == 0) {
            std::cout << "+" << pN.m_countryCode << "(" << pN.m_townCode << ")" << pN.m_Number << '\n';
        }
        else {
            std::cout << "+" << pN.m_countryCode << "(" <<  pN.m_townCode << ")" << pN.m_Number << " "
            << pN.m_addNumber.value() << '\n';
        }

        return os;
    }
private:
    int m_countryCode;
    int m_townCode;
    std::string m_Number;
    std::optional<int> m_addNumber;
};


int main() {
    std::vector<Person> persons{{"Maxim", "Sidorov", ""},
                                {"Inga",  "Sidorova","Vladimirovna"}};
    for (const auto& i : persons) {
        std::cout << i;
    }
    std::cout << std::endl;

    std::vector<PhoneNumber> phoneNumbers {{7, 929, "6307051"},
                                           {7, 985, "2890901", 12}};
    for (const auto& i : phoneNumbers) {
        std::cout << i;
    }
    std::cout << std::endl;

    return 0;
}
