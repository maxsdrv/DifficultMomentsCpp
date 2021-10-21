#ifndef DIFFICULTMOMENTSCPP_PHONENUMBER_H
#define DIFFICULTMOMENTSCPP_PHONENUMBER_H

#include <iostream>
#include <utility>
#include <vector>
#include <tuple>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <map>
#include "gtest/gtest.h"

class PhoneNumber {
public:
    PhoneNumber(int countryCode, int towCode, std::string number, std::optional<int> addNumber = 0);

    /*Getters and Setters*/
    [[nodiscard]] virtual int getCountryCode() const;
    [[nodiscard]] virtual int getTownCode() const;
    [[nodiscard]] virtual const std::string& getNumber() const;
    [[nodiscard]] virtual std::optional<int> getAddNumber() const;
    virtual void setCountryCode(int code);
    virtual void setTownCode(int code);
    virtual void setNumber(std::string number);

    friend std::ostream& operator<<(std::ostream& os, const PhoneNumber& pN);
private:
    int m_countryCode;
    int m_townCode;
    std::string m_Number;
    std::optional<int> m_addNumber;
};


#endif //DIFFICULTMOMENTSCPP_PHONENUMBER_H
