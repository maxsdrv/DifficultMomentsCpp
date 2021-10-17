#include "FullName.h"

FullName::FullName(std::string fname, std::string lname, std::string patr) : m_firstName(std::move(fname)),
m_lastName(std::move(lname)), m_patronymic(std::move(patr))  {}

std::string FullName::getName() const {
    return m_firstName;
}

std::string FullName::getLname() const {
    return m_lastName;
}

std::string FullName::getPatronymic() const {
    return m_patronymic;
}

bool FullName::operator==(const FullName &lhs) const{
    return (m_firstName == lhs.m_firstName) && (m_lastName == lhs.m_lastName);
}
