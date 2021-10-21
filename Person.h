#ifndef DIFFICULTMOMENTSCPP_PERSON_H
#define DIFFICULTMOMENTSCPP_PERSON_H

#include <iostream>
#include <utility>
#include <vector>
#include <tuple>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <map>

class Person {
public:
    Person(std::string name, std::string lastname, std::string patronymic = "");
    friend std::ostream &operator<<(std::ostream &os, const Person &person);
    /*Getters and Setters*/
    [[nodiscard]] const std::string& getName() const;
    [[nodiscard]] const std::string& getLastName() const;
    [[nodiscard]] std::optional<std::string> getPatronymic() const;
private:
    std::string m_Name;
    std::string m_Lastname;
    std::optional<std::string> m_Patronymic;
};


#endif //DIFFICULTMOMENTSCPP_PERSON_H
