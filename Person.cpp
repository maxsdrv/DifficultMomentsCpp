#include "Person.h"

Person::Person(std::string name, std::string lastname, std::string patronymic) :
                      m_Name(std::move(name)), m_Lastname(std::move(lastname)),m_Patronymic(std::move(patronymic)) {}

std::ostream &operator<<(std::ostream &os, const Person &person) {
    if (person.m_Patronymic->empty()) {
        std::cout << person.m_Name << " " << person.m_Lastname <<  " " << '\n';
    }
    else {
        std::cout << person.m_Name << " " << person.m_Lastname << " " << person.m_Patronymic.value() << std::endl;
    }

    return os;
}

const std::string &Person::getName() const {
    return m_Name;
}

const std::string &Person::getLastName() const {
    return m_Lastname;
}

std::optional<std::string> Person::getPatronymic() const {
    return m_Patronymic.value();
}


