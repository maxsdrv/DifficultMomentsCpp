#ifndef DIFFICULTMOMENTSCPP_FULLNAME_H
#define DIFFICULTMOMENTSCPP_FULLNAME_H

#include <string>
#include <optional>

class FullName {
public:
    explicit FullName(std::string fname = "", std::string lname = "", std::string patr = "");

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::string getLname() const;
    [[nodiscard]] std::string getPatronymic() const;

    bool operator==(const FullName& lhs)const;
private:
    std::string m_firstName;
    std::string m_lastName;
    std::string m_patronymic;
};


#endif //DIFFICULTMOMENTSCPP_FULLNAME_H
