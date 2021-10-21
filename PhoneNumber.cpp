#include "PhoneNumber.h"


PhoneNumber::PhoneNumber(int countryCode, int towCode, std::string number, std::optional<int> addNumber) :
        m_countryCode(countryCode), m_townCode(towCode), m_Number(std::move(number)), m_addNumber(addNumber) {}

int PhoneNumber::getCountryCode() const {
    return m_countryCode;
}

int PhoneNumber::getTownCode() const {
    return m_townCode;
}

const std::string &PhoneNumber::getNumber() const {
    return m_Number;
}

std::optional<int> PhoneNumber::getAddNumber() const {
    return m_addNumber.value();
}

std::ostream &operator<<(std::ostream &os, const PhoneNumber &pN) {
    if (pN.m_addNumber.value() == 0) {
        std::cout << "+" << pN.m_countryCode << "(" << pN.m_townCode << ")" << pN.m_Number << '\n';
    }
    else {
        std::cout << "+" << pN.m_countryCode << "(" <<  pN.m_townCode << ")" << pN.m_Number << " "
                  << pN.m_addNumber.value() << '\n';
    }

    return os;
}

void PhoneNumber::setCountryCode(int code) {
    this->m_countryCode = code;
}

void PhoneNumber::setTownCode(int code) {
    this->m_townCode = code;
}

void PhoneNumber::setNumber(std::string number) {
    this->m_Number = std::move(number);
}
